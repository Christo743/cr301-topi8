#pragma once
#include <iostream>
#include "Player.h"

using namespace std;

class JsonHelper
{
public:

	JsonHelper();

	void SaveToFile(string filename, Player player);
	Player ReadFromFile(string filename);

	~JsonHelper();

};

