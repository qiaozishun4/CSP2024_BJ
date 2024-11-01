#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
const int MOD=4;
char a[N][N];
int n,m,k;
int dis[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int vis[N][N];

void dfs(int x,int y,int cnt,int d)
{
	for(int i=1;i<=k;i++)
	{
		int nx=x+dis[d][0];
		int ny=y+dis[d][1];
		if(nx<1||nx>n||ny<1||ny>m) 
		{
			d++;
			d%=MOD;
		}
		else if(a[nx][ny]=='x')
		{
			d++;
			d%=MOD;
		}
		else
		{
			if(vis[nx][ny]==1)
			{
				x=nx;
				y=ny;
			}
			else
			{
				vis[nx][ny]=1;
				x=nx;
				y=ny;
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
}

int main()
{
	freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		vis[x][y]=1;
		dfs(x,y,1,d);
	}
	return 0;
}
