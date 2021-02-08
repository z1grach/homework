#include <iostream>

using namespace std;

int main()
{
//Ex.1
    int a=10, b=-1;
    if(((a+b)>=10) && ((a+b)<=20))
        cout << "True\n";
    else cout << "False\n";

//Ex.2
    int num, counter=0;
    cin >> num;
    if(num==2)
        cout << num << " - prostoe\n";

    for(int i=2; i<num; i++){
        if(num%i==0){
            cout << num << " - ne prostoe\n";
            break;
        }

        if(i==num-1)
            cout << num << " - prostoe\n";
    }

//Ex.3
    const int x=9, y=2;
    if ((x==10 && y==10) || ((x+y)==10))
        cout << "True\n";
    else cout << "False\n";

//Ex.4
    int vis=2124;
    if( (vis%4==0) && ((vis%100!=0) || (vis%400==0)) )
        cout << "God visokosniy\n";
    else cout << "God ne visokosniy\n";

    return 0;
}
