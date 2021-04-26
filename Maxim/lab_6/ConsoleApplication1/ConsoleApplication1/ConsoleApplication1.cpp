
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int* a; int n, i, c, w;
	cout << "Введите размерность массива "; cin >> n;
	a = new int[n];
	for (i = 0; i < n; i++)
		a[i] = rand() % 20 - 10;
	cout << "---------- Исходный массив ------------" << endl;
	for (i = 0; i < n; i++)
		cout << a[i] << " ";

	w = 0;
	for (i = 0; i < n; i++)
		if (abs(a[i]) < 5)
			w += a[i];

	cout << "\nСумма элиментов массива, абсолютные значения которых меньше 5: " << w << endl;
	
	c = 0;
	i = 0;
	w = 0;

	while (a[i]%2 == 0) {
		i++;
	}
	c = i;

	while (a[i+1]%2 == 0) {
		i++;
		w++;
	}
	cout << "\nКоличество элементов, расположенных между первым и вторым нечетным элементами: " << w << endl;
	
		
}
