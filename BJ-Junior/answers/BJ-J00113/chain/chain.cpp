#include<bits/stdc++.h>
using namespace std;
struct node
{
	int l;
	vector<int> a;
}a[100005];
bool vis[105][200005];
int n, K, q;
void dfs(int u, int v, int st)
{
	if(st > 5 && n <= 10 || st > 1 && n > 10) return;
	for(int i = v + 1; i <= v + K - 1 && i < a[u].l; i ++)
	{
		vis[st][a[u].a[i]] = 1;
		for(int I = 1; I <= n; I ++)
		{
			if(I == u) continue;
			for(int J = 0; J < a[I].l; J ++)
			{
				if(a[u].a[i] == a[I].a[J])
				{
					dfs(I, J, st + 1);
				}
			}
		}
	}
}
int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	int t, x;
	cin >> t;
	while(t --)
	{
		memset(vis, 0, sizeof(vis));
		cin >> n >> K >> q;
		for(int i = 1; i <= n; i ++)
		{
			a[i].a.clear();
		}
		for(int i = 1; i <= n; i ++)
		{
			cin >> a[i].l;
			for(int j = 1; j <= a[i].l; j ++)
			{
				cin >> x;
				a[i].a.push_back(x);
			}
		}
		for(int i = 1; i <= n; i ++)
		{
			for(int j = 0; j < a[i].l; j ++)
			{
				if(a[i].a[j] == 1)
				{
					dfs(i, j, 1);
				}
			}
		}
		int r, c;
		while(q --)
		{
			cin >> r >> c;
			cout << vis[r][c] << endl;
		}
	}
	return 0;
}
