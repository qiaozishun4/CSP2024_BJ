#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
bool vis[N][N];
int n,m,k;
char s[N][N];
void dfs(int x,int y,int d,int cnt,int i)
{
	if(!vis[x][y])
	{
		cnt++;
		vis[x][y]=1;
		//cout <<"x:"<<x<<" y："<<y<<"\n";
	}
	if(i==k)
	{
		//cout <<"i:"<<i<<"\n";
		cout <<cnt<<"\n";
		return;
	}
	int nx,ny;
	if(d==0)	{nx=x;		ny=y+1;}
	if(d==1)	{nx=x+1;	ny=y;}
	if(d==2)	{nx=x;		ny=y-1;}
	if(d==3)	{nx=x-1;	ny=y;}
	if(nx>n||nx<1||ny>m||ny<1||s[nx][ny]=='x')
	{
		d++;
		d%=4;
		dfs(x,y,d,cnt,i+1);
		return;
	}
	dfs(nx,ny,d,cnt,i+1);
	return;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin >>t;
	while(t--)
	{
		cin >>n>>m>>k;
		int x,y,d;
		cin >>x>>y>>d;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin >>s[i][j];
			}
		}
		dfs(x,y,d,0,0);
	}
	return 0;
}
