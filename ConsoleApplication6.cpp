#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void NUM1(int num, string& snum)
{
    if (num % 2 == 0)
    {
        snum += "0";
    }
    else
    {
        snum += "1";
    }

    if ((num / 2) != 0)
    {
        NUM1(num / 2, snum);
    }
    else
    {
        return;
    }
}

int NUM21(int base, int exp)
{
    if (exp == 0)
    {
        return 1;
    }

    if (exp == 1)
    {
        return base;
    }

    else
    {
        return(base * NUM21(base, exp - 1));
    }
        
}

int NUM22(int base, int exp)
{
    if (exp == 0)
    {
        return 1;
    }
        
    if (exp == 1)
    {
        return base;
    }

    if (exp % 2 == 0)
    {
        int res = NUM22(base, exp / 2);
        return res * res;
    }
    else
    {
        return NUM22(base, exp - 1) * base;
    }
}

const int x = 5;
const int y = 5;
int board[x][y];

bool checkBoard(int i, int j)
{
    if (board[i][j] == 1)
    {
        return false;
    }
        
    else
    {
        return true;
    }
       
}


int NUM3(int x, int y)
{
    if (x == 0 && y == 0)
    {
        return 0;
    }
    else if (x == 0 ^ y == 0)
    {
        return 1;
    }

    else if (checkBoard(x, y) == true)
    {
        return NUM3(x, y - 1) + NUM3(x - 1, y);
    }
        
    else
    {
        return 0;
    }   
}


int main()
{
    //==================EX.1================================
    setlocale(LC_ALL, "Russian");
    string binary;
    int decNum;
    cout << "Введите цифру: ";
    cin >> decNum;
    NUM1(decNum, binary);
    reverse(binary.begin(), binary.end());
    cout << "Бинарная: " << binary << endl << endl;

    //======================================================

    //==================EX.2.1==============================

    int base, exp;
    cout << "Введите базовый номер: ";
    cin >> base;
    cout << "Введите номер экспонента: ";
    cin >> exp;
    cout << "Результат: " << NUM21(base, exp) << endl << endl;

    //======================================================

    //==================EX.2.2==============================

    cout << "Result is: " << NUM22(base, exp) << endl << endl;

    //======================================================

    //==================EX.3================================
    board[0][0] = 0;

    board[1][3] = 1;
    board[2][3] = 1;
    board[4][1] = 1;
    board[2][1] = 1;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    };

    cout << endl;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cout << NUM3(i, j) << " ";
        }
        cout << endl << endl;
    }
    //======================================================
}
