#include <iostream>

using namespace std;

void printArray(string* array, float* array1, int* array2, int n)
{
    for (int i = 0; i < n; ++i)
        cout << array2[i] << "\t" << array[i] << "\t" << "\t" << array1[i] << endl;
}

void bubble(float* a, string* arr, int* arr1, int n)
{
    for(int i=1;i<n;i++)
        for(int j=i;j>0 && a[j-1]>a[j];j--) { // пока j>0 и элемент j-1 > j, x-массив int
            swap(a[j - 1], a[j]);
            swap(arr[j - 1], arr[j]);
            swap(arr1[j - 1], arr1[j]);
        }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int array3[] = { 1,2,3,4,5,6,7,8,9,10,11};
    string array1[] = { "Топаз", "Лазер", "Свет", "Факел", "Луч", "Искра", "Квант", "Лев", "Утёс", "Агат", "Озон" };
    float array2[] = { 353.9, 455.8, 538.5, 437.8, 1553.7, 647.3, 515.2, 174.4, 124.0, 647.7, 496.6};
    int n = sizeof(array1) / sizeof(array1[0]);

    cout << "--- Массив до сортировки ---" << endl;
    printArray(array1, array2, array3, n);

    bubble(array2, array1, array3, n);

    cout << "--- Массив после сортировки ---" << endl;
    printArray(array1, array2, array3, n);

    cout << "\nНазвание магазина, показатель товарооборота которого находится после сортировки на предпоследнем месте: " << array3[9] << " " << array1[9] << endl;
}