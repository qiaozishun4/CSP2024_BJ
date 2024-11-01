#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<string> s;

int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	cin >> n;
	string card;
	bool flag;
	for (int i = 1; i <= n; i++)
	{
		cin >> card;
		flag = true;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == card)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			s.push_back(card);
		}
	}
	cout << 52 - s.size() << endl;
	return 0;
}