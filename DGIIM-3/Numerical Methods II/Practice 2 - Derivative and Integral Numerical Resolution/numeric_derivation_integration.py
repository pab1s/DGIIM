import numpy as np
import sympy as sp
import matplotlib.pyplot as plt
import matplotlib.patches as patches
from random import random

def mychop(expr, *, max=10**(-15)): 
    if abs(expr) > max:
      return expr 
    else:
      return 0

f = sp.Function('f')
a,h = sp.symbols('a,h')
z = sp.Symbol('z')
def f(x):
    return sp.cos(x)

# Numerical Derivation Formulas
def progressive_diff(f,a,h):
    z = sp.Symbol('z')
    x = [a,a+h]
    y = [f(x[0]),f(x[1])]
    p = (y[1]-y[0])/(x[1]-x[0])*(z-x[0])+y[0]
    return sp.diff(p,z).subs({z:a})

def regressive_diff(p,a,h):
    z = sp.Symbol('z')
    x = [a,a-h]
    y = [f(x[0]),f(x[1])]
    p = (y[1]-y[0])/(x[1]-x[0])*(z-x[0])+y[0]
    return sp.diff(p,z).subs({z:a})

def central_diff(p,a,h):
    z = sp.Symbol('z')
    x = [a-h,a+h]
    y = [f(x[0]),f(x[1])]
    p = (y[1]-y[0])/(x[1]-x[0])*(z-x[0])+y[0]
    return sp.diff(p,z).subs({z:a})

def central_2nd_diff(f,a,h):
    z = sp.Symbol('z')
    x = [a-h,h,a+h]
    y = [f(x[0]),f(x[1])]
    p = (y[1]-y[0])/(x[1]-x[0])*(z-x[0])+y[0]
    return sp.diff(p,z).subs({z:a})

# Do the regressive diff in 
#a=0 
#h=0.01
p = progressive_diff(f,a,h)
print(sp.N(p))
df = sp.diff(f(z),z).subs({z:a})
print(df)

# Numerical Integration Formulas
def simple_left_rectangle_int(f,a,b):
    '''fórmula simple de los rectangulos a izquierda'''
    x0 = a
    y0 = f(x0)
    return (b-a)*y0

def simple_right_rectangle_int(f,a,b):
    '''fórmula simple de los rectangulos a derecha'''
    x0 = b
    y0 = f(x0)
    return (b-a)*y0

def simple_center_rectangle_int(f,a,b):
    '''fórmula simple de los rectangulos centrados'''
    x0 = b-a
    y0 = f(x0)
    return (b-a)*y0

def left_rectangle_int(f,a,b,nx):
    '''fórmula compuesta de los rectangulos a izquierda'''
    h = (b-a)/nx
    return h*sum([f(a+i*h) for i in range(0,nx)])

def right_rectangle_int(f,a,b,nx):
    '''fórmula compuesta de los rectangulos a derecha'''
    h = (b-a)/nx
    return h*sum([f(a+i*h) for i in range(1,nx+1)])

def center_rectangle_int(f,a,b,nx):
    '''fórmula compuesta de los rectangulos centrados'''
    h = (b-a)/nx
    return h*sum([f(a+i*h) for i in range(1,nx)])

def simple_trapezoid_int(f,a,b):
    '''fórmula simple de los trapecios'''
    return (b-a)*(f(a)+f(b))/2

def trapezoid_int(f,a,b,nx):
    '''fórmula compuesta de los trapecios'''
    h = (b-a)/nx
    return h*(f(a)+f(b))/2+h*sum([f(a+i*h) for i in range(1,nx)])

def simple_simpson_int(f,a,b):
    '''fórmula simple de Simpson'''
    return (b-a)*(f(a)+4*f((a+b)/2)+f(b))/6

def simple_simpson_int_points(xL,yL,yM,xR,yR):
    """Fórmula de Simpson simple dados los puntos (xL,yL), (xM,yM) y (xR,yR)"""
    return -(xL - xR)*(yL + 4*yM + yR)/6

def simpson_int(f,a,b,m):
    '''fórmula compuesta de Simpson'''
    h= (b-a)/(2*m)
    P = sum([f(a+2*i*h) for i in range(1,m)])
    I = sum([f(a+(2*i-1)*h) for i in range(1,m+1)])
    E = f(a)+f(b)
    return h/3*(E+2*P+4*I)

def corrected_trapezoid_int(f,df,a,b,nx):
    h = (b-a)/nx
    return h/2*(f(a)+f(b)+2*sum([f(a+i*h) for i in range(1,nx)]))-h**2/12*(df(b)-df(a))

def gaussian_quadrature_w1(f,a,b,n):
    '''fórmula de la cuadratura gaussiana para la integral con peso 1'''
    grexact = 2*n-1
    p = sp.symbols('p1:'+ str(n+1))
    c = sp.symbols('c1:'+ str(n+1))
    nodos = list(p)
    coefs = list(c)
    incogs = coefs + nodos

    ecs = [np.dot([(z**i).subs({z:nodos[j]}) for j in range(n)],coefs)-sp.Rational(b**(i+1)-a**(i+1),(i+1)) for i in range(grexact+1)]
    solsGauss = sp.solve(ecs,incogs)

    for i in range(n):
        coefs[i] = solsGauss[0][i]
        nodos[i] = solsGauss[0][i+n]

    return np.dot([f(nodos[i]) for i in range(n)],coefs)

def w(x):
    """función peso"""
    return sp.exp(-x)

