import numpy as np
b=4.7182818284590452353602874713527
a=2.7182818284590452353602874713527
N=8
h=(b-a)/N
x=np.linspace(a,b,N)
y=1/(x*np.log(x))
#y=x*x*2.71**-x;
f=0.0
for k in range(len(x)-1):
    f+=h*(y[k]+y[k+1])
    print("f(x_j):", f)
    print("x_j: ",k)
   # f+=0.5*((x[k+1]-x[k])*(y[k+1]+y[k]))
print("answer: ", f)
