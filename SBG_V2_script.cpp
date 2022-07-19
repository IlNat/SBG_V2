#include "SBG_V2_script.h"

// Установка кораблей пользователя.
void setUserShips(Field& userField, Ship* ships)
{
    int amountOfShips = 10; // Количество кораблей.

    // Расставление кораблей.
    for (int i = 0; i < amountOfShips; i++)
    {
        userField.print(); // Печать игрового поля игрока для наглядного представления доступного места.
        int amountOfUnits; // Количество палуб(ячеек).

        // Переменная "Вертикальный ли?", применимо к кораблям. По умолчанию устанавливается отрицательное значение.
        // Если корабль не однопалубный, то возможно установить его направление.
        bool isVertical = false; 

        bool flag = false; // Флаг доступности, по умолчанию присваивается отрицательное значение.
        
        // Целочисленная переменная "Вертикальный ли?", необходима для ввода. 
        // Первые координаты по осям X и Y.
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

        // Если корабль не однопалубный, то возможно установить его направление. В данном случае пользователю предлагают самому установить направление.
        if (amountOfUnits != 1)
        {
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
        }

        do
        {
            cout << "Введите первые координаты по X и по Y(от 1-го до 10-ти): ";
            cin >> firstXCord >> firstYCord;
            firstXCord--;
            firstYCord--;

            // Флаг доступности принимает значение метода класса "Field", который определяет - доступно ли место?
            flag = userField.checkForAvailability(firstXCord, firstYCord, amountOfUnits, isVertical);

            if (!flag || firstXCord < 0 || firstXCord > 9 || firstYCord < 0 || firstYCord > 9)
                cout << "Неправильно введены координаты, повторите ввод.\n";
            
        } while (!flag || firstXCord < 0 || firstXCord > 9 || firstYCord < 0 || firstYCord > 9);

        ships[i].setShip(firstXCord, firstYCord, isVertical);
    }
}

// Установка кораблей компьютера.
void setComputerShips(Field& computerField, Ship* computerShips)
{
    int amountOfShips = 10; // Количество кораблей.
    
    for (int i = 0; i < amountOfShips; i++)
    {
        // Переменная "Вертикальный ли?", применимо к кораблям. По умолчанию устанавливается отрицательное значение.
        // Если корабль не однопалубный, то возможно установить его направление.
        bool isVertical = false;

        // Флаг доступности, по умолчанию присваивается отрицательное значение.
        bool flag = false;

        // Целочисленная переменная "Вертикальный ли?", необходима для ввода. 
        // Первые координаты по осям X и Y.
        int amountOfUnits, firstXCord, firstYCord;

        if (i == 0)
            amountOfUnits = 4;
        if (i == 1 || i == 2)
            amountOfUnits = 3;
        else if (i > 2 && i < 6)
            amountOfUnits = 2;
        else
            amountOfUnits = 1;

        // Если корабль не однопалубный, то возможно установить его направление. 
        // В данном случае компьютер при помощи функции "rand()" устанавливает направление корабля.
        if (amountOfUnits != 1)
        {
            int intIsVertical = rand() % 2;
            if (intIsVertical == 1)
                isVertical = true;
            else
                isVertical = false;
        }

        do
        {
            firstXCord = rand() % 10;
            firstYCord = rand() % 10;

            // Флаг доступности принимает значение метода класса "Field", который определяет - доступно ли место?
            flag = computerField.checkForAvailability(firstXCord, firstYCord, amountOfUnits, isVertical);

        } while (!flag);
        computerShips[i].setShip(firstXCord, firstYCord, isVertical);
    }
}

// Копирование известных(все знаки, кроме знаков кораблей) мест из "computerField" в "emptyComputerField".
void copyKnownPlaces(Field& computerField, Field& emptyComputerField)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            // Переменная "Знак" запоминает символ из "computerField". 
            char sign = computerField.returnSign(i, j);
            // Если символ не "Корабль", то помещает его в "emptyComputerField".
            if (sign != SHIP)
                emptyComputerField.setUnit(sign, i, j);
        }
    }
}

