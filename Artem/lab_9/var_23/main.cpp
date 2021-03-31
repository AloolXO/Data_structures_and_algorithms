#include <iostream>

using namespace std;

struct  Turnover {
    int number[11];
    string name[11];
    float count[11];
};

void print(const Turnover& tur, int n)
{
    for (int i = 0; i < n; ++i)
        cout << tur.number[i] << "\t" << tur.name[i] << "\t" << tur.count[i] << endl;
}

void bubble(Turnover& t, int n)
{
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < n-i; j++)
        {
            if (t.count[j] < t.count[j + 1])
            {
                float tmp = t.count[j];
                t.count[j] = t.count[j + 1];
                t.count[j + 1] = tmp;

                string tmp1 = t.name[j];
                t.name[j] = t.name[j + 1];
                t.name[j + 1] = tmp1;

                int tmp2 = t.number[j];
                t.number[j] = t.number[j + 1];
                t.number[j + 1] = tmp2;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
   struct Turnover year1 = {{1,2,3,4,5,6,7,8,9,10,11},
                            { "Топаз", "Лазер", "Свет", "Факел", "Луч", "Искра", "Квант", "Лев", "Утёс", "Агат", "Озон" },
                            { -353.9, 455.8, 538.5, 437.8, 1553.7, 647.3, 515,2-174.4, 124.0, 647.7, 496.6}};

    int n =12;

    cout << "--- Массив до сортировки ---" << endl;
    print(year1, n);

    bubble(year1, n);

    cout << "--- Массив после сортировки ---" << endl;
    print(year1, n);

    cout << "\nНомер и название месяца, показатель товарооборота в котором находится после сортировки на предпоследнем месте: " << year1.number[10] << " " << year1.name[10] << endl;
}