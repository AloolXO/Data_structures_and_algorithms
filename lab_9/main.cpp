#include <iostream>

using namespace std;

struct  Turnover {
    int index;
    string name;
    float count;
};

void print(const Turnover tur[], int n)
{
    cout << "№\t" << "Месяц\t" << "Объём продаж\t" << endl;
    cout << "===============================" << endl;
    for (int i = 0; i < n; ++i)
        cout << tur[i].index << "\t" << tur[i].name << "\t\t" << tur[i].count << endl;
}


void bubble(Turnover t[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < n-i; j++)
        {
            if (t[j].count < t[j + 1].count)
            {
                float tmp = t[j].count;
                t[j].count = t[j + 1].count;
                t[j + 1].count = tmp;

                string tmp1 = t[j].name;
                t[j].name = t[j + 1].name;
                t[j + 1].name = tmp1;

                int tmp2 = t[j].index;
                t[j].index = t[j + 1].index;
                t[j + 1].index = tmp2;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int index[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    string name[] = { "Янв","Фев", "Мар", "Апр", "Май", "Июн", "Июл", "Авг", "Сен", "Окт", "Ноя", "Дек" };
    float count[] = { 102.6, 98.4, 102.3, 101.8, 96.5, 96.7, 96.8, 99.0, 105.2, 104.0, 105.3, 103.4 };
   struct Turnover year1[12] = {};

    int n =12;

    for (int i = 0; i < n; ++i){
        year1[i].index = index[i];
        year1[i].name = name[i];
        year1[i].count = count[i];
    }

    cout << "--- Массив до сортировки ---" << endl;
    print(year1, n);

    bubble(year1, n);

    cout << "--- Массив после сортировки ---" << endl;
    print(year1, n);

    cout << "\nНомер и название месяца, показатель товарооборота в котором находится после сортировки на предпоследнем месте: " << year1[10].index << " " << year1[10].name << endl;
}