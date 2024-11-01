#include<bits/stdc++.h>
using namespace std;
char g[1005][1005];
bool vis[1005][1005];
int n,m,k,ans;
void dfs(int x,int y,int d,int step)
{
	if(step==k+1) return;
	bool fl=0;
	if(step==k) fl=1;
	int nx,ny;
	if(d==0)
	{
		nx=x;
		ny=y+1;
	}
	if(d==1)
	{
		nx=x+1;
		ny=y;
	}
	if(d==2)
	{
		nx=x;
		ny=y-1;
	}
	if(d==3)
	{
		nx=x-1;
		ny=y;
	}
	if(nx<1||nx>n||ny<1||ny>m||g[nx][ny]=='x') dfs(x,y,(d+1)%4,step+1);
	else
	{
		if(fl) return;
		if(!vis[nx][ny]) ans++;
		vis[nx][ny]=true;
		dfs(nx,ny,d,step+1);
	}
	return;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(vis,false,sizeof(vis));
		memset(g,'.',sizeof(g));
		ans=1;
		scanf("%d%d%d",&n,&m,&k);
		int x0,y0,d0;
		char c;
		scanf("%d%d%d",&x0,&y0,&d0);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%c",&c);
				g[i][j]=c;
			}
		}
		vis[x0][y0]=true;
		dfs(x0,y0,d0,0);
		printf("%d\n",ans);
	}
	return 0;
}
