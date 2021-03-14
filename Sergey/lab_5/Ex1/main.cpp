#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

long double fun(long double x){
    long double a = sin(10*x-20)/exp(pow(x-2,2)/5)+0.25-x;
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
