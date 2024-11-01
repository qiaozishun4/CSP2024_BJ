#include <bits/stdc++.h>
using namespace std;

int ans[15000];
int stick[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		if (n == 1)
		{
			printf("-1\n");
			continue;
		}
		int x = (n + 7 - 1) / 7;
		if (x == 1)
		{
			for (int i = 1; i <= 9; i++)
			{
				if (stick[i] == n)
				{
					printf("%d\n", i);
					break;
				}
			}
			continue;
		}
		int i = 1, sum = 2 + (x - 1) * 6;
		while (n > sum && n - sum > x - 1)
		{
			sum += stick[i + 1] - stick[i];
			i++;
		}
		ans[1] = i;
		sum = n - sum;
		for (int j = x; j > x - sum; j--) ans[j] = 8;
		for (int j = 1; j <= x; j++) printf("%d", ans[j]);
		printf("\n");
		memset(ans, 0, sizeof(ans));
	}
	return 0;
}