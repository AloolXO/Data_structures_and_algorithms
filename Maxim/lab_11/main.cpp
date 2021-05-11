#include <iostream>
#include <math.h>
using namespace std;


struct Tstack {
    char Data;
    Tstack* next;
};
int pop(Tstack*& stack)
{
    char result;
    Tstack* top = new Tstack;
    top = stack;
    result = top->Data;
    stack = top->next;
    delete top;
    return result;
}
bool Pairs(char openP, char closedP)
{
    if (openP == '(' && closedP == ')') return true;
    else if (openP == '[' && closedP == ']') return true;
    else return false;

}
bool Check(string exp)
{
    int i = 0;
    Tstack* stack = NULL;
    while (exp[i]) {
        if (exp[i] == '(' || exp[i] == '[') {
            Tstack* neww = new Tstack;
            neww->Data = exp[i];
            neww->next = stack;
            stack = neww;
        }
        if (exp[i] == ')' || exp[i] == ']') {
            if (stack == NULL)
                return 0;
            else if (Pairs(pop(stack), exp[i]) == 0)
                return 0;
        }
        i++;

    }
    if (stack == NULL)
        return 1;
    else
        return 0;
}
int main()
{
    setlocale(LC_ALL, "RUS");
    string exp;
    cout << "Введите скобки:\n";
    cin >> exp;
    if (Check(exp) != 0)
        cout << "\nСкобки правильно расположенны\n";
    else
        cout << "\nСкобки НЕ правильно расставленны\n";
    return 0;
}