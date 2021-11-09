import numpy as np
import matplotlib.pyplot as plt


def Function(x):
    x*x*2.71**-x


def trapz(f,a,b,N=50):
    x = np.linspace(a,b,N+1) # N+1 points make N subintervals
    y = f(x)
    y_right = y[1:] # right endpoints
    y_left = y[:-1] # left endpoints
    dx = (b - a)/N
    T = (dx/2) * np.sum(y_right + y_left)
    return T

def main():
    trapz(Function(x),0,1,N)
    
if __name__ == "__main__":
    main()