#include <iostream>

using namespace std;

int main() {

    //double a = 176.24;
    auto *x = new double (176.24);
    auto *y = new double (176.24);

    cout << "Значение указателя x = " << *x << endl;
    cout << "Адрес указателя x: " << x << endl;
    cout << "Значение указателя y = " << *y+26.84 << endl;
    cout << "Адрес указателя y: " << y  << endl;

    delete (y);
    delete (x);

}
