#include <iostream>

using namespace std;

struct  Turnover {
    int number;
    string name;
    float count;
};

void print(const Turnover tur[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << tur[i].number << "\t" << tur[i].name << "\t" << tur[i].count << endl;
}

void bubble(Turnover a[], int n)
{
    for(int i=1;i<n;i++)
        for(int j=i;j>0 && a[j-1].count>a[j].count;j--) { // пока j>0 и элемент j-1 > j, x-массив int
            swap(a[j - 1].count, a[j].count);
            swap(a[j - 1].number, a[j].number);
            swap(a[j - 1].name, a[j].name);
        }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int number[] = {1,2,3,4,5,6,7,8,9,10,11};
    string name[] =  { "Топаз", "Лазер", "Свет", "Факел", "Луч", "Искра", "Квант", "Лев", "Утёс", "Агат", "Озон" };
    float count[] = { -353.9, 455.8, 538.5, 437.8, 1553.7, 647.3, 515,2-174.4, 124.0, 647.7, 496.6};
   struct Turnover product[11] = {};

    int n =11;

    for (int i = 0; i < n; ++i) {
        product[i].number = number[i];
        product[i].name = name[i];
        product[i].count = count[i];
    }

        cout << "--- Массив до сортировки ---" << endl;
    print(product, n);

    bubble(product, n);

    cout << "--- Массив после сортировки ---" << endl;
    print(product, n);

    cout << "\nНомер и название месяца, показатель товарооборота в котором находится после сортировки на предпоследнем месте: " << product[9].number << " " << product[9].name << endl;
}