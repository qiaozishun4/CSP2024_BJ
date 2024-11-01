#include<bits/stdc++.h>
using namespace std;
#define int long long
char g[1005][1005];
bool vis[1005][1005];
void sol(int n,int m,int x,int y,int d,int step,int k,int ans)
{
	if(step==k) 
	{
		cout<<ans<<endl;
		return;
	}
	step++;
	int nx,ny;
	if(d==0) nx=x,ny=y+1;
	else if(d==1) nx=x+1,ny=y;
	else if(d==2) nx=x,ny=y-1;
	else nx=x-1,ny=y;
	if((nx<1||nx>n||ny<1||ny>m)||g[nx][ny]=='x') 
		sol(n,m,x,y,(d+1)%4,step,k,ans);
	else 
	{
		x=nx,y=ny;
		if(!vis[x][y]) ans++;
		vis[x][y]=true;
		sol(n,m,x,y,d,step,k,ans);
	}
	return;
}
signed main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,n,m,k,sx,sy,d,i,j;
	cin>>t;
	while(t--)
	{
		for(i=1;i<=1005;i++)for(j=1;j<=1005;j++)g[i][j]=' ';
		for(i=1;i<=1005;i++)for(j=1;j<=1005;j++)vis[i][j]=0;
		cin>>n>>m>>k>>sx>>sy>>d;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cin>>g[i][j];
			}
		}
		sol(n,m,sx,sy,d,0,k,1);
	}
	return 0;
}
