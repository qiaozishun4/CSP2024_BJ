#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d;
int nxtx[]={0,1,0,-1};
int nxty[]={1,0,-1,0};
char mp[1005][1005];
bool vis[1005][1005];
bool insd(int a,int b)
{
	if(a<1)return false;
	if(a>n)return false;
	if(b<1)return false;
	if(b>m)return false;
	return true;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>mp[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				vis[i][j]=false;
			}
		}
		vis[x][y]=true;
		for(int i=1;i<=k;i++)
		{
			int nx=x+nxtx[d];
			int ny=y+nxty[d];
			bool flag=true;
			if(insd(nx,ny)==false)
			{
				flag=false;
			}
			else if(mp[nx][ny-1]=='x')
			{
				flag=false;
			}
			if(flag)
			{
				x=nx,y=ny;
				vis[x][y]=true;
			}
			else
			{
				d=(d+1)%4;
			}
		}
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
		cout<<ans<<endl;
	}
	return 0;
}
