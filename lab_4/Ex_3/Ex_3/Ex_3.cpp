#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <random>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian"); //���������� �������� �����

    random_device rd;
    mt19937 mersenne(rd()); // �������������� ����� �������� ��������� ��������� ������ 

    int i, j;
    double d[300][300];
    for (i = 0; i < 300; i++)
        for (j = 0; j < 300; j++)
        {
            d[i][j] = mersenne();
            //cout << d[i][j] << " "; //��������� ��� ��������� ������������ ���������� ������� 300 �� 300
        }

    //cout << "\n"; //��������� ��� ����������� �������������

    double sr[300];
    for (i = 0; i < 300; i++)
    {
        double x = 0;
        for (j = 0; j < 300; j++)
            x += d[i][j];
        sr[i] = x / 300;
        //cout << sr[i] << " "; //��������� ��� ��������� ������������ ���������� ������� �� �������� ��������������� ����� ������� �������
    }

    //cout << "\n"; //��������� ��� ����������� �������������

    double max = 0;
    for (i = 0; i < 300; i++)
        if (sr[i] > max)
            max = sr[i];
    cout << "\n������������ ����� �������� �������� ��������������� ��������� ������ ������ ����� = " << max << "\n";
    return 0;
}