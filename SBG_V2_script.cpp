#include "SBG_V2_script.h"

// ��������� �������� ������������.
void setUserShips(Field& userField, Ship* ships)
{
    int amountOfShips = 10; // ���������� ��������.

    // ������������ ��������.
    for (int i = 0; i < amountOfShips; i++)
    {
        userField.print(); // ������ �������� ���� ������ ��� ���������� ������������� ���������� �����.
        int amountOfUnits; // ���������� �����(�����).

        // ���������� "������������ ��?", ��������� � ��������. �� ��������� ��������������� ������������� ��������.
        // ���� ������� �� ������������, �� �������� ���������� ��� �����������.
        bool isVertical = false; 

        bool flag = false; // ���� �����������, �� ��������� ������������� ������������� ��������.
        
        // ������������� ���������� "������������ ��?", ���������� ��� �����. 
        // ������ ���������� �� ���� X � Y.
        int intIsVertical, firstXCord, firstYCord; 

        if (i == 0)
        {
            cout << "��������� ��������������� �������:\n";
            amountOfUnits = 4;
        }
        if (i == 1)
        {
            cout << "��������� ������� ������������ �������:\n";
            amountOfUnits = 3;
        }
        if (i == 2)
        {
            cout << "��������� ������� ������������ �������:\n";
            amountOfUnits = 3;
        }
        if (i == 3)
        {
            cout << "��������� ������� ������������� �������:\n";
            amountOfUnits = 2;
        }
        if (i == 4)
        {
            cout << "��������� ������� ������������� �������:\n";
            amountOfUnits = 2;
        }
        if (i == 5)
        {
            cout << "��������� �������� ������������� �������:\n";
            amountOfUnits = 2;
        }
        if (i == 6)
        {
            cout << "��������� ������� ������������� �������:\n";
            amountOfUnits = 1;
        }
        if (i == 7)
        {
            cout << "��������� ������� ������������� �������:\n";
            amountOfUnits = 1;
        }
        if (i == 8)
        {
            cout << "��������� �������� ������������� �������:\n";
            amountOfUnits = 1;
        }
        if (i == 9)
        {
            cout << "��������� ��������� ������������� �������:\n";
            amountOfUnits = 1;
        }

        // ���� ������� �� ������������, �� �������� ���������� ��� �����������. � ������ ������ ������������ ���������� ������ ���������� �����������.
        if (amountOfUnits != 1)
        {
            do
            {
                cout << "��� ����������� �������?\n 1 - �����������; 2 - �������������: ";
                cin >> intIsVertical;

                if (intIsVertical != 1 && intIsVertical != 2)
                    cout << "������������ �������� ������, ��������� ����.\n";
            } while (intIsVertical != 1 && intIsVertical != 2);

            if (intIsVertical == 1)
                isVertical = true;
            else
                isVertical = false;
        }

        do
        {
            cout << "������� ������ ���������� �� X � �� Y(�� 1-�� �� 10-��): ";
            cin >> firstXCord >> firstYCord;
            firstXCord--;
            firstYCord--;

            // ���� ����������� ��������� �������� ������ ������ "Field", ������� ���������� - �������� �� �����?
            flag = userField.checkForAvailability(firstXCord, firstYCord, amountOfUnits, isVertical);

            if (!flag || firstXCord < 0 || firstXCord > 9 || firstYCord < 0 || firstYCord > 9)
                cout << "����������� ������� ����������, ��������� ����.\n";
            
        } while (!flag || firstXCord < 0 || firstXCord > 9 || firstYCord < 0 || firstYCord > 9);

        ships[i].setShip(firstXCord, firstYCord, isVertical);
    }
}

// ��������� �������� ����������.
void setComputerShips(Field& computerField, Ship* computerShips)
{
    int amountOfShips = 10; // ���������� ��������.
    
    for (int i = 0; i < amountOfShips; i++)
    {
        // ���������� "������������ ��?", ��������� � ��������. �� ��������� ��������������� ������������� ��������.
        // ���� ������� �� ������������, �� �������� ���������� ��� �����������.
        bool isVertical = false;

        // ���� �����������, �� ��������� ������������� ������������� ��������.
        bool flag = false;

        // ������������� ���������� "������������ ��?", ���������� ��� �����. 
        // ������ ���������� �� ���� X � Y.
        int amountOfUnits, firstXCord, firstYCord;

        if (i == 0)
            amountOfUnits = 4;
        if (i == 1 || i == 2)
            amountOfUnits = 3;
        else if (i > 2 && i < 6)
            amountOfUnits = 2;
        else
            amountOfUnits = 1;

        // ���� ������� �� ������������, �� �������� ���������� ��� �����������. 
        // � ������ ������ ��������� ��� ������ ������� "rand()" ������������� ����������� �������.
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

            // ���� ����������� ��������� �������� ������ ������ "Field", ������� ���������� - �������� �� �����?
            flag = computerField.checkForAvailability(firstXCord, firstYCord, amountOfUnits, isVertical);

        } while (!flag);
        computerShips[i].setShip(firstXCord, firstYCord, isVertical);
    }
}

// ����������� ���������(��� �����, ����� ������ ��������) ���� �� "computerField" � "emptyComputerField".
void copyKnownPlaces(Field& computerField, Field& emptyComputerField)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            // ���������� "����" ���������� ������ �� "computerField". 
            char sign = computerField.returnSign(i, j);
            // ���� ������ �� "�������", �� �������� ��� � "emptyComputerField".
            if (sign != SHIP)
                emptyComputerField.setUnit(sign, i, j);
        }
    }
}

