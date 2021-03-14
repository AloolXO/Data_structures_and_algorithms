#include <iostream>

using namespace std;

int T(int n) {
    if (n == 2)
        return 1;
    else if ((n == 1) || (n > 2))
        return ((2 * T(n / 2)) + n);
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите значение переменной n = ";
    cin >> n;
    cout << "Результат рекурсивного знаяения:  " << T(n);
}
