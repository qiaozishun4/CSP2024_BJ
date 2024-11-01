#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int t, n, k, q;
vector<int> s[N], empty;
int r, c;
bool ans;

void dfs(int p, int last, int stp)
{
	if (stp == r)
	{
		if (last == c)
			ans = true;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (i == p)
			continue;
		if (ans)
			break;
		for (int a = 0, len = s[i].size(); a < len; a++)
		{
			if (ans)
				break;
			if (s[i][a] == last)
				for (int j = a + 1; j <= a + k - 1; j++)
				{
					if (ans)
						break;
					dfs(i, s[i][j], stp + 1);
				}
		}
	}
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d", &n, &k, &q);
		for (int i = 1; i <= n; i++)
			s[i] = empty;
		for (int i = 1; i <= n; i++)
		{
			int l;
			scanf("%d", &l);
			while (l--)
			{
				int a;
				scanf("%d", &a);
				s[i].push_back(a);
			}
		}
		while (q--)
		{
			ans = false;
			scanf("%d%d", &r, &c);
			for (int i = 1; i <= n; i++)
				for (int a = 0, len = s[i].size(); a < len; a++)
					if (s[i][a] == 1)
						for (int j = a + 1; j <= a + k - 1; j++)
							dfs(i, s[i][j], 1);
			printf("%d\n", ans);
		}
	}

	return 0;
}