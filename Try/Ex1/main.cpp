#include<iostream>

using namespace std;

int blocRec(int n)
{
    if(n<=1)
        return 1;
    return blocRec(n-1) + blocRec(n-2);
}

int main()
{
    int Q;
    cout << "Vvedite Q: ";
    cin >> Q;
    int sum = 0;
    for(int i=0;blocRec(i)<Q;i++)
    {
        printf("%d\n",blocRec(i));
        sum+=blocRec(i);
    }
    printf("sum = %d\n",sum);
    return 0;
}
