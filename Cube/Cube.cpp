// Cube.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

double binom(int n, int k);

void main()
{
	int N = 0, Q = 0;
    double compos = 0.0;
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
		cout << "Probability=" << compos  << endl;
	}
	system("pause");
}


double binom(int n, int k)
{
	double res=1, K=1;
	res /= 6;
#pragma omp parallel for
	for (int i = n - k + 1; i < n + 1; i++)
	{
		res *= i / K / 6 ;
		K++;
	}
	return res;
}