// Атака компьютера. Возвращает сообщение о промахе или попадании.
int computerAttack(Field& userField, string& message, ScoreStreak& computerScoreStreak)
{
    srand(time(0));
    int XCord, YCord, outputNumber;
    char sign;
    bool useGunRun = false;
    bool useBomberRun = false;
    if (computerScoreStreak.returnAmountOfGunRun() > 0)
    {
        useGunRun = true;
        int intIsVertical = rand() % 2;
        int cord = rand() % 10;
        bool isVertical;
        
        if (intIsVertical == 1)
            isVertical = true;
        else
            isVertical = false;

        computerScoreStreak.gunRunAttack(cord, isVertical);
        outputNumber = 0;
        message = "Противник использует авиаудар!\n";
    }

    if (useGunRun = false && computerScoreStreak.returnAmountOfBomberRun() > 0)
    {
        XCord = rand() % 7 + 1;
        YCord = rand() % 7 + 1;
        computerScoreStreak.bomberRunAttack(XCord, YCord);
        outputNumber = 0;
        message = "Противник запросил бомбардировку!\n";
    }

    if (useGunRun == false && useBomberRun == false) 
    {
        do
        {
            XCord = rand() % 10;
            YCord = rand() % 10;
            sign = userField.returnSign(XCord, YCord);
        } while (sign != NOTHING && sign != SHIP);
        if (sign == SHIP)
        {
            userField.setUnit(HIT, XCord, YCord);
            message = "Противник попал по Вашим кораблям.\n";
            outputNumber = 1;
        }
        else
        {
            userField.setUnit(MISS, XCord, YCord);
            message = "Противник промахнулся.\n";
            outputNumber = 0;
        }
    }
    return outputNumber;
}

// Атака пользователя. Возвращает сообщение о промахе или попадании.
int userAttack(Field& computerField, Field& emptyComputerField, string& message, ScoreStreak& userScoreStreak)
{
    int XCord, YCord, outputNumber = 0;
    bool useGunRun = false;
    bool useBomberRun = false;
    char choice;

    if (userScoreStreak.returnAmountOfGunRun() > 0)
    {
        do
        {
            cout << "Хотите использовать авиаудар[Y/N]?\n";
            cin >> choice;
            choice = tolower((char)choice);
            if (choice != 'y' && choice != 'n')
                cout << "Повторите ввод.\n";
        } while (choice != 'y' && choice != 'n');
        if (choice == 'y')
        {
            useGunRun = true;
            int cord;
            int intIsVertical;
            bool isVertical;
            do {
                cout << "Как полетит самолёт?\n1 - по вертикали;\n2 - по горизонтали.\n";
                cin >> intIsVertical;
                if (intIsVertical != 1 && intIsVertical != 2)
                    cout << "Повторите ввод.\n";
            } while (intIsVertical != 1 && intIsVertical != 2);

            if (intIsVertical == 1)
                isVertical = true;
            else
                isVertical = false;

            do {
                cout << "По какой координате полетит самолёт(от 1-го до 10-ти)?\n";
                cin >> cord;
                cord--;
                if (cord < 0 && cord > 9)
                    cout << "Повторите ввод.\n";
            } while (cord < 0 && cord > 9);
            userScoreStreak.gunRunAttack(cord, isVertical);
            outputNumber = 0;
            message = "Бррррт!\n";
        }
    }
    if (userScoreStreak.returnAmountOfBomberRun() > 0 && useGunRun == false)
    {
        do
        {
            cout << "Хотите использовать бомбардировку[Y/N]?\n";
            cin >> choice;
            choice = tolower((char)choice);
            if (choice != 'y' && choice != 'n')
                cout << "Повторите ввод.\n";
        } while (choice != 'y' && choice != 'n');

        if (choice == 'y')
        {
            useBomberRun = true;
            do {
                cout << "По какой координате произвести бомбардировку(по осям X и Yот 2-х до 9-ти)? Бомбардировки не производятся по краям поля.\n";
                cin >> XCord >> YCord;
                XCord--;
                YCord--;
                if (XCord < 1 && XCord > 8 && YCord < 1 && YCord > 8)
                    cout << "Повторите ввод.\n";
            } while (XCord < 1 && XCord > 8 && YCord < 1 && YCord > 8);
            userScoreStreak.bomberRunAttack(XCord, YCord);
            outputNumber = 0;
            message = "Бомбы сброшены!\n";
        }
    }
    
    
    if (useGunRun == false && useBomberRun == false)
    {
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
            message = "Промах.\n";
            computerField.setUnit(MISS, XCord, YCord);
            emptyComputerField.setUnit(MISS, XCord, YCord);
            copyKnownPlaces(computerField, emptyComputerField);

            outputNumber = 0;
        }
        if (computerField.returnSign(XCord, YCord) == SHIP)
        {
            message = "Попадание.\n";
            computerField.setUnit(HIT, XCord, YCord);
            emptyComputerField.setUnit(HIT, XCord, YCord);
            copyKnownPlaces(computerField, emptyComputerField);
            outputNumber = 1;
        }
    }
    return outputNumber;
}

