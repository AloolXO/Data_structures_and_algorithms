#include <iostream>
#include <iomanip>

using namespace std;

int sum_f(int** arr, int n){
    int s=0;
    for (int i = 0; i < n;i++){
        for (int j = 0;j<n;j++)
            if ((i==0)||(i==1)||(i==n-2)||(i==n-1)||(j==n-1)||(j==n-2)||(j==0)||(j==1))
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

void del (int** arr, int n){
    for (int i = 0; i < n;i++) {
        for (int j = 0; j < n; j++)
            delete arr[i];
    }
    delete [] arr;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n, sum, **arr, count = 1;
    cout << "Введите размерность массива: ";
    cin >> n;
    arr = new int *[n];

    //Создание массива и заполнение 1 и 0
    for (int i = 0; i < n;i++){
        arr[i] = new int [n];
        for (int j = 0;j<n;j++)
            if ((i==0)||(i==1)||(i==n-2)||(i==n-1)||(j==n-1)||(j==n-2)||(j==0)||(j==1))
                arr[i][j]= 1;
            else
                arr[i][j]= 0;
    }

    sum = sum_f(arr, n);

    //Вывод массива и результата

    print(arr, n, sum);

    //Создание массива и заполнение цифрами
    for (int i = 0; i < n;i++){
        for (int j = 0;j<n;j++) {
            arr[i][j] = count;
            count++;
        }

    }

    sum = sum_f(arr, n);

    //Вывод массива и результата

    print(arr, n, sum);

    //Удаление мссива

    del (arr, n);
}
