#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
char g[1005][1005];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int cnt;
int vis[1005][1005];
void dfs(int c,int x,int y,int d,int ans)
{
	vis[x][y]=1;
	if(c>k)
	{
		return;
	}
	int nx=x+dx[d],ny=y+dy[d];
	if(nx<1||nx>n||ny<1||ny>m||g[nx][ny]=='x')
	{
		dfs(c+1,x,y,(d+1)%4,ans);
	}
	else
	{
		dfs(c+1,nx,ny,d,ans+1);
	}
}
signed main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		cnt=0;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>g[i][j];
			}
		}
		dfs(1,x,y,d,1);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(vis[i][j])
				{
					cnt++;
				}
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
