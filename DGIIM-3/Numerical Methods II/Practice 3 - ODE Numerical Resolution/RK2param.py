def integrate(F,alpha,beta,a,b,x0,N):
    import numpy as np

    h = (b-a)/float(N)

    tn =[]
    xn = []
    tn.append(a)
    xn.append(x0)

    for i in range(1,N+1):
        tn.append(a+i*h)
        xn.append(0)

    for i in range(N):
        K1 = F(tn[i],xn[i])
        K2 = F(tn[i]+beta*h, xn[i]+h*beta*K1)
        xn[i+1] = xn[i] + h*((1-alpha)*K1 + alpha*K2)

    return np.array(tn), np.array(xn)