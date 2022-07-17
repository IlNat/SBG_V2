#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>
#include "Field.h"
#include "Ship.h"
#pragma once

using namespace std;

enum { SHIP = '*', HIT = '+', MISS = '-', NOTHING = '#' };

void setUserShips(Field& userField, Ship* ships);

void setComputerShips(Field& computerField, Ship* computerShips);

void copyKnownPlaces(Field& computerField, Field& emptyComputerField);

int computerAttack(Field& userField, string& message);

int userAttack(Field& computerField, Field& emptyComputerField, string& message);

void makeNextMove(bool& isPlayerMove, Field& userField, Field& computerField, Field& emptyComputerField, string& message);

string checkShips(int& amountOfAliveUserShips, int& amountOfAliveComputerShips, int amountOfShips, Ship* userShips, Ship* computerShips);