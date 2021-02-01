#include <iostream>

using namespace std;

enum tictactoe {Nolik, Krestik};

typedef struct {
   enum tictactoe game[3][3];
   } Field;


int main()
{
    int i=0, j=0; // Ex.1 and 4
    float f=2.2;  // Ex.1
    char c='A';   // Ex.1



//Визуально 4 задание

    Field symbol;

    symbol.game[0][0]=Nolik;
    symbol.game[0][1]=Krestik;
    symbol.game[0][2]=Krestik;
    symbol.game[1][0]=Krestik;
    symbol.game[1][1]=Krestik;
    symbol.game[1][2]=Nolik;
    symbol.game[2][0]=Nolik;
    symbol.game[2][1]=Nolik;
    symbol.game[2][2]=Krestik;

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(symbol.game[i][j]==0)
                cout << '0';
            else
                cout << 'X';
        }
        cout << '\n';
    }

    return 0;
}
