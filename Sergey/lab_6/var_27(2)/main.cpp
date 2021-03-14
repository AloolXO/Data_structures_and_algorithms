#include <iostream>
#include <random>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    int* a; int n, i, c, max, w, m;
    cout << "Введите размерность массива "; cin >> n;
    a = new int[n];
    int min = 12;

    for (i = 0; i < n; i++)
        a[i] = rand() % 20 - 10;
    cout << "---------- Исходный массив ------------" << endl;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";

    c = 0;
    for (i = 0; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
            c = i;
        }
    }
    cout << "\nМинимальный элимент массива: " << min << ", индекс минимального элимента: " << c << endl;

    max = -13;
    for (i = 0; i < n; i++) {
        if (max < abs(a[i])) {
            max = abs(a[i]);
            w = i;
        }
    }

    c = 0;
    min = 12;
    for (i = 0; i < n; i++) {
        if (abs(a[i]) < min) {
            min = abs(a[i]);
            c = i;
        }
    }

    m=1;
    if (w>c) {
        for (i=w; i < c; i++)
            m *= a[i];
    }
    else {
        for (i=c-1; i < w; i--)
            m *= a[i];
    }

    cout << "\nПроизведение элементов массива, расположенных между максимальным по модулю и минимальным по модулю элементами: " << m << endl;
    cout << w << " " << c;

}
