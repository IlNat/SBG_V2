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

    // Серии очков пользователя и компьютера.
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
    string messageOfUserAttackStatus;
    string messageOfComputerAttackStatus;
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

        cout << messageOfUserAttackStatus;
        cout << messageOfComputerAttackStatus;

        if (messageOfShipStatus != "0")
            cout << messageOfShipStatus;

        makeNextMove(isPlayerMove, userField, computerField, emptyComputerField, messageOfUserAttackStatus, messageOfComputerAttackStatus, userScoreStreak, computerScoreStreak, userStreak, computerStreak);
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

    delete[] userShips;
    delete[] computerShips;

    userField.~Field();
    computerField.~Field();
    emptyComputerField.~Field();
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
        cout << "Список команд:\n1 - начать игру;\n2 - показать правила игры;\n3 - выйти из игры.\nВведите команду: ";
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
            cout << "Изначально игрок расставляет корабли по своим координатам. Всего 10 кораблей, из них: \n1--Четырёхпалубный\n2-----Трёхпалубных\n3-----Двухпалубных\n4-----Однопалубных\n";
            cout << "Корабли не должны соприкасаться между собой вплотную и наискосок.\n";
            cout << "После расстановки кораблей Вы должны будете начать битву. Введите координаты по осям X и Y от 1-го до 10-ти для атаки.\n";
            cout << "Если Вы или Ваш противник попал по чьему-то кораблю, то игроку или компьютеру будет доступен ход пока не промахнётся.\n";
            cout << "Если Вы или Ваш противник 2 раза подряд попал по чьему-то кораблю, то ему будет доступна первая серия очков \"Авиаудар\", принцип дейтсвия достаточно прост,\n";
            cout << "Вам необходимо будет назначить пролёт по вертикали или горизонтали, дальше пилот сделает своё дело.\n";
            cout << "Тот самый выбранный пролёт будет атакован и все ячейки пролёта будут заменены на противоположные знаки(Ничего -> Промах; Корабль -> Попадание).\n";
            cout << "Существует ещё одна серия очков - \"Бомбардировка\", она даётся за 3 попадания подряд.\n";
            cout << "Назначьте координаты, но будьте внимательны! Бомбардировка не бъёт по крайним полям! Назначить можно удар по осям X и Y от 2-х ло 9-ти.\n";
            cout << "Но главная задача игры - уничтожить корабли противника, пока тот не уничтожит Ваши.\n";
            cout << "Удачи!\n";
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
