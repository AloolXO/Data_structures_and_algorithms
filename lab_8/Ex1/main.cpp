#include <iostream>
#include <iomanip>

using namespace std;

int sum_f(int** arr, int n){
    int s=0;
    for (int i = 0; i < n;i++){
        for (int j = 0;j<n;j++)
            if ((i==0)||(j==i)||(j==(n-1)-i)||(i==n-1))
                s += arr[i][j];
    }
    return s;
}

void print (int** arr, int n, int sum){
    cout << "\t" << " ---- Массив ---- ";
    for (int i = 0; i < n;i++) {
        cout << "\n";
        for (int j = 0; j < n; j++)
            cout << setw(5) << arr[i][j];
    }
    cout << "\n" << "\n" << "Результат вычисления: " << sum << "\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n, sum, **arr;
    cout << "Введите размерность массива: ";
    cin >> n;
    arr = new int *[n];

    //Создание массива и заполнение 1 и 0
    for (int i = 0; i < n;i++){
        arr[i] = new int [n];
        for (int j = 0;j<n;j++)
            if ((i==0)||(j==i)||(j==(n-1)-i)||(i==n-1))
                arr[i][j]= 1;
            else
                arr[i][j]= 0;
    }

    sum = sum_f(arr, n);

    //Вывод массива и результата

    print(arr, n, sum);

}
