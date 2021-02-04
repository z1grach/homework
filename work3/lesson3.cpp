#include <iostream>
#include "HomeWork.h"

using namespace std;

int main()
{
//Ex.1 and 3
    cout << a * (b + ((float) c / d)) << endl;

//Ex.2
    int x, k;
    cout << "Enter the number\n";
    cin >> x;

    (x>21) ? cout << 2*x << " > 21\n" : cout << x << " <= 21\n";

//Ex.3
    int m[3][3][3] = {{{0,1,2}, {3,4,5}, {6,7,8}},
    {{9,10,11}, {11,12,13}, {14,15,16}},
    {{17,18,19}, {20,24,25}, {26,27,28}}
    };
    int *mPtr;
    mPtr=&m[1][1][1];

    cout << *mPtr << endl;

    return 0;
}
