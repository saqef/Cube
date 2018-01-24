// Cube.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

long double fact(double n);
long double binom(double n, double k);

void main()
{
	int N = 0, Q = 0;
	long double compos = 0.0, all = 0.0;
	cout << "N & Q=?\n";
	cin >> N >> Q;
	if ((N < 1) || (N > 501))
		{
			cout << "N is out of limits(1-500).Repeat...\n" << endl;
			main();
		}
	else
		{
			if ((Q < 1) || (Q > 3001))
			{
				cout << "Q is out of limits(1-3000).Repeat...\n" << endl;
				main();
			}
		}	
	if ((N * 6 < Q) || (N > Q))
	{
		cout << "It's impossible.Repeat...\n" << endl;
		main();
	}
	else
	{
		compos = binom(Q - 1, N - 1);
		all = pow(6, N);
		cout << "Probability=" << compos / all << endl;
	}
	system("pause");
}

long double fact(double n)
{
	long double res = 1;
	#pragma omp parallel for
	for (long double i = 2.0; i < n + 1; i++)
		res *= i;
	return res;
}

long double binom(double n, double k)
{
	long double res=1, K=1;
	for (long double i = n - k + 1; i < n + 1; i++)
	{
		res *= i / K;
		K++;
	}
	return res;
}