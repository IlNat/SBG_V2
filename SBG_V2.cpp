#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "Field.h"
#include "Ship.h"
using namespace std;

//const int size = 10;
enum { SHIP = '*', HIT = '+', MISS = '-', NOTHING = '#' };

void setUserShips
(
    Field& userField,
    Ship& userFirstFourDeckedShip,
    Ship& userFirstThreeDeckedShip,
    Ship& userSecondThreeDeckedShip,
    Ship& userFirstTwoDeckedShip,
    Ship& userSecondTwoDeckedShip,
    Ship& userThirdTwoDeckedShip,
    Ship& userFirstOneDeckedShip,
    Ship& userSecondOneDeckedShip,
    Ship& userThirdOneDeckedShip,
    Ship& userFourthOneDeckedShip
)
{
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
            flag = userField.checkForAvailability(firstXCord, firstYCord, amountOfUnits, isVertical);
            if (!flag)
                cout << "Неправильно введены координаты, повторите ввод.\n";
        } while (!flag);

        if (i == 1)
            userFirstFourDeckedShip.setShip(firstXCord, firstYCord, isVertical);
        if (i == 2)
            userFirstThreeDeckedShip.setShip(firstXCord, firstYCord, isVertical);
        if (i == 3)
            userSecondThreeDeckedShip.setShip(firstXCord, firstYCord, isVertical);
        if (i == 4)
            userFirstTwoDeckedShip.setShip(firstXCord, firstYCord, isVertical);
        if (i == 5)
            userSecondTwoDeckedShip.setShip(firstXCord, firstYCord, isVertical);
        if (i == 6)
            userThirdTwoDeckedShip.setShip(firstXCord, firstYCord, isVertical);
        if (i == 7)
            userFirstOneDeckedShip.setShip(firstXCord, firstYCord, isVertical);
        if (i == 8)
            userSecondOneDeckedShip.setShip(firstXCord, firstYCord, isVertical);
        if (i == 9)
            userThirdOneDeckedShip.setShip(firstXCord, firstYCord, isVertical);
        if (i == 10)
            userFourthOneDeckedShip.setShip(firstXCord, firstYCord, isVertical);
    }
}

void setComputerShips
(
    Field& computerField,
    Ship& compFirstFourDeckedShip,
    Ship& compFirstThreeDeckedShip,
    Ship& compSecondThreeDeckedShip,
    Ship& compFirstTwoDeckedShip,
    Ship& compSecondTwoDeckedShip,
    Ship& compThirdTwoDeckedShip,
    Ship& compFirstOneDeckedShip,
    Ship& compSecondOneDeckedShip,
    Ship& compThirdOneDeckedShip,
    Ship& compFourthOneDeckedShip
)
{

}

void copyKnownPlaces(Field& computerField, Field& emptyComputerField)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            char sign = computerField.returnSign(i, j);
            if (sign != SHIP)
                emptyComputerField.setUnit(sign, i, j);
        }
    }
}

int computerAttack(Field& userField)
{
    
    int XCord, YCord;
    char sign;
    do
    {
        XCord = rand() & 10;
        YCord = rand() & 10;
        sign = userField.returnSign(XCord, YCord);
    } while (sign != NOTHING && sign != SHIP);
    if (sign == SHIP) 
    {
        userField.setUnit(HIT, XCord, YCord);
        return 1;
    }
    else
    {
        userField.setUnit(MISS, XCord, YCord);
        return 0;
    }
}

int userAttack(Field& computerField, Field& emptyComputerField)
{
    int XCord, YCord;
    do
    {
        cout << "Введите координаты для атаки (x [от 1 до 10]; y [от 1 до 10]): \n";
        cin >> XCord >> YCord;
        XCord--;
        YCord--;
        if (emptyComputerField.returnSign(XCord, YCord) != NOTHING || XCord < 0 || XCord > 9 || YCord < 0 || YCord > 9)
            cout << "Введите другие координаты.\n";
    } while (emptyComputerField.returnSign(XCord, YCord) != NOTHING && XCord > 9 && XCord < 0 && YCord < 0 && YCord > 9);
    if (computerField.returnSign(XCord, YCord) == NOTHING)
    {
        cout << "Промах.\n";
        computerField.setUnit(MISS, XCord, YCord);
        return 0;
    }
    if (computerField.returnSign(XCord, YCord) == SHIP)
    {
        cout << "Попадание.\n";
        computerField.setUnit(HIT, XCord, YCord);
        return 1;
    }
    copyKnownPlaces(computerField, emptyComputerField);
}

void makeNextMove(bool& isPlayerMove, Field& userField,Field& computerField, Field& emptyComputerField)
{
    if (isPlayerMove)
    {
        if (userAttack(computerField, emptyComputerField) == 0)
            !isPlayerMove;
    }
    else
    {
        if (computerAttack(userField) == 1)
            !isPlayerMove;
    }
}

bool gameOver()
{
    
}

void game()
{
    bool isPlayerMove = true;

    // Поля игрока, компьютера.
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

    setUserShips
    (
        userField,
        userFirstFourDeckedShip,
        userFirstThreeDeckedShip,
        userSecondThreeDeckedShip,
        userFirstTwoDeckedShip,
        userSecondTwoDeckedShip,
        userThirdTwoDeckedShip,
        userFirstOneDeckedShip,
        userSecondOneDeckedShip,
        userThirdOneDeckedShip,
        userFourthOneDeckedShip
    );

    setComputerShips
    (
        computerField,
        compFirstFourDeckedShip,
        compFirstThreeDeckedShip,
        compSecondThreeDeckedShip,
        compFirstTwoDeckedShip,
        compSecondTwoDeckedShip,
        compThirdTwoDeckedShip,
        compFirstOneDeckedShip,
        compSecondOneDeckedShip,
        compThirdOneDeckedShip,
        compFourthOneDeckedShip
    );

    do
    {
        cout << "Поле противника:\n";
        emptyComputerField.print();
        
        cout << "Ваше поле:\n";
        userField.print();
    } while (!gameOver);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));
    cout << "Hello World!\n";
    cout << "Добро пожаловать в игру \"Морской бой\"!\n";
    int choice;
    do {
        cout << "Список команд:\n1 - начать игру;\n2 - показать правила игры;\n3 - выйти из игры.\n Введите команду: ";
        cin >> choice;
        switch (choice) 
        {
        case 1:
        {
            cout << "Запуск игры.\n";
            game();
            break;
        }
        case 2:
        {
            cout << "Правила игры:\n";
            // < Правила игры. >
            break;
        }
        case 3:
        {
            cout << "Выход из игры.\n";
            break;
        }
        default:
        {
            cout << "Такой команды нет, повторите ввод.\n";
            break;
        }
        }
    } while (choice != 3);
}
