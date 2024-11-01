#include <iostream>
using namespace std;

int b[10][50];
int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n, ls1, ls2;
	char c1, c2;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> c1 >> c2;
		if (c1 == 'D')
			ls1 = 1;
		if (c1 == 'C')
			ls1 = 2;
		if (c1 == 'H')
			ls1 = 3;
		if (c1 == 'S')
			ls1 = 4;
		if ('2' <= c2 && c2 <= '9')
		{
			ls2 = c2 - '0';
		}
		else if (c2 == 'T')
		{
			ls2 = 10;
		}
		else if (c2 == 'J')
		{
			ls2 = 11;
		}
		else if (c2 == 'Q')
		{
			ls2 = 12;
		}
		else if (c2 == 'K')
		{
			ls2 = 13;
		}
		else if (c2 == 'A')
		{
			ls2 = 1;
		}
		b[ls1][ls2] = 1;
//		cout << c1 << " " << c2 << endl;
//		cout << ls1 << " " << ls2 << endl;
	}
	int cnt = 0;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 13; j++)
		{
			if (b[i][j] == 0)
			{
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