// Определение хода: ходит игрок или ходит компьютер. При этом вовзращает сообщение с происходящим.
void makeNextMove(bool& isPlayerMove, Field& userField, Field& computerField, Field& emptyComputerField, string& messageOfUserAttackStatus, string& messageOfComputerAttackStatus, ScoreStreak& userScoreStreak, ScoreStreak& computerScoreStreak, int& userStreak, int& computerStreak)
{
    if (isPlayerMove)
    {
        if (userAttack(computerField, emptyComputerField, messageOfUserAttackStatus, userScoreStreak) == 0)
        {
            isPlayerMove = false;
            userStreak = 0;
        }
        else
        {
            isPlayerMove = true;
            userStreak++;
        }
    }
    else
    {
        if (computerAttack(userField, messageOfComputerAttackStatus, computerScoreStreak) == 1)
        {
            isPlayerMove = false;
            computerStreak++;
        }
        else
        {
            isPlayerMove = true;
            computerStreak = 0;
        }
    }
}

// Проверка кораблей на целостность. Перебор кораблей пользователя и компьютера. 
// Если корабль уничтожен и не проверен, то вовзращает сообщение о том, чей и какой корабль уничтожен.
string checkShips(int& amountOfAliveUserShips, int& amountOfAliveComputerShips, int amountOfShips, Ship* userShips, Ship* computerShips)
{
    string message = "0";
    for (int i = 0; i < amountOfShips; i++)
    {
        if (userShips[i].returnStatusIsDestroyed() == false)
            userShips[i].checkForDestroyed();

        if (computerShips[i].returnStatusIsDestroyed() == false)
            computerShips[i].checkForDestroyed();

        if (userShips[i].returnStatusIsDestroyed() == true && userShips[i].returnStatusIsChecked() == false)
        {
            if (i == 0)
                message = "Ваш четырёхпалубный корабль потоплен.\n";
            else if (i == 1 || i == 2)
                message = "Ваш трёхпалубный корабль потоплен.\n";
            else if (i > 2 && i < 6)
                message = "Ваш двухпалубный корабль потоплен.\n";
            else
                message = "Ваш однопалубный корабль потоплен.\n";
            userShips[i].checkDestroyedShip();
            amountOfAliveUserShips--;
        }

        if (computerShips[i].returnStatusIsDestroyed() == true && computerShips[i].returnStatusIsChecked() == false)
        {
            if (i == 0)
                message = "Четырёхпалубный корабль противника потоплен.\n";
            else if (i == 1 || i == 2)
                message = "Трёхпалубный корабль противника потоплен.\n";
            else if (i > 2 && i < 6)
                message = "Двухпалубный корабль противника потоплен.\n";
            else
                message = "Однопалубный корабль противника потоплен.\n";
            computerShips[i].checkDestroyedShip();
            amountOfAliveComputerShips--;
        }
    }
    return message;
}

// Печать картинки с якорем.
void printAnchor()
{
    cout << "          .::::.\n";
    cout << "          ::  ::\n";
    cout << "          \":..:\"\n";
    cout << "            ::\n";
    cout << "      ::::::::::::::\n";
    cout << "       \"\"\"\"\"::\"\"\"\"\"\n";
    cout << "            ::\n";
    cout << "            ::\n";
    cout << "            ::\n";
    cout << " .:         ::         :.\n";
    cout << ".::.       .::.       .::.\n";
    cout << "::::       ::::       ::::\n";
    cout << " \":::.    .::::.    .:::\"\n";
    cout << "   \"::::::::::::::::::\"\n";
    cout << "      \"::::::::::::\"\n";
    cout << "         \"::::::\"\n";
    cout << "            \"\"\n";
}

