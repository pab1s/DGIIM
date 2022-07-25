import numpy as np
import sympy as sp
from decimal import *

mporig = 16

def buscaRaiz(f,a,b,dx): 
    '''
    x1,x2 = buscaraiz(f,a,b,dx)
    buscará dentro del intervalo [a,b] en incrementos de dx una acotación
    de la forma [x1,x2] de la raíz más pequeña de f(x) en dicho intervalo.
    Se devolverá x1 = x2 = None en caso de no encontrarse ninguna.
    '''
    x1 = a; x2 = a + dx
    f1 = f(x1); f2 = f(x2)
    while np.sign(f1) == np.sign(f2):
        if x2 >= b: return None,None   # hemos cambiado x1 por x2
        x1 = x2;  f1 = f2
        x2 = x1 + dx; f2 = f(x2)
    else:
        return x1,x2

def metodoBiseccion(f,a,b,cifras=16,prec=10**(-16),nmax=100,num_iter=False):
    getcontext().prec = cifras+1
    tol = 10**(-cifras)
    niter = 0; sale =''
    sucesionBiseccion = []
    a,b = Decimal(a),Decimal(b)

    for k in range(nmax):
        niter = niter + 1;
        c = a+(b-a)/2 # equivalente a c = (a+b)/2
        sucesionBiseccion.append(c)

        if abs(f(c)) < prec:
            sale = 'precision'
            break
        if np.sign(f(a)) != np.sign(f(c)):
            b = c
        else:
            a = c

        if b-a < tol:
            sale = 'tolerancia'
            break

    if sale == 'precision':
        print('Posiblemente solución exacta: ',c)
    elif niter < nmax:
        print('Aproximación solicitada: ',c)
    else:
        print('Se llegó al número máximo de iteraciones',c)
    if num_iter:
        print('Número de iteraciones reales en metodoBiseccion: ',niter)

    getcontext().prec = mporig
    return sucesionBiseccion

def metodoRegulaFalsi(f,a,b,cifras=16,prec=10**(-16),nmax=100,num_iter=False):
    getcontext().prec = cifras+1
    tol = 10**(-cifras)
    niter = 0; sale =''
    sucesionRegulaFalsi = []
    a,b = Decimal(a),Decimal(b)

    for k in range(nmax):
        niter = niter + 1;
        c = b-((a-b)*f(b))/(f(a)-f(b))
        sucesionRegulaFalsi.append(c)

        if abs(f(c)) < prec:
            sale = 'precision'
            break
        if np.sign(f(a)) != np.sign(f(c)):
            b = c
        else:
            a = c

        if b-a < tol:
            sale = 'tolerancia'
            break

    if sale == 'precision':
        print('Posiblemente solución exacta: ',c)
    elif niter < nmax:
        print('Aproximación solicitada: ',c)
    else:
        print('Se llegó al número máximo de iteraciones',c)
    if num_iter:
        print('Número de iteraciones reales en metodoBiseccion: ',niter)

    getcontext().prec = mporig
    return sucesionRegulaFalsi

def numIterBiseccion(a,b,cifras):
    tol = 10**(-cifras)
    n = np.ceil(np.log((b-a)/tol)/np.log(2) - 1)
    print('Número de iteraciones: ', n)
    return n

def metodoSecante(f,a,b,cifras=16,prec=10**(-16),nmax=100,num_iter=False):
    getcontext().prec = cifras+1
    tol = 10**(-cifras)
    niter = 0; sale =''
    sucesionSecante = []
    x0,x1 = Decimal(a),Decimal(b)

    for k in range(nmax):
        niter = niter + 1;
        c = x1 - (x0-x1)/(f(x0)-f(x1))*f(x1)
        sucesionSecante.append(c)
        if abs(f(c)) < prec:
            sale = 'precision'
            break
        else:
            x1,x0 = c,x1
        if abs(x1-x0) < tol:
            sale = 'tolerancia'
            break

    if sale == 'precision':
        print('Posiblemente solución exacta: ',c)
    elif niter < nmax:
        print('Aproximación solicitada: ',c)
    else:
        print('Se llegó al número máximo de iteraciones: ',c)
    if num_iter:
        print('Número de iteraciones reales en metodoSecante: ',niter)

    getcontext().prec = mporig
    return sucesionSecante

