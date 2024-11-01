#include <bits/stdc++.h>
using namespace std;
const int N=1010;
bool vis[N][N][4];
long long n,m,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char a[N][N];
void dfs(long long x,long long y,long long d,long long k)
{             
	if(vis[x][y][d]==true)
	{
		return ;
	}
	vis[x][y][d]=true;
	if(k==0)
	{
		return ;
	}
	long long nx=x+dx[d],ny=y+dy[d],nd=d;
	if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]=='.')
	{
		dfs(nx,ny,d,k-1);
		return ;
	}
	else
	{
		nd=(nd+1)%4;
		dfs(x,y,nd,k-1);
		return ;
	}
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(false);
	long long t;
	cin>>t;
	while(t--)
	{
		long long k;
		cin>>n>>m>>k;
		long long xx,yy,dd;
		cin>>xx>>yy>>dd;
		memset(vis,0,sizeof(vis));
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		dfs(xx,yy,dd,k);
		long long cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(vis[i][j][0]||vis[i][j][1]||vis[i][j][2]||vis[i][j][3])
				{
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}