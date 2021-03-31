#include <iostream>
#include <cmath>

using namespace std;

int T(int x,int n) {
    if (n == 0)
        return 1;
    if (n > 0)
        return x*T(x,n-1);
    if (n < 0)
        return T(x,n+1)/x;
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int x, n;
    cout << "Введите значение переменной x = ";
    cin >> x;
    cout << "Введите значение переменной n = ";
    cin >> n;
    cout << "Результат рекурсивного знаяения:  " << T(x, n);
}
