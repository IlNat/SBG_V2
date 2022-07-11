#include <iostream>
#include "Field.h"
using namespace std;

Field::Field()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			field[i][j] == NOTHING;
		}
	}
}

void Field::setUnit(char sign, int XCord, int YCord)
{
	field[XCord][YCord] = sign;
}

void Field::print()
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (i == 0 && j != 0)
			{
				if (j == 10)
				{
					cout << 0;
				}
				else
				{
					cout << j;
				}
			}
			else if (j == 0)
			{
				if (i == 10)
				{
					cout << 0;
				}
				else
				{
					cout << i;
				}
			}
			else
			{
				if (field[i - 1][j - 1] != NOTHING)
					cout << field[i - 1][j - 1];
				else
					cout << ' ';
			}
		}
		cout << '\n';
	}
}


/*
void print_field(char field[10][10], int a)
{
	if (a == 1)
	{
		cout << "������ �������� ���� ������������(\'#\' - ������ ������������; \'*\' - �������/����� �������; \'-\' - ������; \'+\' - ��������� �� ������ �������;): \n";
	}
	if (a == 2)
	{
		cout << "������ �������� ���� ����������(\'#\' - ������ ������������; \'+\' - ���������; \'-\' - ������;): \n";
	}
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (i == 0 && j != 0)
			{
				if (j == 10)
				{
					cout << 0;
				}
				else
				{
					cout << j;
				}
			}
			else if (j == 0)
			{
				if (i != 10)
				{
					cout << i;
				}
				else
				{
					cout << 0;
				}
			}
			else
			{
				cout << field[i - 1][j - 1];
			}
		}
		cout << "\n";
	}
	cout << '\n';
}*/

bool Field::isAvailable(int XCord, int YCord, int amountOfUnits, bool isVertical)
{
	int operationNumber = 0;
	if (!isVertical)
	{
		if (XCord == 0 && YCord == 0)
			operationNumber = 1;
		else if (XCord == 0 && YCord > 0 && YCord < size - amountOfUnits)
			operationNumber = 2;
		else if (XCord > 0 && XCord < 9 && YCord == 0)
			operationNumber = 3;
		else if (XCord > 0 && XCord < 9 && YCord > 0 && YCord < size - amountOfUnits)
			operationNumber = 4;
		else if (XCord == 9 && YCord == 0)
			operationNumber = 5;
		else if (XCord == 9 && YCord > 0 && YCord < size - amountOfUnits)
			operationNumber = 6;
		else 
			return false;
	}
	else
	{
		if (XCord == 0 && YCord == 0)
			operationNumber = 7;
		else if (YCord == 0 && XCord > 0 && XCord < size - amountOfUnits)
			operationNumber = 8;
		else if (YCord > 0 && YCord < 9 && XCord == 0)
			operationNumber = 9;
		else if (YCord > 0 && YCord < 9 && XCord > 0 && YCord < size - amountOfUnits)
			operationNumber = 10;
		else if (YCord == 9 && XCord == 0)
			operationNumber = 11;
		else if (YCord == 9 && XCord > 0 && XCord < size - amountOfUnits)
			operationNumber = 12;
		else
			return false;
	}
	switch (operationNumber)
	{
	case 1:
	{
		
		break;
	}
	default:
	{
		cout << "������!\n";
	}
	}
}

