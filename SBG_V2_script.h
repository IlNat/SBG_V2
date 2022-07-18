#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>
#include "Field.h"
#include "Ship.h"
#include "ScoreStreak.h"
#pragma once

using namespace std;

// ������������: "�������", "���������", "������", "������ ������".
enum { SHIP = '*', HIT = '+', MISS = '-', NOTHING = '#' };

// ��������� �������� ������������.
void setUserShips(Field& userField, Ship* ships);

// ��������� �������� ����������.
void setComputerShips(Field& computerField, Ship* computerShips);

// ����������� ���������(��� �����, ����� ������ ��������) ���� �� "computerField" � "emptyComputerField".
void copyKnownPlaces(Field& computerField, Field& emptyComputerField);

// ����� ����������. ���������� ��������� � ������� ��� ���������.
int computerAttack(Field& userField, string& message, ScoreStreak& copmuterScoreStreak);

// ����� ������������. ���������� ��������� � ������� ��� ���������.
int userAttack(Field& computerField, Field& emptyComputerField, string& message, ScoreStreak& userScoreStreak);

// ����������� ����: ����� ����� ��� ����� ���������. ��� ���� ���������� ��������� � ������������.
void makeNextMove(bool& isPlayerMove, Field& userField, Field& computerField, Field& emptyComputerField, string& messageOfUserAttackStatus, string& messageOfComputerAttackStatus, ScoreStreak& userScoreStreak, ScoreStreak& copmuterScoreStreak, int& userStreak, int& computerStreak);

// �������� �������� �� �����������. ������� �������� ������������ � ����������. 
// ���� ������� ��������� � �� ��������, �� ���������� ��������� � ���, ��� � ����� ������� ���������.
string checkShips(int& amountOfAliveUserShips, int& amountOfAliveComputerShips, int amountOfShips, Ship* userShips, Ship* computerShips);