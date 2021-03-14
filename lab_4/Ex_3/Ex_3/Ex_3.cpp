#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <random>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian"); //Добавление русского языка

    random_device rd;
    mt19937 mersenne(rd()); // инициализируем Вихрь Мерсенна случайным стартовым числом 

    int i, j;
    double d[300][300];
    for (i = 0; i < 300; i++)
        for (j = 0; j < 300; j++)
        {
            d[i][j] = mersenne();
            //cout << d[i][j] << " "; //Добавлено для просмотра корректности заполнения массива 300 на 300
        }

    //cout << "\n"; //Добавлено для визуального разграничения

    double sr[300];
    for (i = 0; i < 300; i++)
    {
        double x = 0;
        for (j = 0; j < 300; j++)
            x += d[i][j];
        sr[i] = x / 300;
        //cout << sr[i] << " "; //Добавлено для просмотра корректности заполнения массива со средними арифметическими строк первого массива
    }

    //cout << "\n"; //Добавлено для визуального разграничения

    double max = 0;
    for (i = 0; i < 300; i++)
        if (sr[i] > max)
            max = sr[i];
    cout << "\nМаксимальное среди значений среднего арифметического элементов каждой строки равно = " << max << "\n";
    return 0;
}