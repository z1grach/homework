#include <iostream>
#include <windows.h>
#define POINT_ARRAY(array, y, x) *(*((array)+(y))+(x))
#define CHK_DOT(x, sz) ((x) >= 0 && (x) < (sz))

enum tictactoe { Krestik = 'X', Nolik = '0', Empty = '_' };

typedef struct
{
    int szY;
    int szX;
    int towin;
    tictactoe **map;
}Field;

void setValue(tictactoe** map, const int row, const int col, tictactoe value)
{
   POINT_ARRAY(map, row, col) = value;
}

char getValue(tictactoe** map, const int row, const int col)
{
    return POINT_ARRAY(map, row, col);
}

int isValid(Field& field, int x, int y)
{
    return CHK_DOT(x, field.szX) && CHK_DOT(y, field.szY);
}

int isEmpty(Field& field, int x, int y)
{
    return getValue(field.map, y, x) == Empty;
}

void init(Field& field)
{
    field.towin = 3;
    field.szY = 3;
    field.szX = 3;
    field.map = new tictactoe * [field.szY];
    for (int i = 0; i < field.szY; i++) {
        *(field.map + i) = new tictactoe[field.szX];
    }
    for (int y = 0; y < field.szY; y++) {
        for (int x = 0; x < field.szX; x++) {
                POINT_ARRAY(field.map, y, x)=Empty;

        }
    }
}

void print(Field& field)
{
    system("cls");
    std::cout << "-1-2-3-\n";
    for (int y = 0; y < field.szY; y++) {
        std::cout << y+1;
        for (int x = 0; x < field.szX; x++) {
            printf ("%c|", POINT_ARRAY(field.map, y, x));
        }
        std::cout << '\n';
    }
}

int lineChk(Field &field, int y, int x, int vx, int vy, int len, tictactoe c)
{
   const int endx = x + (len - 1) * vx;
   const int endy = y + (len - 1) * vy;
   if (!isValid(field, endx, endy))
       return 0;
   for (int i = 0; i < len; i++)
       if (getValue(field.map, (y + i * vy), (x + i * vx)) != c)
           return 0;
   return 1;
}

int winChk(Field &field, tictactoe c)
{
   for (int y = 0; y < field.szX; y++) {
       for (int x = 0; x < field.szY; x++) {
           if (lineChk(field, y, x, 1, 0, field.towin, c)) return 1;
           if (lineChk(field, y, x, 1, 1, field.towin, c)) return 1;
           if (lineChk(field, y, x, 0, 1, field.towin, c)) return 1;
           if (lineChk(field, y, x, 1, -1, field.towin, c)) return 1;
       }
   }
   return 0;
}

void moveX(Field &field)
{
    int y, x;
    do{
        std::cout << "Which cell do you want to put \"X\"?\nWrite Y and X.\n";
        std::cin >> y >> x;
        --y; --x;
    }while((!isValid(field, x, y)) && (!isEmpty(field, x, y)));
    POINT_ARRAY(field.map, y, x)=Krestik;
}

void move0(Field &field)
{
    int y, x;
    do{
        std::cout << "Which cell do you want to put \"0\"?\nWrite Y and X.\n";
        std::cin >> y >> x;
        --y; --x;
    }while((!isValid(field, x, y)) && (!isEmpty(field, x, y)));
    POINT_ARRAY(field.map, y, x)=Nolik;
}

int isDraw(Field &field)
{
   for (int y = 0; y < field.szY; y++)
       for (int x = 0; x < field.szX; x++)
           if (isEmpty(field, x, y))
               return 0;
   return 1;
}

void cicl()
{
    Field field;

    init(field);
    print(field);
    while (true) {
           if(isDraw(field)){
                std::cout << "Is DRAW!\n";
                break;
           }
           moveX(field);
           print(field);
           if(winChk(field, Krestik)){
                std::cout << "X win!\n";
                break;
           }

           if(isDraw(field)){
                std::cout << "Is DRAW!\n";
                break;
           }
           move0(field);
           print(field);
           if (winChk(field, Nolik)){
                std::cout << "0 win!\n";
                break;
           }
    }

    for(int i=0; i<3; i++)
        delete[] field.map[i];
    delete[] field.map;
}


int main()
{
    cicl();

    return 0;
}
