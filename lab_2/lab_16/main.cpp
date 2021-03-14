#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double x, y;
    cout << "Введите координаты точек x и y:" << endl;
    cin >> x >> y;
    cout << "x = " << x << ", y = " << y << " - ";
    if (((-x<=1)&&(y<=1)&&(-y<=0)&&(-x>=0))||((y<=-x+1)&&(-y<=0)&&(x>=0))||((pow(x,2)+pow(y,2)<=1)&&(y<=0)&&(-x>=0)))
        cout << "внутри";
    else
        cout << "снаружи";

}
