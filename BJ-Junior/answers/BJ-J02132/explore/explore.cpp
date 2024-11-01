#include<bits/stdc++.h>
using namespace std;
bool vis[1010][1010];
char mp[1010][1010];
int n,m,k;
void dfs(int x,int y,int d,int k0)
{
	if(k0>k)
	{
		return ;
	}
	vis[x][y]=true;
	if(1<=x&&x<=n&&1<=y&&y<=m&&mp[x][y]=='.')
	{
		if(d==0)
		{
			if(!(1<=x&&x<=n&&1<=y+1&&y+1<=m))
			{
				d=(d+1)%4;
				dfs(x,y,d,k0+1);
			}
			else
			{
				dfs(x,y+1,d,k0+1);
			}
		}
		else if(d==1)
		{
			if(!(1<=x+1&&x+1<=n&&1<=y&&y<=m))
			{
				d=(d+1)%4;
				dfs(x,y,d,k0+1);
			}
			else
			{
				dfs(x+1,y,d,k0+1);
			}
		}
		else if(d==2)
		{
			if(!(1<=x&&x<=n&&1<=y-1&&y-1<=m))
			{
				d=(d+1)%4;
				dfs(x,y,d,k0+1);
			}
			else
			{
				dfs(x,y-1,d,k0+1);
			}
		}
		else
		{
			if(!(1<=x-1&&x-1<=n&&1<=y&&y<=m))
			{
				d=(d+1)%4;
				dfs(x,y,d,k0+1);
			}
			else
			{
				dfs(x-1,y,d,k0+1);
			}
		}
	}
	else if(mp[x][y]=='x')
	{
		d=(d+1)%4;
		dfs(x,y,d,k0+1);
	}
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
		cin>>n>>m>>k;
		int x0,y0,d0;
		cin>>x0>>y0>>d0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>mp[i][j];
			}
		}
		vis[1][1]=true;
		dfs(1,1,d0,0);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(vis[i][j])
				{
					ans++;
				}
			}
		}
		cout<<endl<<ans<<endl;
	}
    return 0;
}