// Печать картинки с ничьёй.
void printDraw()
{
    cout << " _______________________________________________________________________ \n";
    cout << "|  ___     ___   ___     ___   ___     ___   ___           ___________  |\n";
    cout << "| |   |   |   | |   |   /   | |   |   |   | |   |         |           | |\n";
    cout << "| |   |   |   | |   |  /    | |   |   |   | |   |         |    ___    | |\n";
    cout << "| |   |   |   | |   | /     | |   |___|   | |   |         |   |   |   | |\n";
    cout << "| |   |___|   | |   |/      | |           | |   |         |   |___|   | |\n";
    cout << "| |           | |           | |______     | |   |_______  |           | |\n";
    cout << "| |    ___    | |           |        |    | |    ___    | |___        | |\n";
    cout << "| |   |   |   | |      /|   |        |    | |   |   |   |    /   /|   | |\n";
    cout << "| |   |   |   | |     / |   |        |    | |   |___|   |   /   / |   | |\n";
    cout << "| |   |   |   | |    /  |   |        |    | |           |  /   /  |   | |\n";
    cout << "| |___|   |___| |___/   |___|        |____| |___________| /___/   |___| |\n";
    cout << "|_______________________________________________________________________|\n";
}

// Печать картинки с победой.
void printWin()
{
    cout << " __________________________________________________________________________________________\n";
    cout << "|  ___________    ___________    ___________    ___________      _______        _______    |\n";
    cout << "| |           |  |           |  |           |  |           |    |  ___  |      /   _   \   |\n";
    cout << "| |    ___    |  |    ___    |  |    _______|  |     ______|    | |   | |     /   / \   \  |\n";
    cout << "| |   |   |   |  |   |   |   |  |   |          |    |           | |   | |    |   |   |   | |\n";
    cout << "| |   |   |   |  |   |   |   |  |   |_______   |    |______     | |   | |    |   |   |   | |\n";
    cout << "| |   |   |   |  |   |   |   |  |           |  |           |    | |   | |    |   |___|   | |\n";
    cout << "| |   |   |   |  |   |   |   |  |    ___    |  |     ______|   _| |___| |_   |           | |\n";
    cout << "| |   |   |   |  |   |   |   |  |   |   |   |  |    |         |           |  |    ___    | |\n";
    cout << "| |   |   |   |  |   |___|   |  |   |___|   |  |    |______   |   _____   |  |   |   |   | |\n";
    cout << "| |   |   |   |  |           |  |           |  |           |  |  |     |  |  |   |   |   | |\n";
    cout << "| |___|   |___|  |___________|  |___________|  |___________|  |__|     |__|  |___|   |___| |\n";
    cout << "|__________________________________________________________________________________________|\n";
}

// Печать картинки с поражением.
void printLose()
{
    cout << " _______________________________________________________________________________________________________________________________\n";
    cout << "|  ___________   ___________   ___________     _______     __   _   __   ___________   ___     ___   ___     ___   ___________  |\n";
    cout << "| |           | |           | |           |   /   _   \   |  | | | |  | |           | |   |   |   | |   |   /   | |           | |\n";
    cout << "| |    ___    | |    ___    | |    ___    |  /   / \   \  |  | | | |  | |     ______| |   |   |   | |   |  /    | |     ______| |\n";
    cout << "| |   |   |   | |   |   |   | |   |   |   | |   |   |   |  \ | | | | /  |    |        |   |   |   | |   | /     | |    |        |\n";
    cout << "| |   |   |   | |   |   |   | |   |___|   | |   |   |   |   \ \| |/ /   |    |______  |   |___|   | |   |/      | |    |______  |\n";
    cout << "| |   |   |   | |   |   |   | |           | |   |___|   |    |     |    |           | |           | |           | |           | |\n";
    cout << "| |   |   |   | |   |   |   | |     ______| |           |    |     |    |     ______| |    ___    | |           | |     ______| |\n";
    cout << "| |   |   |   | |   |   |   | |    |        |    ___    |   / /| |\ \   |    |        |   |   |   | |      /|   | |    |        |\n";
    cout << "| |   |   |   | |   |___|   | |    |        |   |   |   |  / | | | | \  |    |______  |   |   |   | |     / |   | |    |______  |\n";
    cout << "| |   |   |   | |           | |    |        |   |   |   | |  | | | |  | |           | |   |   |   | |    /  |   | |           | |\n";
    cout << "| |___|   |___| |___________| |____|        |___|   |___| |__| |_| |__| |___________| |___|   |___| |___/   |___| |___________| |\n";
    cout << "|_______________________________________________________________________________________________________________________________|\n";
}
