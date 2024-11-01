#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005], n, ans;
bool vis[200005];
void dfs(int id)
{
	if(id > n)
	{
		int lr = 0, lb = 0, tot = 0;
		for(int i = 1; i <= n; i ++)
		{
			if(vis[i])
			{
				if(a[i] == lr)
				{
					tot += a[i];
				}
				lr = a[i];
			}
			else
			{
				if(a[i] == lb)
				{
					tot += a[i];
				}
				lb = a[i];
			}
		}
		ans = max(ans, tot);
		return;
	}
	vis[id] = 1;
	dfs(id + 1);
	vis[id] = 0;
	dfs(id + 1);
}
signed main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int t;
	cin >> t;
	while(t --)
	{
		cin >> n;
		for(int i = 1; i <= n; i ++)
		{
			cin >> a[i];
		}
		ans = 0;
		dfs(1);
		cout << ans << endl;
	}
	return 0;
}

