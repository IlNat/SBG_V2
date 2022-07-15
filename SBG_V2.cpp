#include <iostream>
#include <Windows.h>
#include "Field.h"
#include "Ship.h"
using namespace std;

/*
void setUserShips(
Ship& userFirstFourDeckedShip,
Ship& userFirstThreeDeckedShip,
Ship& userSecondThreeDeckedShip,
Ship& userFirstTwoDeckedShip,
Ship& userSecondTwoDeckedShip,
Ship& userThirdTwoDeckedShip,
Ship& userFirstOneDeckedShip,
Ship& userSecondOneDeckedShip,
Ship& userThirdOneDeckedShip,
Ship& userFourthOneDeckedShip)
{
    int amountOfShips = 10;
    // Расставление кораблей.
    for (int i = 1; i <= amountOfShips; i++)
    {
        if (i == 1)
            userFirstFourDeckedShip.setShip();
        if (i == 2)
            userFirstThreeDeckedShip.setShip();
        if (i == 3)
            userSecondThreeDeckedShip.setShip();
        if (i == 4)
            userFirstTwoDeckedShip.setShip();
        if (i == 5)
            userSecondTwoDeckedShip.setShip();
        if (i == 6)
            userThirdTwoDeckedShip.setShip();
        if (i == 7)
            userFirstOneDeckedShip.setShip();
        if (i == 8)
            userSecondOneDeckedShip.setShip();
        if (i == 9)
            userThirdOneDeckedShip.setShip();
        if (i == 10)
            userFourthOneDeckedShip.setShip();
    }
}
*/



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Hello World!\n";

    // Поля игрока, компьютера
    Field userField;
    Field computerField;
    Field emptyComputerField;

    Ship userFirstFourDeckedShip(4, userField);
    Ship userFirstThreeDeckedShip(3, userField);
    Ship userSecondThreeDeckedShip(3, userField);
    Ship userFirstTwoDeckedShip(2, userField);
    Ship userSecondTwoDeckedShip(2, userField);
    Ship userThirdTwoDeckedShip(2, userField);
    Ship userFirstOneDeckedShip(1, userField);
    Ship userSecondOneDeckedShip(1, userField);
    Ship userThirdOneDeckedShip(1, userField);
    Ship userFourthOneDeckedShip(1, userField);
    
    Ship compFirstFourDeckedShip(4, computerField);
    Ship compFirstThreeDeckedShip(3, computerField);
    Ship compSecondThreeDeckedShip(3, computerField);
    Ship compFirstTwoDeckedShip(2, computerField);
    Ship compSecondTwoDeckedShip(2, computerField);
    Ship compThirdTwoDeckedShip(2, computerField);
    Ship compFirstOneDeckedShip(1, computerField);
    Ship compSecondOneDeckedShip(1, computerField);
    Ship compThirdOneDeckedShip(1, computerField);
    Ship compFourthOneDeckedShip(1, computerField);

    int amountOfShips = 10;
    // Расставление кораблей.
    for (int i = 1; i <= amountOfShips; i++)
    {
        int amountOfUnits;
        bool isVertical;
        bool flag = false;
        int intIsVertical, firstXCord, firstYCord;

        if (i == 1)
        {
            cout << "Установка четырёхпалубного корабля: ";
            amountOfUnits = 4;
        }
        if (i == 2)
        {
            cout << "Установка первого трёхпалубного корабля: ";
            amountOfUnits = 3;
        }
        if (i == 3)
        {
            cout << "Установка второго трёхпалубного корабля: ";
            amountOfUnits = 3;
        }
        if (i == 4)
        {
            cout << "Установка первого двухпалубного корабля: ";
            amountOfUnits = 2;
        }
        if (i == 5)
        {
            cout << "Установка второго двухпалубного корабля: ";
            amountOfUnits = 2;
        }
        if (i == 6)
        {
            cout << "Установка третьего двухпалубного корабля: ";
            amountOfUnits = 2;
        }
        if (i == 7)
        {
            cout << "Установка первого однопалубного корабля: ";
            amountOfUnits = 1;
        }
        if (i == 8)
        {
            cout << "Установка второго однопалубного корабля: ";
            amountOfUnits = 1;
        }
        if (i == 9)
        {
            cout << "Установка третьего однопалубного корабля: ";
            amountOfUnits = 1;
        }
        if (i == 10)
        {
            cout << "Установка четвёртого однопалубного корабля: ";
            amountOfUnits = 1;
        }

        do 
        {
            cout << "Как расположить корабль?\n 1 - вертикально; 2 - горизонтально: ";
            cin >> intIsVertical;

            if (intIsVertical != 1 && intIsVertical != 2)
                cout << "Неправильные введённые данные, повторите ввод.\n";
        } while (intIsVertical != 1 && intIsVertical != 2);

        if (intIsVertical == 1)
            isVertical = true;
        else
            isVertical = false;

        do
        {
            cout << "Введите первые координаты по X и по Y(от 1-го до 10-ти): ";
            cin >> firstXCord >> firstYCord;
            firstXCord--;
            firstYCord--;
            flag = userField.isAvailable(firstXCord, firstYCord, amountOfUnits, isVertical);
            if (!flag)
                cout << "Неправильно введены координаты, повторите ввод.\n";
        } while (!flag);
        
        if (i == 1)
            userFirstFourDeckedShip.setShip(firstXCord, firstYCord, amountOfUnits, isVertical);
        if (i == 2)
            userFirstThreeDeckedShip.setShip(firstXCord, firstYCord, amountOfUnits, isVertical);
        if (i == 3)
            userSecondThreeDeckedShip.setShip(firstXCord, firstYCord, amountOfUnits, isVertical);
        if (i == 4)
            userFirstTwoDeckedShip.setShip(firstXCord, firstYCord, amountOfUnits, isVertical);
        if (i == 5)
            userSecondTwoDeckedShip.setShip(firstXCord, firstYCord, amountOfUnits, isVertical);
        if (i == 6)
            userThirdTwoDeckedShip.setShip(firstXCord, firstYCord, amountOfUnits, isVertical);
        if (i == 7)
            userFirstOneDeckedShip.setShip(firstXCord, firstYCord, amountOfUnits, isVertical);
        if (i == 8)
            userSecondOneDeckedShip.setShip(firstXCord, firstYCord, amountOfUnits, isVertical);
        if (i == 9)
            userThirdOneDeckedShip.setShip(firstXCord, firstYCord, amountOfUnits, isVertical);
        if (i == 10)
            userFourthOneDeckedShip.setShip(firstXCord, firstYCord, amountOfUnits, isVertical);
    }


}
