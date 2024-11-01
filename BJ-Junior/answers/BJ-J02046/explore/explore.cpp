#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,m,k;
char a[1010][1010];
bool vis[1010][1010];
int x,y,d;
int dis[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int cnt;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while (T--)
	{
		cin>>n>>m>>k;
		cnt=0;
		cin>>x>>y>>d;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				cin>>a[i][j];
				vis[i][j]=0;
			}
		}
		cnt++;
		vis[x][y]=1;
		while (k--)
		{
			int nx,ny;
			nx=x+dis[d][0];
			ny=y+dis[d][1];
			if (nx<1 || nx>n || ny<1 || ny>m || a[nx][ny]=='x') 
			{
				d=(d+1)%4;
			}
			else
			{
				x=nx,y=ny;
				if (!vis[x][y])
				{
					cnt++;
					vis[x][y]=1;
				}
			}
		}
		cout<<cnt<<endl;
	}
			
	return 0;
}
