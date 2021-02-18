#include <iostream>
#define DIAPOZON(x,y) ((((x) >= 0) && ((x) < (y))) ? 1 : 0)
#define PRINT(array, x, y) std::cout << *(*((array)+(x))+(y)) << std::endl
#define SIZE(array, type) std::cout << ((sizeof(array)) / (sizeof(type))) << std::endl

int main()
{
//Ex.1
    int a=1;
    int b=2;

    if(DIAPOZON(a, b)==1)
        std::cout << "True\n";
    else
        std::cout << "False\n";

//Ex.2
    int **arr;
    arr=new int* [3];
    for(int i=0; i<3; i++)
        arr[i]=new int [3];
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            arr[i][j]=j;

    PRINT(arr, a, b);

    for(int i=0; i<3; i++)
        delete []arr[i];
    delete [] arr;

//Ex.3

    char mas[6];

    SIZE(mas, char);

    return 0;
}
