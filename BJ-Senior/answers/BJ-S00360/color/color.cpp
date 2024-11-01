#include <iostream>
#include <cstdio>
using namespace std;

int a[200010];
int flag[200010]; // 0->red, 1->blue
int n;
int maxn = -1;

int check()
{
	int sum = 0;
	for (int i = 2; i <= n; i++)
	{
		int j;
		for (j = i - 1; j >= 0; j--)
			if (flag[j] == flag[i])
				break;
		if (j == 0)
			continue;
		sum += a[i] * (a[i] == a[j]);
	}
	return sum;
}

void dfs(int step)
{
	if (step > n)
	{
		maxn = max(maxn, check());
		return;
	}
	flag[step] = 0;
	dfs(step + 1);
	flag[step] = 1;
	dfs(step + 1);
}

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int T;
	scanf("%d", &T);
	flag[0] = -1;
	while (T--)
	{
		maxn = -1;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", a + i);
		dfs(1);
		printf("%d\n", maxn);
	}
}