#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int n; long double epsilon, y, x, p;
    cout << "Введите степень погрешности: ";
    cin >> epsilon;
    cout << endl << "Введите значение переменной x: ";
    cin >> x;
    cout << endl;
    cout << "Результат вычисления левой части уравнения: " << (exp(-pow(x,2)));
    epsilon = pow(10,-abs(epsilon));
    p = 1;
    y = 1;
    n = 1;
    int i = 1;
    while (abs(p) >= epsilon) {
        p *= -1*x*x/i;
        y += p;
        n++;
        i++;
    }
    cout << endl << "Результат вычисления правой части выражения: " <<  y << ", значение n: " << n-1;
}
