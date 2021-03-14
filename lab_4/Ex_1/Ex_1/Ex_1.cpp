#include <iostream>

using namespace std;

int main()
{
    // ИНИЦИАЛИЗАЦИЯ ЦЕЛОЧИСЛЕННОЙ ПЕРЕМЕННОЙ И ПРИСВОЕНИЕ УКАЗАТЕЛЯМ АДРЕСА ЭТОЙ ПЕРЕМЕННОЙ
    int a = 101;
    int* b = &a;
    int* c = &a;

    // ИНИЦИАЛИЗАЦИЯ И ВВОД ЗНАЧЕНИЕ ПЕРЕМЕННОЙ I
    int i;
    cout << "Enter the value of the variable i: ";
    cin >> i;

    // ВЫВОД ЗНАЧЕНИЙ И АДРЕСОВ УКАЗАТЕЛЕЙ 
    cout << "Pointer value *b = " << *b;
    cout << "\nPointer address *b = " << b;
    cout << "\nPointer value *c = " << *c + i;
    cout << "\nPointer address *c = " << c + i;
}