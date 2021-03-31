#include <iostream>

using namespace std;

struct  Turnover {
    int index[12];
    string name[12];
    float count[12];
};

void print(const Turnover& tur, int n)
{
    for (int i = 0; i < n; ++i)
        cout << tur.index[i] << "\t" << tur.name[i] << "\t" << tur.count[i] << endl;
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

                int tmp2 = t.index[j];
                t.index[j] = t.index[j + 1];
                t.index[j + 1] = tmp2;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
   struct Turnover year1 = {{1,2,3,4,5,6,7,8,9,10,11,12},
                            { "Янв","Фев", "Мар", "Апр", "Май", "Июн", "Июл", "Авг", "Сен", "Окт", "Ноя", "Дек" },
                            { 102.6, 98.4, 102.3, 101.8, 96.5, 96.7, 96.8, 99.0, 105.2, 104.0, 105.3, 103.4 }};

    int n =12;

    cout << "--- Массив до сортировки ---" << endl;
    print(year1, n);

    bubble(year1, n);

    cout << "--- Массив после сортировки ---" << endl;
    print(year1, n);

    cout << "\nНомер и название месяца, показатель товарооборота в котором находится после сортировки на предпоследнем месте: " << year1.index[10] << " " << year1.name[10] << endl;
}