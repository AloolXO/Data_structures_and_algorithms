
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int* a; int n, i, c, q, w;
	cout << "Введите размерность массива "; cin >> n;
	a = new int[n];
	c = 0;
	for (i = 0; i < n; i++)
		a[i] = rand() % 20 - 10;
	cout << "---------- Исходный массив ------------" << endl;
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	for (i = 0; i < n; i++) {
		if (i % 2 == 0)
			c += a[i];
	}
	cout << "\nСумма элиментов массива на четный позициях: " << c << endl;
	q = 1000;
	for (i = 0; i < n; i++) {
		if (q > a[i]) {
			q = a[i];
			w = i;
		}
	}
	c = 0;
	for (w; w < n; w++) 
		c ++;
	cout << "\nКоличество элементов массива, расположенных после минимального элемента: " << c << endl;
	
		
}
