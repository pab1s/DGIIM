# -*- coding: UTF-8 -*-
## modulo metdodoBiseccion
'''
c = metdodoBiseccion(f,a,b,tol,prec,nmax)
buscará dentro del intervalo [a,b] el cero f(c) acotando cada vez
mas el intervalo para encontrar la raíz simple f(x) en dicho intervalo.
Se devolverá None en caso de no encontrarse ninguna.
'''
# global f,a,b,tol,prec,nmax
def metdodoBiseccion(f,a,b,tol,prec=16,nmax=100):
    niter = 0
    sale = ''

    for k in range(nmax):
        niter = niter + 1
        c = a + (b-a)/2  # equivalente a c = (a+b)/2
        if abs(f(c)) < prec:
            sale = 'precision'
            break
        if sign(f(a)) != sign(f(c)):
            b = c
        else:
            a = c
        if b-a < tol:
            sale = 'tolerancia'
            break

    if sale == 'precision':
        print('Posiblemente solución exacta: ', c)
    elif niter < nmax:
        print('Aproximación solicitada: ', c)
    else:
        print('Se llegó al número máximo de iteraciones')
    print('Solución exacta, ', sol_exact, ", con decimales  ", sol_exact.evalf())
    print('Número total de iteraciones ', niter)
    return c

