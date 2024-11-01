#include <bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,ans,t;
bool vis[1006][1006];
char a[1006][1006];
int dis[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while (t--)
	{
		memset(vis,0,sizeof(vis));
		ans=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		vis[x][y]=1;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		while(k--)
		{
			int nx=x+dis[d%4][0];
			int ny=y+dis[d%4][1];
			if (nx>n||nx<1||ny>m||ny<1||a[nx][ny]=='x')
			{
				d++;
				continue;
			}
			vis[nx][ny]=1;
			x=nx;
			y=ny;
		}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				if(vis[i][j])ans++;
		cout<<ans<<endl;
	}
	return 0;
}
