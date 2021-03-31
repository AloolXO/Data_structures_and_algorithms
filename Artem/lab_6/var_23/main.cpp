
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int* a; int n, i, c, q, w;
    cout << "Введите размерность массива "; cin >> n;
    a = new int[n];
    c = 0;
    for (i = 0; i < n; i++)
        a[i] = rand() % 20 - 10;
    cout << "---------- Исходный массив ------------" << endl;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    for (i = 0; i < n; i++)
        if (abs(a[i])<5)
            c += a[i];
    cout << "\nСумма элиментов массива, которые меньше 5: " << c << endl;
    c=0;
    for (i = 0; i< n; i++)
        if (a[i]%2!=0){
            w=i;
            break;
        }
    for (i = w; i< n; i++)
        if (a[i]%2!=0){
            q=i;
            break;
        }
    for (i = w; i < q; i++)
        if (abs(a[i]) < 5)
            c ++;
    cout << "\nКоличество элементов, расположенных между первым и вторым нечетным элементами: " << c << endl;


}
