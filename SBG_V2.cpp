﻿#include <iostream>
#include "Field.h"
using namespace std;

class FourDeckedShip
{ 
private:
    char* firstUnit;
    char* secondUnit;
    char* thirdUnit;
    char* forthUnit;
    bool isDestroyed;
public:
    void setShip()
    {
        cout << "Как расположить корабль: вертикально(1) или горизонтально(0): ";
        bool isVertical;
        int input;
        do {
            cin >> input;
            if (input != 1 && input != 0)
                cout << "Неправильный введён. Повторите ввод.\n";
        } while (input != 1 && input != 0);
        isVertical = input;
        int firstXCord;
        int firstYCord;
        cout << "Введите начальную координату(X и Y): ";
        cin >> firstXCord >> firstYCord;
        // Проверка на расположение... Цикл, пока расположение не будет удачным.
    }
};


int main()
{

    cout << "Hello World!\n";
    Field userField;
    Field computerField;
    Field emptyComputerField;
}