def newtonRaphson(f,df,x0,cifras=16,prec=10**(-16),nmax=100,num_iter=False):
    getcontext().prec = cifras
    tol = 10**(-cifras)
    niter = 0; sale = ''
    sucesionNewtonRaphson = []
    x0 = Decimal(x0)

    for k in range(nmax):
        niter = niter + 1
        x1 = x0 - f(x0)/Decimal(df(x0))
        sucesionNewtonRaphson.append(x1)

        if abs(x1-x0) < tol:
            sale = 'tolerancia'
            break
        if abs(f(x1)) < prec:
            sale = 'precision'
            break
        else:
            x0 = x1

    if sale == 'precision':
        print('Posiblemente solución exacta: ',x1)
    elif niter < nmax:
        print('Aproximación solicitada: ',x1)
    else:
        print('Se llegó al número máximo de iteraciones: ',x1)
    if num_iter:
        print('Número de iteraciones reales en newtonRaphson: ',niter)
        
    return sucesionNewtonRaphson

def metodoWhittaker(f,df, x0,prec=10**(-16),cifras=16,nmax=100):
    tol = 10**(-cifras)
    niter = 0; sale = ''

    for k in range(nmax):
        niter = niter + 1
        x1 = x0 - f(x0)/df(x0)
        if abs(x1-x0) < tol:
            sale = 'tolerancia'
            break
        if abs(f(x1)) < prec:
            sale = 'precision'
            break
        else:
            x0 = x1

    if sale == 'precision':
        print('Posiblemente solución exacta: ',x1)
    elif niter < nmax:
        print('Aproximación solicitada: ',x1)
    else:
        print('Se llegó al número máximo de iteraciones')
    return x1

def metodoSteffensen(f,x0,prec=10**(-16),cifras=16,nmax=100):
    tol = 10**(-cifras)
    niter = 0; sale = ''

    for k in range(nmax):
        niter = niter + 1
        x1 = x0 - f(x0)**2/(f(x0+f(x0))-f(x0))
        if abs(x1-x0) < tol:
            sale = 'tolerancia'
            break
        if abs(f(x1)) < prec:
            sale = 'precision'
            break
        else:
            x0 = x1
    return x1

    if sale == 'precision':
        print('Posiblemente solución exacta: ',x1)
    elif niter < nmax:
        print('Aproximación solicitada: ',x1)
    else:
        print('Se llegó al número máximo de iteraciones')
    return x1

def metodoAcelAitken(aprox):
    '''
    Método de aceleración de convergencia : Aitken
    aprox -> Sucesión de números reales
    Return: Sucesión acelerada según teoría
    '''
    acelAitken = []
    n = len(aprox)
    
    for k in range(n-2):
        aproxacel = aprox[k]-(aprox[k+1]-aprox[k])**2/(aprox[k+2]-2*aprox[k+1]+aprox[k])
        acelAitken.append(aproxacel)
    
    return acelAitken

def metodoAcelSteffesen(g,x0,niter):
    '''
    Método de aceleración de convergencia : Steffesen
    g -> Función definida como un problema de punto fijo
    x0 -> Aproximación inicial
    niter -> Número de iteraciones que se desean realizar
    '''

    aproxtemp = [x0,g(x0),g(g(x0))]
    acelSteff = []

    for i in range(niter):
        x0 = aproxtemp[0]-(aproxtemp[1]-aproxtemp[0])**2/(aproxtemp[2]-2*aproxtemp[1]+aproxtemp[0])
        aproxtemp = [x0,g(x0),g(g(x0))]
        acelSteff = acelSteff + [aproxtemp[0]]

    return acelSteff

