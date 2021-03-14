#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double fun(double x){
    double a = 0.5*cos(x/3)-(pow(sin(3*x),2));
    return a;
}

int main() {

    double x,y;
    x = 0;
    y = 0;

    while (y>=0){
        y = fun(x);
        x += 0.00000001;
    }

    while (x<6){
        if (y<0) {
            y = fun(x);
            x += 0.00000001;
        }
        else {
            y = fun(x);
            break;
        }
    }

    cout << fixed << showpoint << setprecision(10);
    cout << y << endl;
    cout << x;
}
