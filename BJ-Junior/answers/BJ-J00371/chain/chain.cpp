#include <bits/stdc++.h>
using namespace std;

int t,n,k,q,l[100005],a[1005][2005];
bool dfs(int x,int y,int lst)
{
	if (x == 1)
	{
		for (int i = 1;i <= n;i++)
		{
			if (i == lst) continue;
			for (int j = 1;j <= l[i];j++)
			{
				if (a[i][j] == 1)
				{
					for (int r = j+1;r <= min(l[i],j+k-1);r++)
					{
						if (a[i][r] == y) return true;
					}
				}
			}
		}
		return false;
	}
	for (int i = 1;i <= n;i++)
	{
		if (i == lst) continue;
		for (int j = 1;j <= l[i];j++)
		{
			if (a[i][j] != y) continue;
			for (int r = max(1,j-k+1);r < j;r++)
			{
				if (dfs(x-1,a[i][r],i) == true) return true;
			}
		}
	}
	return false;
}

int main()
{
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin >> t;
	while (t--)
	{
		cin >> n >> k >> q;
		for (int i = 1;i <= n;i++)
		{
			cin >> l[i];
			for (int j = 1;j <= l[i];j++)
			{
				cin >> a[i][j];
			}
		}
		while (q--)
		{
			int r,c;
			cin >> r >> c;
			if (dfs(r,c,0) == true) cout << "1\n";
			else cout << "0\n";
		}
	}
	
	return 0;
}
