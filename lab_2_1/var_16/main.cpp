#include <iostream>
#include <cmath>
#include <iomanip>

using  namespace std;

int main() {

    double x, Q; int n, i, j=2;
    cout << "Введите значение переменной n: ";
    cin >> n;
    cout << "Введите значение переменной x: ";
    cin >> x;
    Q=x;
    if (n==1)
        Q=x;
    else {
        for (i=0; i<n; i++) {
           Q *= (1-(pow(j,-1)));
           j += 2;
        }
    }
    cout << "При n = " << n << " и x = " << x << fixed << showpoint << setprecision(6) << "; Q = " << Q;
}
