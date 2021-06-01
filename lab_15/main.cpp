#include <iostream>

using namespace std;

struct node // структура для представления узлов дерева
{
    int key; // номер вершины
    unsigned char height; // высота поддерева
    node* left; // cсылка на левого сына
    node* right; // ссылка на правого сына
    node(int k) { key = k; left = right = 0; height = 1; } //  пустая вершина без детей
};

node* avl = nullptr;

unsigned char height(node* p) // получение высоты вершины
{
    return p?p->height:0; //получим высоту следующим способом : если вершины нет, ответ 0 иначе высота поддерева этой вершины
}

int bfactor(node* p) // разность высот между сыновьями
{
    return height(p->right)-height(p->left); // вручную посчитаем разницу
}

void fixheight(node* p) // обновим высоту, если сбалансированность нарушена
{
    unsigned char hl = height(p->left); // высота левого сына
    unsigned char hr = height(p->right); // высота правого сына
    p->height = (hl>hr?hl:hr)+1; // высота вершины - это высота сына с макс высотой плюс 1
}

node* rotateright(node* p) // правый поворот вокруг p
{
    node* q = p->left;  // обменяем левого и правого сына
    p->left = q->right;
    q->right = p;
    fixheight(p); //починим дерево
    fixheight(q);
    return q;
}

node* rotateleft(node* q) // левый поворот вокруг q
{
    node* p = q->right; // обменяем правого и левого сына
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

node* balance(node* p) // балансировка узла p
{
    fixheight(p);
    if( bfactor(p)==2 ) //если левый сын сильно больше правого сделаем правый поворот
    {
        if( bfactor(p->right) < 0 )
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if( bfactor(p)==-2 ) // если правый сын сибно больше левого сделаем левый поворот
    {
        if( bfactor(p->left) > 0  )
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p; // балансировка не нужна
}

node* insert(node* p, int k) // вставка ключа k в дерево с корнем p
{
    if( !p ) return new node(k); // если дерево пустое создадим его
    if( k<p->key ) //если ключ больше вершины, вызомем это рекурсивно от левого сына
        p->left = insert(p->left,k);
    else
        p->right = insert(p->right,k); // если ключ меньше вершины, вызовем рекурсию от правго сына
    return balance(p); // отбалансируем вершину
}

node* findmin(node* p) // поиск узла с минимальным ключом в дереве p
{
    return p->left?findmin(p->left):p; //если есть левый сын, идем в него иначе ответ в этой вершине
}

node* removemin(node* p) // удаление узла с минимальным ключом из дерева p
{
    if( p->left==0 ) // если нет левого сына удалим эту вершину
        return p->right;
    p->left = removemin(p->left); // иначе идем в левого сына
    return balance(p); //балансируем дерево
}

node* remove(node* p, int k) // удаление ключа k из дерева p
{
    if( !p ) return 0; // если дерево пустое, уходим
    if( k < p->key ) //если элемент меньше вершины идем в левого сына
        p->left = remove(p->left,k);
    else if( k > p->key )
        p->right = remove(p->right,k);  // если элемент больше вершины, идем в правого сына
    else //  мы пришли в вершину, которую надо удалить
    {
        node* q = p->left;
        node* r = p->right;
        delete p; //удалим физически эту вершину
        if( !r ) return q;
        node* min = findmin(r);
        min->right = removemin(r); //правый сын минимальной вершины - это правое поддерево удаляемой без минимума
        min->left = q; // левый сын минимальной вершины - левый сын удаляемой
        return balance(min); // балансируем меньшую вершину
    }
    return balance(p); // мы ничего не нашли, балансируем дерево
}

void printTree(node* p, int l) {
    int i;
    if (p != nullptr) {
        printTree(p->right, l + 1);
        for (i = 0; i < l; i++)
            cout << "    ";
        cout << " " << p->key;
        printTree(p->left, l + 1);
    }
    else
        cout << endl;
}

int main() {
    int h;
    cout << "Введите высоту дерева: ";
    cin >> h;
    while (h){
        int k =rand()%10-5;
        avl = insert(avl,k);
        h--;
        cout << k << endl;
    };

    printTree(avl,0);


}
