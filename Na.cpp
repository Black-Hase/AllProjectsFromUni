#include <codecogs/maths/approximation/interpolation/cubic.h>
 
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;
 
#define PI  3.1415
#define N   12
 
int main() 
{
    // Declare and initialize two arrays to hold the coordinates of the initial data points
    double x[N], y[N];
 
    // Generate the points
    double xx = PI, step = 4 * PI / (N - 1);
    for (int i = 0; i < N; ++i, xx += step) {
        x[i] = xx;
        y[i] = sin(2 * xx) / xx;
    }
 
    // Initialize the Cubic spline interpolation routine with known data points
    Maths::Interpolation::Cubic A(N, x, y);
 
    // Interrogate spline curve to find interpolated values
    int N_out = 20;
    xx = PI, step = (3 * PI) / (N_out - 1);
    for (int i = 0; i < N_out; ++i, xx += step) {
        cout << "x = " << setw(7) << xx << "  y = ";
        cout << setw(13) << A.getValue(xx) << endl;
  }
  return 0;
}