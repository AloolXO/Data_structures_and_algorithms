#include <iostream>

using namespace std;

struct Tlist {
    int Data;
    Tlist* Next;
};

Tlist* q (int a) {
    Tlist* lst = new (Tlist);
    lst->Data = a;
    lst->Next = lst;
    return(lst);
}

Tlist* addItem(Tlist* lst, int name) {
    Tlist* temp = new (Tlist);
    Tlist* p;
    p = lst->Next;
    lst->Next = temp;
    temp->Data = name;
    temp->Next = p;
    return (temp);
}

int index (Tlist* lst, const int index) {
    int counter = 0;
    Tlist* current = lst;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->Data;
        }
        current = current->Next;
        counter++;
    }

}

void List_print(Tlist* lst) {
    Tlist* p;
    p = lst;
    cout << "\n------- Список детей -------\n" << endl;
    do {
        cout << " " << p->Data;
        p = p->Next;
    } while (p != lst);
}

Tlist* Delete_Item_Cricle_Single_List(Tlist* Head, int x, int count) {
//    if (Head != nullptr) {
//        Tlist* Current = Head;
//        if (Head->Next != Head) {
//            for (int i = 0; i < name; i++)
//                Current = Current->Next;
//            Tlist* ptr = Head;
//            while (ptr->Next != Current)
//                ptr = ptr->Next;
//            ptr->Next = Current->Next;
//            if (Head == Current)
//                Head = Current->Next;
//            delete(Current);
//        }
//        else {
//            Head = nullptr;
//            delete (Current);
//        }
//    }
//    return Head;
    Tlist* Current = Head;
    int c = 0;
    if (Head != nullptr){
        if (Head->Next != Head) {
            for (int i = 0; i < count - 1; i++) {
                if (i % x == 0) {
                    Current->Data = 0;
                    c++;
                }
                Current = Current->Next;
            }
        }
    }

    Tlist* ptr = Head;
    Current = Head;
    for (int i = 0; i < count - 1; i++) {
        if (Current->Data == 0) {
            while (ptr->Next != Current)
                ptr = ptr->Next;
            ptr->Next = Current->Next;
            if (Head == Current)
                Head = Current->Next;
            delete (Current);
        } else {
            Current = Current->Next;
        }

    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int a, n;
    cout << "Число детей в кругу: ";
    cin >> n;
    cout << "Введите номер ребёнка: ";
    cin >> a;
    Tlist* children;
    children = q(a);

    for (int i = 1; i < n; i++) {
        int name;
        cout << "Введите номер ребёнка: ";
        cin >> name;
        addItem(children, name);
    }

    List_print(children);

    cout << "\nНеобходимо удалить каждого ";
    cin >> a; cout << " ребёнка." ;


    children = Delete_Item_Cricle_Single_List(children, a-1);

    List_print(children);

}