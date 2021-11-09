#hardcoded to only work for 2 points
#general form is crazy complicated and a whole hw assignment on it's own
from sympy import *
def cubic_spline_2(x0,x1,y0,y1, free):
    x=symbols('x')
    a=symbols('a')
    b=symbols('b')
    c=symbols('c')
    d=symbols('d')
    S = a + b*(x-x0)+c*(x-x0)**2 + d*(x-x0)**3
    
    S2=diff(diff(S,x),x)
    
    # S(x0)=y0  =>
    a_val = x0
    S=S.subs(a, a_val)
    
    if free:
        # S''(x0)=0
        # S''(x1)=0
        
        #after some painful work involving linear algebra solvers, 
        #I realized those two equations imply that c=d=0
        # linsolve([S2.subs(x,x0), S2.subs(x,x1)], (c, d))
        
        c_val = 0
        d_val = 0
        
        S=S.subs(c, c_val)
        S=S.subs(d, d_val)
        
        #S(x1)=y1   =>
        b_val = solve(S.subs(x,x1), b)
        S=S.subs(b, b_val[0])
        #print(b_val)
        print("S1: ", S)
    else:
        S1=diff(S,x)

        fp0 = float(input("enter f'(x0): "))
        fp1 = float(input("enter f'(x1): "))
        
        #                      S'(x0)=f'(x0)      S'(x1)=f'(x1)        S(x1)=y1
        bcd = list(linsolve([S1.subs(x,x0) - fp0, S1.subs(x,x1) - fp1, 
                S.subs(x,x1) - y1], (b, c, d)))
        #bcd is a list within a list for some reason
        #print(bcd[0])
        
        b_val = bcd[0][0]
        c_val = bcd[0][1]
        d_val = bcd[0][2]
        
        S=S.subs(b, b_val)
        S=S.subs(c, c_val)
        S=S.subs(d, d_val)
        print("S2: ", S)
    return(S)

def main():
    print("main")
    free= True 
    cubic_spline_2(8.3,8.6,17.56492,18.50515, free)

if __name__ == "__main__":
    main()
