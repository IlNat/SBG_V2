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

// Перечисление: "Корабль", "Попадание", "Промах", "Пустая ячейка".
enum { SHIP = '*', HIT = '+', MISS = '-', NOTHING = '#' };

// Установка кораблей пользователя.
void setUserShips(Field& userField, Ship* ships);

// Установка кораблей компьютера.
void setComputerShips(Field& computerField, Ship* computerShips);

// Копирование известных(все знаки, кроме знаков кораблей) мест из "computerField" в "emptyComputerField".
void copyKnownPlaces(Field& computerField, Field& emptyComputerField);

// Атака компьютера. Возвращает сообщение о промахе или попадании.
int computerAttack(Field& userField, string& message, ScoreStreak& copmuterScoreStreak);

// Атака пользователя. Возвращает сообщение о промахе или попадании.
int userAttack(Field& computerField, Field& emptyComputerField, string& message, ScoreStreak& userScoreStreak);

// Определение хода: ходит игрок или ходит компьютер. При этом вовзращает сообщение с происходящим.
void makeNextMove(bool& isPlayerMove, Field& userField, Field& computerField, Field& emptyComputerField, string& messageOfUserAttackStatus, string& messageOfComputerAttackStatus, ScoreStreak& userScoreStreak, ScoreStreak& copmuterScoreStreak, int& userStreak, int& computerStreak);

// Проверка кораблей на целостность. Перебор кораблей пользователя и компьютера. 
// Если корабль уничтожен и не проверен, то вовзращает сообщение о том, чей и какой корабль уничтожен.
string checkShips(int& amountOfAliveUserShips, int& amountOfAliveComputerShips, int amountOfShips, Ship* userShips, Ship* computerShips);