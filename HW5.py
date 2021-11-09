{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": [
    "# Python program for implementation \n",
    "# of Bisection Method for \n",
    "# solving equations \n",
    "\n",
    "\n",
    "# An example function whose \n",
    "# solution is determined using \n",
    "# Bisection Method. \n",
    "# The function is x^3 - x^2 + 2 \n",
    "def func(x): \n",
    "\treturn math.tan(math.pi*x)\n",
    "\n",
    "# Prints root of func(x) \n",
    "# with error of EPSILON \n",
    "def bisection(a,b): \n",
    "\n",
    "\tif (func(a) * func(b) >= 0): \n",
    "\t\tprint(\"You have not assumed right a and b\\n\") \n",
    "\t\treturn\n",
    "\n",
    "\tc = a \n",
    "\twhile ((b-a) >= 0.01): \n",
    "\n",
    "\t\t# Find middle point \n",
    "\t\tc = (a+b)/2\n",
    "\n",
    "\t\t# Check if middle point is root \n",
    "\t\tif (func(c) == 0.0): \n",
    "\t\t\tbreak\n",
    "\n",
    "\t\t# Decide the side to repeat the steps \n",
    "\t\tif (func(c)*func(a) < 0): \n",
    "\t\t\tb = c \n",
    "\t\telse: \n",
    "\t\t\ta = c \n",
    "\t\t\t\n",
    "\tprint(\"The value of root is : \",\"%.4f\"%c) \n",
    "\t\n",
    "# Driver code \n",
    "# Initial values assumed \n",
    "a = 0\n",
    "b = 0.48\n",
    "bisection(a, b) \n",
    "\n",
    "# This code is contributed \n",
    "# by Anant Agarwal. \n"
   ]
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "Python 3",
   "language": "python",
   "name": "python3"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.8.6"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 4
}
