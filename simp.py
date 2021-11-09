#simpson's Rule
import numpy as np
import matplotlib.pyplot as plt
b=3.7182818284590452353602874713527
a=2.7182818284590452353602874713527
N=2
x = np.linspace(a,b,N+1)
y=1/(x*np.log(x))
S=0.0
#if statement is unneccisary in this case but could be useful 
if N % 2 == 1:
    raise ValueError("N must be an even integer.")
dx = (b-a)/N

S += dx/3 * np.sum(y[0:-1:2] + 4*y[1::2] + y[2::2])
print(S)