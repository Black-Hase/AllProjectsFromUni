import math

# An example function whose 
# solution is determined using 
# Bisection Method. 
# The function is x^3 - x^2 + 2 
def func(x): 
	return math.tan((math.pi*x))-6


def secant(a,b,N):
    if func(a)*func(b) >= 0:
        print("Secant method fails.")
        return None
    a_n = a
    b_n = b
    for n in range(0,N):
        m_n = a_n - func(a_n)*(b_n - a_n)/(func(b_n) - func(a_n))
        f_m_n = func(m_n)
        if func(a_n)*f_m_n < 0:
            a_n = a_n
            b_n = m_n
            print("11111")
        elif func(b_n)*f_m_n < 0:
            a_n = m_n
            b_n = b_n
            print(m_n)
        elif f_m_n == 0:
            print("33333333333")
            print("Found exact solution.")
            return m_n
        else:
            print("4444444444")
            print("Secant method fails.")
            return None
    return a_n - func(a_n)*(b_n - a_n)/(func(b_n) - func(a_n))
#driver
def main():
    a=0
    b=.48
    N=10
    
    secant(a,b,N)

if __name__ == "__main__":
    main()
