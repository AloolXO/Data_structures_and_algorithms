#include <iostream>
#include <cmath>

using namespace std;

long double fact(int n)
{
    if (n < 0) // если пользователь ввел отрицательное число
        return 0; // возвращаем ноль
    if (n == 0) // если пользователь ввел ноль,
        return 1; // возвращаем факториал от нуля - не удивляетесь, но это 1 =)
    else // Во всех остальных случаях
        return n * fact(n - 1); // делаем рекурсию.
}

int main() {

    int n; long double epsilon, y, x, p;
    cout << "Введите степень погрешности: ";
    cin >> epsilon;
    cout << endl << "Введите значение переменной x: ";
    cin >> x;
    cout << endl;
    cout << "Результат вычисления левой части уравнения: " << ((1 + 2 * pow(x, 2)) / exp(pow(x, 2)));
    epsilon = pow(10, -abs(epsilon));
    p = 1;
    y = 1;
    n = 1;
    while (p >= epsilon) {
        p = pow(-1, n + 1) * (2 * (n)-1) * pow(x, 2 * n) / fact(n);
        y += p;
        n++;

    }
    cout << endl << "Результат вычисления правой части выражения: " << y << ", значение n: " << n - 1;
    cout << endl << "Значение факториала: " << fact(n);
}
