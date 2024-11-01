#include <bits/stdc++.h>
using namespace std;

int t,n,a[200005],f[200005],ans;

void dfs(int x)
{
	if (x > n)
	{
		int sum = 0,l1 = 0,l2 = 0;
		for (int i = 1;i <= n;i++)
		{
			if (f[i] == 1)
			{
				if (a[i] == a[l1]) sum += a[i];
				l1 = i;
			}
			if (f[i] == 2)
			{
				if (a[i] == a[l2]) sum += a[i];
				l2 = i;
			}
		}
		ans = max(ans,sum);
		return;
	}
	f[x] = 1;
	dfs(x+1);
	f[x] = 2;
	dfs(x+1);
}

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		dfs(1);
		cout << ans << "\n";
		ans = 0;
	}
	
	return 0;
}
