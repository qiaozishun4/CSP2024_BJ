#include <bits/stdc++.h>
using namespace std;

int a[5][15];
string s[55];

int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) cin >> s[i];
	int cnt = 52;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		if (s[1][0] == 'D') x = 1;
		else if (s[1][0] == 'C') x = 2;
		else if (s[1][0] == 'H') x = 3;
		else x = 4;
		if ('2' <= s[i][1] && s[i][1] <= '9') y = s[i][1] - '0';
		else if (s[i][1] == 'A') y = 1;
		else if (s[i][1] == 'T') y = 10;
		else if (s[i][1] == 'J') y = 11;
		else if (s[i][1] == 'Q') y = 12;
		else y = 13;
		if (a[x][y] < 1)
		{
			a[x][y]++;
			cnt--;
		}
	}
	printf("%d", cnt);
	return 0;
}