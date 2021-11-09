from scipy import misc

def NewtonsMethod(f, x, tolerance=0.00001):
    while True:
        x1 = x - f(x) / misc.derivative(f, x) 
        t = abs(x1 - x)
        if t < tolerance:
            break
        x = x1
    return x

def f(x):
    return x*x*x*x-2*x*x*x-12*x*x+16*x-40
def main():
    print("Newtons-R Method B")
    x_1=1
    x0 = NewtonsMethod(f, x_1)
    print('x_1: ', x_1)
    print('x0: ', x0)
    x_2 = 4
    x1 = NewtonsMethod(f, x_2)
    print('x_2: ', x_2)
    print('x1: ', x1)
if __name__ == "__main__":
    main()

    
