#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

double fun(double x) {
    double a;
    a = log2(x+4)-0.5*(sin(pow((x+6)/3,3))+5);
    return a;
}

int main()
{
    double x, y;
    y = -100000;
    x = 0;
    while (x < 6) {
        if (y < 0) {
            y = fun(x);
            x += 0.00000001;
        }
        else {
            break;
        }
    }

    cout << fixed << showpoint << setprecision(10);
    cout << x << "\n";
}