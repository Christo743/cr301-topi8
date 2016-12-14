#pragma once
#include <iostream>

using namespace std;

class Preference
{
public:

	Preference();

	string language;
	int volumelevel;
	string graphic;
	int difficulty;

	~Preference();
};

