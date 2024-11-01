#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,ans=0,T,K,sx,sy,sd;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool vis[N][N];
char g[N][N];
/*
void dfs(int x,int y,int dir,int k)
{
	if(k==0)
	{
		return;
	}
	if(!vis[x][y])	ans++;
	vis[x][y]=1;
	int nx=x+dx[dir],ny=y+dy[dir];
	if(nx<1 or nx>n or ny<1 or ny>m or g[nx][ny]=='x')
	{
		return dfs(x,y,(dir+1)%4,k-1);
	}
	else
	{
		return dfs(nx,ny,dir,k-1);
	}
}
*/
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++)
    {
		memset(vis,0,sizeof(vis));
		ans=1;
		cin>>n>>m>>K;
		cin>>sx>>sy>>sd;
		vis[sx][sy]=1;
		//swap(n,m);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>g[i][j];
			}	
		}
		
		int x=sx,y=sy,dir=sd;
		while(K--)
		{
			int nx=x+dx[dir],ny=y+dy[dir];
			if(nx<1||nx>n||ny<1||ny>m||g[nx][ny]=='x')
			{
				dir=(dir+1)%4;
			}
			else if(g[nx][ny]=='.')
			{
				if(!vis[nx][ny])
				{
					ans++;
					vis[nx][ny]=1;
				}
				x=nx,y=ny;
			}
		}
		//dfs(sx,sy,sd,K);
		cout<<ans<<endl;
	}
    

    return 0;
}
