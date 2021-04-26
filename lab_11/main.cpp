#include <iostream>

using namespace std;

#define STACK_OVERFLOW -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY -102

typedef char T;
struct TStack {
    T Value;
    TStack* Next;
};

void push(TStack** Head, T value) {
    TStack* tmp = new TStack;
    if (tmp == nullptr) {
        exit(STACK_OVERFLOW);
    }
    tmp->Next = *Head;
    tmp->Value = value;
    *Head = tmp;
}

void printTStack(TStack** Head, int l) {
    cout << ("\nStack >") << endl;
    TStack* Current = *Head;
    for(int i = l; i>=0; i--) {
        cout << " " << Current->Value;
        Current = Current->Next;
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int c; string s;
    TStack* Top = nullptr;
    Top = new TStack;
    cout << "Введите число для проверки симметрии: ";
    cin >> s;
    int l = s.length()-1;

    for (int i = l; i >= 0; i--)
        push(&Top, s[i]);
    printTStack(&Top, l);

    int j = 0, i = l; bool b = false;

    while (i-1 != j+1) {
        if (s[j] == s[i])
            b = true;
        else
            b = false;
        j++;
        i--;
    }
    if (b)
        cout << "\n+";
    else
        cout << "\n-";
}
