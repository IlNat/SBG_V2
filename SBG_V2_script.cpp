#include "SBG_V2_script.h"

void setUserShips(Field& userField, Ship* ships)
{
    int amountOfShips = 10;

    // ������������ ��������.
    for (int i = 0; i < amountOfShips; i++)
    {
        userField.print();
        int amountOfUnits;
        bool isVertical = false;
        bool flag = false;
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
            flag = userField.checkForAvailability(firstXCord, firstYCord, amountOfUnits, isVertical);
            if (!flag || firstXCord < 0 || firstXCord > 9 || firstYCord < 0 || firstYCord > 9)
                cout << "����������� ������� ����������, ��������� ����.\n";
        } while (!flag || firstXCord < 0 || firstXCord > 9 || firstYCord < 0 || firstYCord > 9);

        ships[i].setShip(firstXCord, firstYCord, isVertical);

    }
}

void setComputerShips(Field& computerField, Ship* computerShips)
{
    int amountOfShips = 10;
    bool isVertical = false;
    for (int i = 0; i < amountOfShips; i++)
    {
        int amountOfUnits;
        bool flag = false;

        int firstXCord, firstYCord;

        if (i == 0)
            amountOfUnits = 4;
        if (i == 1 || i == 2)
            amountOfUnits = 3;
        else if (i > 2 && i < 6)
            amountOfUnits = 2;
        else
            amountOfUnits = 1;

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
            flag = computerField.checkForAvailability(firstXCord, firstYCord, amountOfUnits, isVertical);
        } while (!flag);
        computerShips[i].setShip(firstXCord, firstYCord, isVertical);
    }
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

int computerAttack(Field& userField, string& message)
{
    srand(time(0));
    int XCord, YCord;
    char sign;
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
        return 1;
    }
    else
    {
        userField.setUnit(MISS, XCord, YCord);
        message = "��������� �����������.\n";
        return 0;
    }
}

int userAttack(Field& computerField, Field& emptyComputerField, string& message)
{
    int XCord, YCord;
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

        return 0;
    }
    if (computerField.returnSign(XCord, YCord) == SHIP)
    {
        message = "���������.\n";
        computerField.setUnit(HIT, XCord, YCord);
        emptyComputerField.setUnit(HIT, XCord, YCord);
        copyKnownPlaces(computerField, emptyComputerField);
        return 1;
    }

}

void makeNextMove(bool& isPlayerMove, Field& userField, Field& computerField, Field& emptyComputerField, string& message)
{
    if (isPlayerMove)
    {
        if (userAttack(computerField, emptyComputerField, message) == 0)
            isPlayerMove = false;
        else
            isPlayerMove = true;
    }
    else
    {
        if (computerAttack(userField, message) == 1)
            isPlayerMove = false;
        else
            isPlayerMove = true;
    }
}

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