def newtonRaphsonAcelerado(f,df,x0,m,cifras=16,prec=10**(-16),nmax=100,num_iter=False):
    '''
    Implementación del algoritmo de Newthon-Raphson acelerado
    para raíces múltiples
    '''
    x0 = Decimal(x0); m = Decimal(m)
    niter = 0; sale =''
    iter_list = []
    getcontext().prec = cifras
   
    tol = 10**(-cifras)
    for k in range(nmax):
        niter = niter + 1;
        x1 = x0 - m*f(x0)/Decimal(df(x0))
        iter_list.append(x1)
        if abs(x1-x0) < tol:
            sale = 'tolerancia'
            break
        if abs(f(x1)) < prec:
            sale = 'precision'
            break
        else:
            x0 = x1

    if sale == 'precision':
        print('Posiblemente solución exacta: ',x1)
    elif niter < nmax:
        print('Aproximación solicitada: ', x1)
    else:
        print('Se llegó al número máximo de iteraciones', x1)
    
    getcontext().prec = mporig
    if num_iter:
        print('Número de iteraciones reales en Newton-Raphson acelerado: ',niter)
    print('Multiplicidad de la raíz: ',m)

    return iter_list

def algoritmoHorner(x0,p):
    '''
    Implementación del algoritmo de Horner
    '''
    x0 = Decimal(x0)
    p.reverse()
    q = [p[0]]
    resto = 0
    
    for i in range(1,len(p)):
        resto = p[i]+q[i-1]*x0
        q.append(resto)
    
    resto = q.pop()
    q.reverse()

    return resto, q

def hornerTaylor(x,x0,p,orden):
    '''
    Implementación de la obtención del polinomio de Taylor
    usando el algoritmo de Horner para el cálculo de los coeficientes
    '''
    coefs = p
    resultado = Decimal(0)

    for i in range(orden):
        r, coefs = algoritmoHorner(x0,coefs)
        resultado += r * (x-x0)**i

    return resultado

def newtonRaphsonHorner(coefs,x0,cifras=16,prec=10**(-16),nmax=100,num_iter=False):
    '''
    Implementación del algoritmo de Newthon-Raphson para 
    el caso de un polinomio usando el algoritmo de Horner
    '''
    getcontext().prec = cifras
    tol = 10**(-cifras)
    niter = 0; sale = ''
    orden = 2; dp = 0
    sucesionNewtonRaphson = [];
    x0 = Decimal(x0)      

    for k in range(nmax):
        niter = niter + 1
       # Hacemos dp a partir del algoritmo de Horner
        p, der_coefs = algoritmoHorner(x0,coefs)
        dp, der_coefs = algoritmoHorner(x0,der_coefs)
        # Calculamos la aproximación
        x1 = x0 - p/dp
        p, der_coefs = algoritmoHorner(x1,coefs)
        sucesionNewtonRaphson.append(x1)

        if abs(x1-x0) < tol:
            sale = 'tolerancia'
            break
        if abs(p) < prec:
            sale = 'precision'
            break
        else:
            x0 = x1
            
        der_coefs = coefs

    if sale == 'precision':
        print('Posiblemente solución exacta: ',x1)
    elif niter < nmax:
        print('Aproximación solicitada: ',x1)
    else:
        print('Se llegó al número máximo de iteraciones: ',x1)
    if num_iter:
        print('Número de iteraciones reales en newtonRaphsonHorner: ',niter)
        
    return sucesionNewtonRaphson

def sturm(polinomio,x):
    '''
    Método para obtener una sucesión de Sturm para un polinomio
    '''
    
    p0 = polinomio
    p1 = sp.Poly(sp.diff(polinomio,x))
    
    sucesion = [p0,p1]
    p = p0 % p1
    p = sp.Poly(-p)
    while((sp.degree(p,x) != -sp.oo) or (p == p0)):
        sucesion.append(p)
        p0,p1 = p1,p
        p = p0 % p1
        p = sp.Poly(-p)
    
    return sucesion

def gNR(x):
    '''función de punto fijo asociada al método de N-R para f(x)'''
    return x - f(x)/df(x)

def gSteff(x):
    '''función de punto fijo asociada al método de Steffensen para f(x)'''
    return x - f(x)**2/(f(x+f(x))-f(x))