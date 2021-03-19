#include <iostream>

using namespace std;

void printArray(string* array, float* array1, int* array2, int n)
{
    for (int i = 0; i < n; ++i)
        cout << array2[i] << "\t" << array[i] << "\t" << array1[i] << endl;
}

void bubble(float* a, string* arr, int* arr1, int n)
{
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < n-i; j++)
        {
            if (a[j] < a[j + 1])
            {
                float tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;

                string tmp1 = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp1;

                int tmp2 = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = tmp2;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int array3[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
    string array1[] = { "Янв","Фев", "Мар", "Апр", "Май", "Июн", "Июл", "Авг", "Сен", "Окт", "Ноя", "Дек" };
    float array2[] = { 102.6, 98.4, 102.3, 101.8, 96.5, 96.7, 96.8, 99.0, 105.2, 104.0, 105.3, 103.4 };
    int n = sizeof(array1) / sizeof(array1[0]);

    cout << "--- Массив до сортировки ---" << endl;
    printArray(array1, array2, array3, n);

    bubble(array2, array1, array3, n);

    cout << "--- Массив после сортировки ---" << endl;
    printArray(array1, array2, array3, n);

    cout << "\nНомер и название месяца, показатель товарооборота в котором находится после сортировки на предпоследнем месте: " << array3[10] << " " << array1[10] << endl;
}