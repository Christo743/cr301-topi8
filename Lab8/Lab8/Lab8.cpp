// Lab8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "JsonHelper.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	string value = "";
	JsonHelper helper = JsonHelper();

	Player player = Player();
	player.id = 10;

	while (value != "0")
	{		
		string path = "example.json";
				
		cout << "Options: \n";
		cout << "1: Load data \n";
		cout << "2: Save data \n";
		cout << "0: Close program \n";

		getline(cin, value);

		if (value == "1")
		{
			cout << "Please provide the name/path of the file \n";
			getline(cin, path);
			Player player = helper.ReadFromFile(path);
			helper.SaveToFile(path+"2", player);
		}
		else if (value == "2")
		{
			cout << "Please provide the name/path of the file \n";
			getline(cin, path);
			helper.SaveToFile(path, player);
		}
	}


	return 0;
}

