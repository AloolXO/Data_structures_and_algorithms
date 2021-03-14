#include <iostream>

using namespace std;

double H(double n){
    if (n==1)
        return 1;
    if (n>1)
        return H(n-1)+(1/n);
}

int main() {

    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите значение переменной n: ";
    cin >> n;
    cout << "Результат рекурсивного знаяения:  " << H(n);

}
