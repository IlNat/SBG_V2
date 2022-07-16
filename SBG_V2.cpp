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
    Ship* ships
)
{
    int amountOfShips = 10;
    ;
    // Расставление кораблей.
    for (int i = 0; i < amountOfShips; i++)
    {
        userField.print();
        int amountOfUnits;
        bool isVertical;
        bool flag = false;
        int intIsVertical, firstXCord, firstYCord;

        if (i == 0)
        {
            cout << "Установка четырёхпалубного корабля:\n";
            amountOfUnits = 4;
        }
        if (i == 1)
        {
            cout << "Установка первого трёхпалубного корабля:\n";
            amountOfUnits = 3;
        }
        if (i == 2)
        {
            cout << "Установка второго трёхпалубного корабля:\n";
            amountOfUnits = 3;
        }
        if (i == 3)
        {
            cout << "Установка первого двухпалубного корабля:\n";
            amountOfUnits = 2;
        }
        if (i == 4)
        {
            cout << "Установка второго двухпалубного корабля:\n";
            amountOfUnits = 2;
        }
        if (i == 5)
        {
            cout << "Установка третьего двухпалубного корабля:\n";
            amountOfUnits = 2;
        }
        if (i == 6)
        {
            cout << "Установка первого однопалубного корабля:\n";
            amountOfUnits = 1;
        }
        if (i == 7)
        {
            cout << "Установка второго однопалубного корабля:\n";
            amountOfUnits = 1;
        }
        if (i == 8)
        {
            cout << "Установка третьего однопалубного корабля:\n";
            amountOfUnits = 1;
        }
        if (i == 9)
        {
            cout << "Установка четвёртого однопалубного корабля:\n";
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
            if (!flag || firstXCord < 0 || firstXCord > 9 || firstYCord < 0 || firstYCord > 9)
                cout << "Неправильно введены координаты, повторите ввод.\n";
        } while (!flag || firstXCord < 0 || firstXCord > 9 || firstYCord < 0 || firstYCord > 9);

        ships[i].setShip(firstXCord, firstYCord, isVertical);
        
    }
}

void setComputerShips
(
    Field& computerField,
    Ship* computerShips
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
        cout << "Введите координаты для атаки по X и по Y(от 1-го до 10-ти): \n";
        cin >> XCord >> YCord;
        XCord--;
        YCord--;
        if (emptyComputerField.returnSign(XCord, YCord) != NOTHING || XCord < 0 || XCord > 9 || YCord < 0 || YCord > 9)
            cout << "Введите другие координаты.\n";
    } while (emptyComputerField.returnSign(XCord, YCord) != NOTHING || XCord > 9 || XCord < 0 || YCord < 0 || YCord > 9);
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

void checkShips
(
    int& amountOfAliveUserShips,
    int& amountOfAliveComputerShips,
    int amountOfShips,
    Ship* userShips,
    Ship* computerShips
)
{

    for (int i = 0; i < amountOfShips; i++)
    {
        if (userShips[i].returnStatusIsDestroyed() && !userShips[i].returnStatusIsChecked())
        {
            if (i == 0)
                cout << "Ваш четырёхпалубный корабль потоплен.\n";
            else if (i == 1 || i == 2)
                cout << "Ваш трёхпалубный корабль потоплен.\n";
            else if (i > 2 && i < 6)
                cout << "Ваш двухпалубный корабль потоплен.\n";
            else
                cout << "Ваш однопалубный корабль потоплен.\n";
            userShips[i].checkDestroyedShip();
            amountOfAliveUserShips--;
        }
        if (computerShips[i].returnStatusIsDestroyed() && !computerShips[i].returnStatusIsChecked())
        {
            if (i == 0)
                cout << "Четырёхпалубный корабль противника потоплен.\n";
            else if (i == 1 || i == 2)
                cout << "Трёхпалубный корабль противника потоплен.\n";
            else if (i > 2 && i < 6)
                cout << "Двухпалубный корабль противника потоплен.\n";
            else
                cout << "Однопалубный корабль противника потоплен.\n";
            computerShips[i].checkDestroyedShip();
            amountOfAliveComputerShips--;
        }
    }
}

void game()
{
    const int amountOfShips = 10;
    int amountOfAliveUserShips = 10;
    int amountOfAliveComputerShips = 10;
    bool isPlayerMove = true;

    // Поля игрока, компьютера.
    Field userField;
    Field computerField;
    Field emptyComputerField;

    Ship* userShips = new Ship[amountOfShips]
    {
        {4, userField},
        {3, userField},
        {3, userField},
        {2, userField},
        {2, userField},
        {2, userField},
        {1, userField},
        {1, userField},
        {1, userField},
        {1, userField}
    };

    Ship* computerShips = new Ship[amountOfShips]
    {
        {4, userField},
        {3, userField},
        {3, userField},
        {2, userField},
        {2, userField},
        {2, userField},
        {1, userField},
        {1, userField},
        {1, userField},
        {1, userField}
    };

    setUserShips
    (
        userField,
        userShips
    );

    setComputerShips
    (
        computerField,
        computerShips
    );

    do
    {
        cout << "Поле противника:\n";
        emptyComputerField.print();
        
        cout << "Ваше поле:\n";
        userField.print();

        makeNextMove(isPlayerMove, userField, computerField, emptyComputerField);

    } while (amountOfAliveComputerShips != 0 && amountOfAliveUserShips != 0);
    if (amountOfAliveComputerShips == 0 && amountOfAliveUserShips == 0)
        cout << "Игра окончена! Ничья!\n";
    else if (amountOfAliveComputerShips == 0)
        cout << "Игра окончена! Победитель: Игрок!\n";
    else if (amountOfAliveUserShips == 0)
        cout << "Игра окончена! Победитель: Компьютер!\n";
    else
        cout << "ошиБка. всо плоха\n";
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
    return 0;
}
