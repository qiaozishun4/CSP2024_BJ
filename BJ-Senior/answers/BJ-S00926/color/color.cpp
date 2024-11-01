#include <bits/stdc++.h>
using namespace std;
int maxn, n;
int a[100005], bx[100005];
void dfs(int st)
{
	if (st > n)
	{
		int rl= 0, bl = 0;
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			if (bx[i] == 1)
			{
				if (bl != 0 && a[i] == a[bl])
				{
					sum += a[bl];
				}
				bl = i;
			}
			if (bx[i] == 2)
			{
				if (rl != 0 && a[i] == a[rl])
				{
					sum += a[rl];
				}
				rl = i;
			}	
		}
		maxn = max(maxn, sum);
		return;
	}
	for (int i = 1; i <= 2; i++)
	{
		if (i == 1)
		{ 
			bx[st] = 1;//blue
		}
		if (i == 2)
		{
			bx[st] = 2;//red;
		}
		dfs(st + 1);
		bx[st] = 0;
	}
}
int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int t;
	cin >> t;
	while (t--)
	{
		maxn = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		dfs(1);
		cout << maxn << endl;
	}
	return 0;
}