bool Field::checkForAvailability(int XCord, int YCord, int amountOfUnits, bool isVertical, int caseNumber)
{
	if (!isVertical)
	{
		if (YCord != 9)
		{
			if (caseNumber == 3) 
			{
				if (YCord == 0)
				{
					if (field[XCord][YCord] == SHIP && field[XCord - 1][YCord] == SHIP && field[XCord + 1][YCord] == SHIP)
						return false;
					else
						return true;
				}
				else 
				{
					if (field[XCord][YCord] == SHIP && field[XCord - 1][YCord - 1] == SHIP && field[XCord - 1][YCord] == SHIP && field[XCord + 1][YCord] == SHIP && field[XCord][YCord - 1] == SHIP && field[XCord + 1][YCord - 1] == SHIP)
						return false;
					else
						return true;
				}
			}
			if (caseNumber == 1)
			{
				if (YCord == 0)
				{
					if (field[XCord][YCord] == SHIP && field[XCord + 1][YCord] == SHIP)
						return false;
					else
						return true;
				}
				else 
				{
					if (field[XCord][YCord] == SHIP && field[XCord + 1][YCord] == SHIP && field[XCord][YCord - 1] == SHIP && field[XCord + 1][YCord - 1] == SHIP)
						return false;
					else
						return true;
				}
			}
			if (caseNumber == 2)
			{
				if (YCord == 0)
				{
					if (field[XCord][YCord] == SHIP && field[XCord - 1][YCord] == SHIP)
						return false;
					else
						return true;
				}
				else 
				{
					if (field[XCord][YCord] == SHIP && field[XCord - 1][YCord - 1] == SHIP && field[XCord - 1][YCord] == SHIP && field[XCord][YCord - 1] == SHIP)
						return false;
					else
						return true;
				}
			}
			for (int i = 0; i < amountOfUnits; i++)
			{
				if (field[XCord][YCord + i] == SHIP)
					return false;
				else
					return true;
				if (caseNumber == 3 || caseNumber == 1)
				{
					if (field[XCord + 1][YCord + i] == SHIP)
						return false;
					else
						return true;
				}
				if (caseNumber == 3 || caseNumber == 2)
				{
					if (field[XCord - 1][YCord + i] == SHIP)
						return false;
					else
						return true;
				}
			}
		}
		else
		{
			if (amountOfUnits == 1)
			{
				if (XCord == 0)
				{
					if (field[XCord][YCord] == SHIP && field[XCord][YCord - 1] == SHIP && field[XCord + 1][YCord] == SHIP && field[XCord + 1][YCord - 1] == SHIP)
						return false;
					else
						return true;
				}
				else if (XCord != 9)
				{
					if (field[XCord][YCord] == SHIP && field[XCord][YCord - 1] == SHIP && field[XCord - 1][YCord] == SHIP && field[XCord - 1][YCord - 1] == SHIP && field[XCord + 1][YCord - 1] == SHIP && field[XCord + 1][YCord] == SHIP)
						return false;
					else
						return true;
				}
				else
				{
					if (field[XCord][YCord] == SHIP && field[XCord][YCord - 1] == SHIP && field[XCord - 1][YCord] == SHIP && field[XCord - 1][YCord - 1] == SHIP)
						return false;
					else
						return true;
				}
			}
			else
				return false;
		}
	}
	else	
	{
	if (XCord != 9)
	{
		if (caseNumber == 3)
		{
			if (XCord == 0)
			{
				if (field[XCord][YCord] == SHIP && field[XCord][YCord - 1] == SHIP && field[XCord][YCord + 1] == SHIP)
					return false;
				else
					return true;
			}
			else
			{
				if (field[XCord][YCord] == SHIP && field[XCord - 1][YCord - 1] == SHIP && field[XCord][YCord - 1] == SHIP && field[XCord][YCord + 1] == SHIP && field[XCord - 1][YCord] == SHIP && field[XCord - 1][YCord + 1] == SHIP)
					return false;
				else
					return true;
			}
		}
		if (caseNumber == 1)
		{
			if (YCord == 0)
			{
				if (field[XCord][YCord] == SHIP && field[XCord][YCord + 1] == SHIP)
					return false;
				else
					return true;
			}
			else
			{
				if (field[XCord][YCord] == SHIP && field[XCord][YCord + 1] == SHIP && field[XCord - 1][YCord] == SHIP && field[XCord - 1][YCord + 1] == SHIP)
					return false;
				else
					return true;
			}
		}
		if (caseNumber == 2)
		{
			if (YCord == 0)
			{
				if (field[XCord - 1][YCord] == SHIP && field[XCord][YCord] == SHIP)
					return false;
				else
					return true;
			}
			else
			{
				if (field[XCord][YCord] == SHIP && field[XCord - 1][YCord - 1] == SHIP && field[XCord][YCord - 1] == SHIP && field[XCord - 1][YCord] == SHIP)
					return false;
				else
					return true;
			}
		}
		for (int i = 0; i < amountOfUnits; i++)
		{
			if (field[XCord + i][YCord] == SHIP)
				return false;
			else
				return true;
			if (caseNumber == 3 || caseNumber == 1)
			{
				if (field[XCord + i][YCord + 1] == SHIP)
					return false;
				else
					return true;
			}
			if (caseNumber == 3 || caseNumber == 2)
			{
				if (field[XCord + i][YCord - 1] == SHIP)
					return false;
				else
					return true;
			}
		}
	}
	else
	{
		if (amountOfUnits == 1)
		{
			if (YCord == 0)
			{
				if (field[XCord][YCord] == SHIP && field[XCord - 1][YCord] == SHIP && field[XCord][YCord + 1] == SHIP && field[XCord - 1][YCord + 1] == SHIP)
					return false;
				else
					return true;
			}
			else if (YCord != 9)
			{
				if (field[XCord][YCord] == SHIP && field[XCord - 1][YCord] == SHIP && field[XCord][YCord - 1] == SHIP && field[XCord - 1][YCord - 1] == SHIP && field[XCord - 1][YCord + 1] == SHIP && field[XCord][YCord + 1] == SHIP)
					return false;
				else
					return true;
			}
			else
			{
				if (field[XCord][YCord] == SHIP && field[XCord - 1][YCord] == SHIP && field[XCord][YCord - 1] == SHIP && field[XCord - 1][YCord - 1] == SHIP)
					return false;
				else
					return true;
			}
		}
		else
			return false;
	}
	}
	
}