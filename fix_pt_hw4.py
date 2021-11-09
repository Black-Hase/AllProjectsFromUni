# Fixed Point Iteration Method
# Importing math to use sqrt function
import math

def func(x): 
	return math.tan((math.pi*x))-6

# Re-writing f(x)=0 to x = g(x)
def g(x):
    return math.pi + 0.5*math.sin(frac(x,))

# Implementing Fixed Point Iteration Method
def fixedPointIteration(x0, e, N):
    print('\n\n*** FIXED POINT ITERATION ***')
    step = 1
    flag = 1
    condition = True
    while condition:
        x1 = g(x0)
        print('Iteration-%d, x1 = %0.6f and func(x1) = %0.6f' % (step, x1, func(x1)))
        x0 = x1

        step = step + 1
        
        if step > N:
            flag=0
            break
        
        condition = abs(func(x1)) > e

    if flag==1:
        print('\nRequired root is: %0.8f' % x1)
    else:
        print('\nNot Convergent.')

# Input Section

# Converting x0 and e to float
x0 = 0
e = float(.01)

# Converting N to integer
N = int(.48)


#Note: You can combine above three section like this
# x0 = float(input('Enter Guess: '))
# e = float(input('Tolerable Error: '))
# N = int(input('Maximum Step: '))

# Starting Newton Raphson Method
fixedPointIteration(x0,e,N)