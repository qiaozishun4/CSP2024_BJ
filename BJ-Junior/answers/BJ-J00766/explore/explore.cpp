#include<bits/stdc++.h>
using namespace std;
int n,m,t,i,j,ans,x,y,d,k;
bool vis[1003][1003];
char mp[1003][1003];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		ans = 1;
		cin>>n>>m>>k>>x>>y>>d;
		vis[x][y] = 1;
		for(i = 1;i<=n;i++)
		{
			for(j = 1;j<=m;j++)
			{
				cin>>mp[i][j];
				mp[0][j] = mp[n+1][j] = '#';
			}
			mp[i][0] = mp[i][m+1] = '#';
		}
		while(k--)
		{
			if(d == 0)
			{
				if(mp[x][y+1]=='.')y++;
				else d = 1;
			}
			else if(d == 1)
			{
				if(mp[x+1][y]=='.')x++;
				else d = 2;
			}
			else if(d == 2)
			{
				if(mp[x][y-1]=='.')y--;
				else d = 3;
			}
			else if(d == 3)
			{
				if(mp[x-1][y]=='.')x--;
				else d = 0;
			}
			if(!vis[x][y])ans++;
			vis[x][y] = 1;
		}
		cout<<ans<<'\n';
	}
}