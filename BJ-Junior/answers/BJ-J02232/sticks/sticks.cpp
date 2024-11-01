#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string sub[22] = {"", "1145141919810", "1", "7", "4", "2", "6", "8"};

string minstr(string a, string b)
{
	if (a.length() > b.length())
	{
		return b;
	}
	else if (a.length() < b.length())
	{
		return a;
	}
	for (int i = 0; i < a.length(); i++)
	{
		if ((int)a[i] != (int)b[i])
		{
			if ((int)a[i] > (int)b[i])
			{
				return b;
			}
			return a;
		}
	}
	return a;
}

int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int n, t;
	cin >> t;
	for (int i = 8; i <= 21; i++)
	{
		sub[i] = sub[i - 6] + "0";
		for (int j = 1; j < 10; j++)
		{
			sub[i] = minstr(sub[i - num[j]] + (char)(48 + j), sub[i]);
		}
	}
	for (int i = 1; i <= t; i++)
	{
		cin >> n;
		if (n < 2)
		{
			cout << "-1" << endl;
		}
		else if (n < 22)
		{
			cout << sub[n] << endl;
		}
		else
		{
			cout << sub[(n - 1) % 7 + 15];
			for (int i = 4; i <= (n + 6) / 7; i++)
			{
				cout << "8";
			}
			cout << endl;
		}
	}
	return 0;
}