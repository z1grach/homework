#include <iostream>
#include "HomeWork.h"
#define N 5

using namespace std;
using namespace lesson;


int main()
{
//Ex.1
    int mas1[5]={0,1,0,1,1};
    for (int i=0; i<5; i++)
        mas1[i]=(mas1[i]==0) ? mas1[i]=1 : mas1[i]=0;

//Ex.2
    int mas2[8];
    exercise2(mas2);
    for(int i=0; i<8; i++)
        cout << mas2[i] << ' ';
    cout << "\n\n\n";

//Ex.3
    int checkBalance[N]={1, 1, 1, 2, 1};
    exercise3(checkBalance);

//Ex.4
    int mas4[N]={1, 2, 3, 4, 5};
    int n=-3;
    exercise4 (mas4, n);

    return 0;
}
