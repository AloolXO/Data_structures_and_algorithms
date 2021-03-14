#include <iostream>

using namespace std;

int main()
{
    // ОШИБОЧНЫЙ КОД
    char* sptr = "abc", *tptr;
    *tptr = sptr;

    // ИСПРАВЛЕННЫЙ КОД
    char* sptr = (char*) "abc";
    char* tptr = sptr;

    /* 1. Нельзя просто присвоить строку к указателю, необходимо её привести к типу char*
       2. Нельзя объявлять новую переменную, после инициализации
    */
}