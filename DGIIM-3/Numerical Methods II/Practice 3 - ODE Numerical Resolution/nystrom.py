## módulo NYstrom
''' Método de Nystrom (q=2, m=0, r>=0) para r=1 y k=2 para resolver
    el problema de valores iniciales {y}' = {F(x,{y})},
    donde {y} = {y[0],y[1],...y[N-1]}.
    X,Y = integrate(F,x0,y0,xfinal,N).
    x0,y0 = condiciones iniciales
    xfinal = valor final de x
    N = número de subintervalos de la partición
    h = incremento de x usado en la integración
    F = función suplida por el usuario que devuelve el
    array F(x,y) = {y'[0],y'[1],...,y'[N-1]}.
'''
def integrate(F,x0,y0,xfinal,N):

    import numpy as np

    def Nys(F,x0,y1,h):
        return 2*F(x0+h,y1)
        
    X = np.linspace(x0,xfinal,N+1)
    h = (xfinal-x0)/float(N)
    y1 = y0 + h*F(x0,y0); Y = [y0,y1]
    for n in range(N-1):
        Y.append(Y[n] + h*Nys(F,X[n],Y[n+1],h))
    return np.array(X),np.array(Y)
