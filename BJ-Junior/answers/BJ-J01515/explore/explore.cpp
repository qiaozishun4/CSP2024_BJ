#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=0;
const int N=1000+5,M=1000+5;
char a[N][M];
bool vis[N][M];
void D(int x,int y,int d)
{
	if(k==-1)
	{
		return;
	}
	k--;
	if(a[x][y]=='.'&&!vis[x][y])
	{
		ans++;
		vis[x][y]=1;
	}
	if(d==0)	
	{
		if(a[x][y+1]=='.'&&y+1<=m)
		{
			D(x,y+1,d);
		}
		else
		{
			D(x,y,(d+1)%4);
		}
	}
	else if(d==1)
	{
		if(a[x+1][y]=='.'&&x+1<=n)
		{
			D(x+1,y,d);
		}
		else
		{
			D(x,y,(d+1)%4);
		}
	}
	else if(d==2)
	{
		if(a[x][y-1]=='.'&&y-1>=1)
		{
			D(x,y-1,d);
		}
		else
		{
			D(x,y,(d+1)%4);
		}
	}
	else if(d==3)
	{
		if(a[x-1][y]=='.'&&x-1>=1)
		{
			D(x-1,y,d);
		}
		else
		{
			D(x,y,(d+1)%4);
		}
	}
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	int tt=1;
	while(tt<=t)
	{
		cin>>n>>m>>k;
		int x0,y0,d0;
		cin>>x0>>y0>>d0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		D(x0,y0,d0);
		cout<<ans<<endl;
		tt++;
		ans=0;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
	}
	return 0;
}