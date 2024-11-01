#include<bits/stdc++.h>

using namespace std;

int n;
bool poker[10][20];
char s[5];
int ans;

int get_num(char c)
{
	if (c == 'A')
		return 1;
	if (c >= '2' && c <= '9')
		return c - '0';
	if (c == 'T')
		return 10;
	if (c == 'J')
		return 11;
	if (c == 'Q')
		return 12;
	if (c == 'K')
		return 13;
	if (c == 'D')
		return 1;
	if (c == 'C')
		return 2;
	if (c == 'H')
		return 3;
	if (c == 'S')
		return 4;
}

int main()
{
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", s);
		poker[get_num(s[0])][get_num(s[1])] = true;
	}
	for (int i = 1; i <= 13; i++)
		for (int j = 1; j <= 4; j++)
			if (!poker[j][i])
				ans++;
	printf("%d\n", ans);

	return 0;
}