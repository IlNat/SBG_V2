#include <iostream>
#include "Field.h"
#pragma once

using namespace std;

// ����� "����� �����". ���� ���������� ����� ����� � ������� �� ��������� "0", �� ���������� ����������� ������ ������ �� ����.
class ScoreStreak
{
private:
	int amountOfGunRun; // ���������� "����������" � �������.
	int amountOfBomberRun; // ���������� "�������������" � �������.
	Field& enemyField; // ������ �� ���� �����, �� ������� ����� ��������������� �������� ����� �����. 
	enum { SHIP = '*', NOTHING = '#', HIT = '+', MISS = '-' };
public: 

	// ����������� ������.
	ScoreStreak(Field& settingEnemyField);

	// ����� "���������". �� ��������� ��� ����������� � ���� ������������ ��������������� �����.
	void gunRunAttack(int Cord, bool isVertical);

	// ����� "�������������". �� ������� � 3*3 ������������ ��������������� �����.
	void bomberRunAttack(int XCord, int YCord);

	// ���������� ����������(�� 1) "����������" � �������.
	void increaseAmountOfGunRun() { amountOfGunRun++; };

	// ���������� ����������(�� 1) "�������������" � �������.
	void increaseAmountOfBomberRun() { amountOfBomberRun++; };

	// ���������� ���������� "����������" � �������.
	int returnAmountOfGunRun() { return amountOfGunRun; };

	// ���������� ���������� "�������������" � �������.
	int returnAmountOfBomberRun() { return amountOfBomberRun; };

};

