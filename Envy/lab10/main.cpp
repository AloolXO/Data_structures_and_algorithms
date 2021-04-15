#include <iostream>
using namespace std;

struct CTPYKTYPA {
    int data;
    CTPYKTYPA* next;
};

/*void joker(CTPYKTYPA* head, int v)
{
    CTPYKTYPA *Current = head;
    auto *Item = new (CTPYKTYPA);
    Item->data = v;
    Item->next = nullptr;

    if (head->data % 2 == 0) {

        Item->next = head;
        head = Item;

        // это легко, поэтому я это не делал.
    }
    else {
        while (Current->next != nullptr) // смотрим на то , чтобы ссылка была не пустой, в противном случа выполняется оставшееся...
            Current = Current->next;
        Item->data = v;
        Item->next = nullptr;
        Current->next = Item;
    }
}*/
/*void Finder(CTPYKTYPA* head, int data, int n) {
	CTPYKTYPA* toDelete;
	CTPYKTYPA* Current = head;
	while (Current != NULL) {
		toDelete = Current->next;
		if (Current->data == data) {
			Current->data = toDelete->data;
			Current->next = toDelete->next;
			delete toDelete;
		}
		Current = Current->next;
	}
}*/
/*void poisk (int k, CTPYKTYPA* head){
	CTPYKTYPA* current = head;

	while (current->next != k)


	if (current != NULL) {
		current = current->next;
		if (current->data == k);

		pishy_chto_hochu(head->next);
	}
};*/

void pishy_chto_hochu(CTPYKTYPA * head)
{
    if (head != nullptr) {
        cout << head->data << "\t";
        pishy_chto_hochu(head->next);
    }
    else cout << "\n";
}


/*int pishy_chto_hochu(CTPYKTYPA* head)
{
	if (head != NULL)
	{
		if (head->data != 0)
			int s += head->data;
		pishy_chto_hochu(head->next);
	}
	return s;
}*/



int main()
{
    int n=0, s=0;
    setlocale(LC_ALL, "RUS");
    CTPYKTYPA *head = nullptr;
    head = new CTPYKTYPA;
    head->data = rand()%1000-500;
    head->next = nullptr;
    CTPYKTYPA* k = head;



    cout << "Введите длинну списка : ";
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        k->next = new CTPYKTYPA;
        k = k->next;
        k->data = rand()%1000-500;
        k->next = nullptr;
        /*if (head->data != 0)
            s += k->data;*/
    }
    pishy_chto_hochu(head);
    cout << "\n" << "Введите желаемое число : ";
    cin >> s;
    //joker(head, s);
    CTPYKTYPA* Current = head;
    auto* Item = new CTPYKTYPA;
    Item->data = s;
    Item->next = nullptr;

    if (s % 2 == 0) {

        Item->next = head;
        head = Item;
        // это легко, поэтому я это не делал.



    }
    else {
        while (Current->next != nullptr) // смотрим на то , чтобы ссылка была не пустой, в противном случа выполняется оставшееся...
            Current = Current->next;

        Current->next = Item;

    }

    pishy_chto_hochu(head);
    /*cout << "\n"<<"Введите ненужное число : ";
    cin >> s;
    Finder(head,s,n);
    pishy_chto_hochu(head);*/
    /*cout << "\n" << "\n" << "\n" << s <<" Сумма не нулевых элементов."<< "\n" << "\n" << "\n";*/








}


