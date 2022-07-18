#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>
#include "Field.h"
#include "Ship.h"
#include "SBG_V2_script.h"
using namespace std;

void game()
{
    system("cls");
    const int amountOfShips = 10;
    int amountOfAliveUserShips = 10;
    int amountOfAliveComputerShips = 10;
    int userStreak = 0;
    int computerStreak = 0;
    bool isPlayerMove = true;

    // Поля игрока, компьютера.
    Field userField;
    Field computerField;
    Field emptyComputerField;

    ScoreStreak userScoreStreak(computerField);
    ScoreStreak computerScoreStreak(userField);

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
        {4, computerField},
        {3, computerField},
        {3, computerField},
        {2, computerField},
        {2, computerField},
        {2, computerField},
        {1, computerField},
        {1, computerField},
        {1, computerField},
        {1, computerField}
    };

    setComputerShips(computerField, computerShips);
    
    setUserShips(userField, userShips);

     
    computerField.print();
    cout << endl;
    
    string messageOfShipStatus;
    string messageOfAttackStatus;
    do
    {
        system("cls");
        if (isPlayerMove)
        {
            cout << "Поле противника:\n";
            emptyComputerField.print();

            cout << "Ваше поле:\n";
            userField.print();
        }

        cout << messageOfAttackStatus;

        if (messageOfShipStatus != "0")
            cout << messageOfShipStatus;

        makeNextMove(isPlayerMove, userField, computerField, emptyComputerField, messageOfAttackStatus, userScoreStreak, computerScoreStreak, userStreak, computerStreak);
        messageOfShipStatus = checkShips(amountOfAliveUserShips, amountOfAliveComputerShips, amountOfShips, userShips, computerShips);

        if (userStreak == 2)
        {
            cout << "Вам доступен авиаудар!\n";
            userScoreStreak.increaseAmountOfGunRun();
        }
        
        if (userStreak == 3)
        {
            cout << "Вам доступна бомбардировка!\n";
            userScoreStreak.increaseAmountOfBomberRun();
        }

        if (computerStreak == 2)
            computerScoreStreak.increaseAmountOfGunRun();
        
        if (computerStreak == 3)
            computerScoreStreak.increaseAmountOfBomberRun();

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
    //cout << "Hello World!\n";
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
