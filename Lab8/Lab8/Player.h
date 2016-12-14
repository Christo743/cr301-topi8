#pragma once
#include <iostream>
#include "GameData.h"
#include "Preference.h"

using namespace std;

class Player
{
public:

	Player();

	int id;
	string name;
	string dateOfBirth;
	string country;
	string email;

	GameData gameData;
	Preference preference;
	
	~Player();

};

