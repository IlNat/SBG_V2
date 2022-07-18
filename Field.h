#pragma once
class Field
{
private: 
	const int sizeOfLine = 10;
	char field[10][10];	
	enum { SHIP = '*', NOTHING = '#', HIT = '+', MISS = '-' };
public: 
	
	// ����������� �� ���������. ��� �������� ���������� ������� ��������������� �� "������ ������".
	Field();

	// ��������� ������� �� �����������.
	void setUnit(char sign, int XCord, int YCord);

	// ������ ����.
	void print();

	// �������� �� �����������. ��������� ���������� �� ���� X � Y, ���������� �����(�����), �����������.
	bool checkForAvailability(int XCord, int YCord, int amountOfUnits, bool isVertical);

	// �������� �� ����������� �� �����������.
	bool checkForHorizontalLocationMistakes(int XCord, int YCord, int amountOfUnits);

	// �������� �� ����������� �� ���������.
	bool checkForVerticalLocationMistakes(int XCord, int YCord, int amountOfUnits);

	// ����������� �������� ���������� �������.
	char returnSign(int XCord, int YCord) { return field[XCord][YCord]; };

	~Field()
	{
		if (field != nullptr)
			delete[] field;
	}
};

