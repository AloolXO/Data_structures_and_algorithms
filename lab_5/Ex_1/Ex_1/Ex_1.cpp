#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cmath>

using namespace std;

double fun(double x) {
    double a;
    a = 0.5 * sin(((x + 3) * (x + 3)) / 2) + (log(x + 2)) / 2 - 1;
    return a;
}
    
int main()
{
    double x, y, a;
    y = -100000;
    x = 0;
    while (x < 6) {
        if (y < 0) {
            y = fun(x);
            x += 0.0000001;
        }
        else {
            break;
        }
    }

    cout << fixed << showpoint << setprecision(10);
    cout << x;
}
