import math

# An example function whose 
# solution is determined using 
# Bisection Method. 
# The function is x^3 - x^2 + 2 
def func(x): 
	return math.tan((math.pi*x))-6


# Implementing False Position Method
def falsePosition(x0,x1,e):
    step = 1
    print('\n\n*** FALSE POSITION METHOD IMPLEMENTATION ***')
    condition = True
    while condition:
        x2 = x0 - (x1-x0) * func(x0)/( func(x1) - func(x0) )
        print('Iteration-%d, x2 = %0.9f and func(x2) = %0.9f' % (step, x2, func(x2)))

        if func(x0) * func(x2) < 0:
            x1 = x2
        else:
            x0 = x2

        step = step + 1
        condition = abs(func(x2)) > e

    print('\nRequired root is: %0.9f' % x2)


# Input Section
x0 = 0
x1 = .48
e = .1

# Converting input to float
x0 = float(x0)
x1 = float(x1)
e = float(e)

#Note: You can combine above two section like this
# x0 = float(input('First Guess: '))
# x1 = float(input('Second Guess: '))
# e = float(input('Tolerable Error: '))


# Checking Correctness of initial guess values and false positioning
if func(x0) * func(x1) > 0.0:
    print('Given guess values do not bracket the root.')
    print('Try Again with different guess values.')
else:
    falsePosition(x0,x1,e)