// ����� ����������. ���������� ��������� � ������� ��� ���������.
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
        message = "��������� ���������� ��������!\n";
    }

    if (useGunRun = false && computerScoreStreak.returnAmountOfBomberRun() > 0)
    {
        XCord = rand() % 7 + 1;
        YCord = rand() % 7 + 1;
        computerScoreStreak.bomberRunAttack(XCord, YCord);
        outputNumber = 0;
        message = "��������� �������� �������������!\n";
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
            message = "��������� ����� �� ����� ��������.\n";
            outputNumber = 1;
        }
        else
        {
            userField.setUnit(MISS, XCord, YCord);
            message = "��������� �����������.\n";
            outputNumber = 0;
        }
    }
    return outputNumber;
}

// ����� ������������. ���������� ��������� � ������� ��� ���������.
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
            cout << "������ ������������ ��������[Y/N]?\n";
            cin >> choice;
            choice = tolower((char)choice);
            if (choice != 'y' && choice != 'n')
                cout << "��������� ����.\n";
        } while (choice != 'y' && choice != 'n');
        if (choice == 'y')
        {
            useGunRun = true;
            int cord;
            int intIsVertical;
            bool isVertical;
            do {
                cout << "��� ������� ������?\n1 - �� ���������;\n2 - �� �����������.\n";
                cin >> intIsVertical;
                if (intIsVertical != 1 && intIsVertical != 2)
                    cout << "��������� ����.\n";
            } while (intIsVertical != 1 && intIsVertical != 2);

            if (intIsVertical == 1)
                isVertical = true;
            else
                isVertical = false;

            do {
                cout << "�� ����� ���������� ������� ������(�� 1-�� �� 10-��)?\n";
                cin >> cord;
                cord--;
                if (cord < 0 && cord > 9)
                    cout << "��������� ����.\n";
            } while (cord < 0 && cord > 9);
            userScoreStreak.gunRunAttack(cord, isVertical);
            outputNumber = 0;
            message = "������!\n";
        }
    }
    if (userScoreStreak.returnAmountOfBomberRun() > 0 && useGunRun == false)
    {
        do
        {
            cout << "������ ������������ �������������[Y/N]?\n";
            cin >> choice;
            choice = tolower((char)choice);
            if (choice != 'y' && choice != 'n')
                cout << "��������� ����.\n";
        } while (choice != 'y' && choice != 'n');

        if (choice == 'y')
        {
            useBomberRun = true;
            do {
                cout << "�� ����� ���������� ���������� �������������(�� ���� X � Y�� 2-� �� 9-��)? ������������� �� ������������ �� ����� ����.\n";
                cin >> XCord >> YCord;
                XCord--;
                YCord--;
                if (XCord < 1 && XCord > 8 && YCord < 1 && YCord > 8)
                    cout << "��������� ����.\n";
            } while (XCord < 1 && XCord > 8 && YCord < 1 && YCord > 8);
            userScoreStreak.bomberRunAttack(XCord, YCord);
            outputNumber = 0;
            message = "����� ��������!\n";
        }
    }
    
    
    if (useGunRun == false && useBomberRun == false)
    {
        do
        {
            cout << "������� ���������� ��� ����� �� X � �� Y(�� 1-�� �� 10-��): \n";
            cin >> XCord >> YCord;
            XCord--;
            YCord--;
            if (emptyComputerField.returnSign(XCord, YCord) != NOTHING || XCord < 0 || XCord > 9 || YCord < 0 || YCord > 9)
                cout << "������� ������ ����������.\n";
        } while (emptyComputerField.returnSign(XCord, YCord) != NOTHING || XCord > 9 || XCord < 0 || YCord < 0 || YCord > 9);
        if (computerField.returnSign(XCord, YCord) == NOTHING)
        {
            message = "������.\n";
            computerField.setUnit(MISS, XCord, YCord);
            emptyComputerField.setUnit(MISS, XCord, YCord);
            copyKnownPlaces(computerField, emptyComputerField);

            outputNumber = 0;
        }
        if (computerField.returnSign(XCord, YCord) == SHIP)
        {
            message = "���������.\n";
            computerField.setUnit(HIT, XCord, YCord);
            emptyComputerField.setUnit(HIT, XCord, YCord);
            copyKnownPlaces(computerField, emptyComputerField);
            outputNumber = 1;
        }
    }
    return outputNumber;
}

// ����������� ����: ����� ����� ��� ����� ���������. ��� ���� ���������� ��������� � ������������.
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

// �������� �������� �� �����������. ������� �������� ������������ � ����������. 
// ���� ������� ��������� � �� ��������, �� ���������� ��������� � ���, ��� � ����� ������� ���������.
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
                message = "��� �������������� ������� ��������.\n";
            else if (i == 1 || i == 2)
                message = "��� ����������� ������� ��������.\n";
            else if (i > 2 && i < 6)
                message = "��� ������������ ������� ��������.\n";
            else
                message = "��� ������������ ������� ��������.\n";
            userShips[i].checkDestroyedShip();
            amountOfAliveUserShips--;
        }

        if (computerShips[i].returnStatusIsDestroyed() == true && computerShips[i].returnStatusIsChecked() == false)
        {
            if (i == 0)
                message = "�������������� ������� ���������� ��������.\n";
            else if (i == 1 || i == 2)
                message = "����������� ������� ���������� ��������.\n";
            else if (i > 2 && i < 6)
                message = "������������ ������� ���������� ��������.\n";
            else
                message = "������������ ������� ���������� ��������.\n";
            computerShips[i].checkDestroyedShip();
            amountOfAliveComputerShips--;
        }
    }
    return message;
}

// ������ �������� � ������.
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

// ������ �������� � ������.
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

// ������ �������� � �������.
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

// ������ �������� � ����������.
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
