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

int main()
{
    random_device rd;
    mt19937 mersenne(rd()); // инициализируем Вихрь Мерсенна случайным стартовым числом
    int n, c=0, s=0;
    cout << "Введите длинну списка: ";
    cin >> n;
    List<int> lst;

    for (int i = 0; i < n; i++){
        lst.push_back(mersenne()%1000-100);
    }

    for (int i = 0; i < n; i++){
        c += lst[i];
    }
    c /= lst.GetSize();

    for (int i = 0; i < n; i++){
        if (lst[i]<c)
          s += lst [i];
    }

    cout << "Вывод заполненного списка" << endl;
    for (int i = 0; i < n; i++){
        cout << lst[i] << "\t";
    }
    cout << endl << endl << "Сумма элементов списка, которые меньше среднего знаяения: " << s << endl << endl;

}