def gaussian_quadrature(f,w,a,b,n):
    '''fórmula de la cuadratura gaussiana para la integral con peso
    no idénticamente 1'''
    x = sp.Symbol('x')
    z = sp.Symbol('z')
    grexact = 2*n-1
    p = sp.symbols('p1:'+ str(n+1))
    c = sp.symbols('c1:'+ str(n+1))
    nodos = list(p)
    coefs = list(c)
    incogs = coefs + nodos

    ecs = [np.dot([(z**i).subs({z:nodos[j]}) for j in range(n)],coefs)-sp.integrate(w(x)*x**i,(x,a,b)) for i in range(grexact+1)]
    solsGauss = sp.solve(ecs,incogs)

    for i in range(n):
        coefs[i] = solsGauss[0][i]
        nodos[i] = solsGauss[0][i+n]

    return np.dot([f(nodos[i]) for i in range(n)],coefs)



# Appendix
xL,yL,xM,yM,xR,yR = sp.symbols('xL,yL,xM,yM,xR,yR')
dyL,dyR = sp.symbols('dyL,dyR')

def linea(z,xL,yL,xR,yR):
    """línea uniendo los puntos (xL,yL) y (xR,yR)"""
    return (z-xL)/(xR-xL)*yR+(xR-z)/(xR-xL)*yL

def parabola(x,xL,yL,xM,yM,xR,yR):
    '''fórmula de la parábola que une los puntos (xL,yL), (xM,yM) y (xR,yR)'''
    return yL -(x-xL)*(x-xM)*(xL*yM-xL*yR-xM*yL+xM*yR+xR*yL-xR*yM)/(xL**2*xM-xL**2*xR-xL*xM**2+xL*xR**2+xM**2*xR-xM*xR**2)+(x-xL)*(yL-yM)/(xL-xM)

def parabolaconderivada(x,d,xL,yL,xR,yR):
    """parábola con derivada fijada en el primer punto"""
    return (yL*(xL-xR)**2+(x-xL)*(x-xR)*(d*(xL-xR)+(yR-yL))+(x-xL)*(xL-xR)*(yL-yR))/(xL-xR)**2

def cubicaconderivadas(x,xL,yL,dL,xR,yR,dR):
    """cúbica con datos de Lagrange y Hermite en ambos extremos"""
    # DR = sp.Symbol('DR')
    # DR = sp.Rational(dL*xL-dL*xR+dR*xL-dR*xR-2*(yL-yR),(xL-xR)**3)
    DR = (dL*xL-dL*xR+dR*xL-dR*xR-2*(yL-yR))/(xL-xR)**3
    return parabolaconderivada(x,dL,xL,yL,xR,yR) + DR*(x-xL)**2*(x-xR)

def pintaIntegralRectangulo(f,a,b,nx):
    nxx = 100
    xx = np.linspace(float(a),float(b),nxx)
    yy = f(xx)
    x = np.linspace(a,b,nx); y = f(x)
    x0 = (x[1:]+x[:-1])/2; y0 = f(x0)

    fig,ax = plt.subplots(figsize=(8,8))
    ax.plot(x0,y0,'ro')
    ax.plot(xx,yy,'k',label='función del integrando')
    for k in range(1,nx):
        zz = np.linspace(float(x[k-1]),float(x[k]),nxx)
        yk = [linea(z,x[k-1],(y[k-1]+y[k])/2,x[k],(y[k-1]+y[k])/2) for z in zz]
        ax.fill_between(zz,0,yk);

    ax.legend(loc=9)
    ax.set_xlabel('$x$',fontsize=18)
    ax.set_ylabel('$y$',fontsize=18)
    ax.set_title('Fórmula compuesta de los rectángulos del punto medio');

def pintaIntegralTrapecio(f,a,b,nx):
    nxx = 100
    xx = np.linspace(float(a),float(b),nxx)
    yy = f(xx)
    x = np.linspace(a,b,nx); y = f(x)

    fig,ax = plt.subplots(figsize=(8,8))
    ax.plot(x,y,'ro')
    ax.plot(xx,yy,'k',label='función del integrando')
    for k in range(1,nx):
        zz = np.linspace(float(x[k-1]),float(x[k]),nxx)
        yk = [linea(z,x[k-1],y[k-1],x[k],y[k]) for z in zz]
        ax.fill_between(zz,0,yk);

    ax.legend(loc=9)
    ax.set_xlabel('$x$',fontsize=18)
    ax.set_ylabel('$y$',fontsize=18)
    ax.set_title('Fórmula del trapecio compuesta')

def pintaIntegralSimpson(f,a,b,m):
    nx=2*m; nxx = 100;  # fórmula de Simpson compuesta
    xx = np.linspace(float(a),float(b),nxx+1)
    yy = f(xx)
    x = np.linspace(a,b,nx+1); y = f(x)
    fig,ax = plt.subplots(figsize=(8,8))
    ax.plot(x,y,'ro')
    ax.plot(xx,yy,'k',label='función del integrando')

    for k in range(1,m+1):
        zz = np.linspace(float(x[2*(k-1)]),float(x[2*k]),nxx)
        yk = [parabola(z,x[2*(k-1)],y[2*(k-1)],x[2*k-1],y[2*k-1],x[2*k],y[2*k]) for z in zz]
        ax.fill_between(zz,0,yk);

    ax.legend(loc=9)
    ax.set_xlabel('$x$',fontsize=18)
    ax.set_ylabel('$y$',fontsize=18)
    ax.set_title('Fórmula de Simpson compuesta');