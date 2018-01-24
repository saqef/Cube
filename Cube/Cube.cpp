// Cube.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void main()
{
	string str="";
	int N=0, Q=0;
	cout << "N & Q=?\n";
	getline(cin, str);
	if (!str.empty())
	{
		str.erase(0, str.find_first_not_of(" "));
		N = stoi(str);
		if ((N < 1) || (N > 501))
		{
			cout << "N is out of limits(1-500).Repeat...\n";
			main();
		}
		else
		{
			str.erase(0, str.find_first_of(" "));
			Q = stoi(str);
			if ((Q < 1) || (Q > 3001))
			{
				cout << "Q is out of limits(1-3000).Repeat...\n";
				main();
			}
		}
	}
	else
	{
		cout << "Parametrs are empty. Repeat...\n";
		main();
	}
	system("pause");
}

