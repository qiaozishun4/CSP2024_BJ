#include <bits/stdc++.h>

using namespace std;

int t,n,m,k,d;

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	queue<int> q;
	while(t --)
	{
		int x,y;
		cin >> n >> m >> k >> x >> y >> d;
		char mp[n+1][m+1];
		bool is[n+1][m+1];
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
			{
				cin >> mp[i][j];
				is[i][j] = false;
			}
		int ans = 1;
		while(k --)
		{
			int l=x,r=y;
			if (d == 0)
				r = y+1;
			else if (d == 1)
				l = x+1;
			else if (d == 2)
				r = y-1;
			else
				l = x-1;
			if (mp[l][r]=='.' && l>=1 && l<=n && r>=1 && r<=m)
			{
				x = l;
				y = r;
				if (is[l][r] == false)
					ans ++;
				is[l][r] = true;
			}
			else
				d = d+1 % 4;
		}
		q.push(ans);
	}
	while(!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
	return 0;
}
