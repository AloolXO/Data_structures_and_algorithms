#include <iostream>
#include <string>
#include <random>
using namespace std;

template<typename T>
class List
{
public:
    List();
    ~List();

    void pop_front();
    void clear();
    void push_back(T data);
    int GetSize() { return Size; }
    T& operator[](int index);

    void push_front(T data);
    void insert (T value, int index);
    void removeAt(int index);
    void pop_back();

private:

    template<typename t>
    class Node
    {
    public:
        Node* pNext;
        t data;

        Node(t data = t(), Node* pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;
    Node<T>* head;
};

template<typename T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List()
{
    clear();
}

template<typename T>
void List<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else {
        Node<T>* current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size++;
}

template<typename T>
T& List<T>::operator[](const int index) {
    int counter = 0;
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

template<typename T>
void List<T>::pop_front() {
    Node<T> *temp = this->head;
    head = head->pNext;
    delete temp;
    Size--;
}

template<typename T>
void List<T>::clear() {
    while(Size)
    {
        pop_front();
    }
}

template<typename T>
void List<T>::push_front(T data) {
    head = new Node<T>(data,head);
    Size++;
}

template<typename T>
void List<T>::insert(T value, int index) {
    if (index ==0)
    {
        push_front(value);
    }
    else
    {
        Node<T> *previous = this->head;
        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }
        //Node<T> *newNode = new Node<T>(value, previous->pNext) ;
        //previous->pNext = newNode;
        previous->pNext = new Node<T>(value, previous->pNext);
        Size++;
    }
}

template<typename T>
void List<T>::removeAt(int index) {
    if (index ==0)
    {
        pop_front();
    }
    else
    {
        Node<T> *previous = this->head;
        for (int i = 0; i < index - 1; i++) {
            previous = previous->pNext;
        }
        Node<T> *toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        Size--;
    }
}

template<typename T>
void List<T>::pop_back() {
    removeAt(Size-1);
}

int main()
{
    int n, c;
    cout << "Введите длинну списка: ";
    cin >> n;
    List<int> lst;

    for (int i = 0; i < n; i++){
        lst.push_back(rand()%20-16);
    }

    cout << "Вывод заполненного списка до выполнения задания " << endl;
    for (int i = 0; i < lst.GetSize(); i++){
        cout << lst[i] << "\t";
    }

    c = lst.GetSize();
    int i = 0;
    while(c)
    {
        if(lst[i] % 2 < 0)
        {
            lst.removeAt(i);
            c--;
            break;
        }
        else
            i++;

    }

    cout << endl << endl << "Вывод заполненного списка после выполнения задания " << endl;
    for (int i = 0; i < lst.GetSize(); i++){
        cout << lst[i] << "\t";
    }

    return 0;
}

