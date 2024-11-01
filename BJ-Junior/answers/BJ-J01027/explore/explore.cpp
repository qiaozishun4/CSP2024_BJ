#include <bits/stdc++.h>
using namespace std;
char s[1007][1007];
int vis[1007][1007];
int vs[1007][1007];
int n,m,cnt;
void dfs(int x,int y,int d,int k)
{
	if (k==0)
	{
		return;
	}
	if (vis[x][y]==0)
	{
		cnt++;
		vis[x][y]=1;
	}
	int nx,ny;
	if (d==0)
	{
		nx=x;
		ny=y+1;
	}
	if (d==1)
	{
		nx=x+1;
		ny=y;
	}
	if (d==2)
	{
		nx=x;
		ny=y-1;
	}
	if (d==3)
	{
		nx=x-1;
		ny=y;
	}
	if (nx<0||ny<0||nx>n||ny>m||s[nx][ny]=='x')
	{
		dfs(x,y,(d+1)%4,k-1);
	}
	else
	{
		dfs(nx,ny,d,k-1);
	}
}
int main()
{
	//freopen("explore.in","r",stdin);
	//freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while (t--)
	{
		int k;
		memset(s,'0',sizeof(s));
		memset(vis,0,sizeof(vis));
		scanf("%d%d%d",&n,&m,&k);
		int x,y,d;
		scanf("%d%d%d",&x,&y,&d);
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				cin>>s[i][j];
			}
		}
		if (k==1)
		{
			int nx,ny;
			if (d==0)
			{
				nx=x;
				ny=y+1;
			}
			if (d==1)
			{
				nx=x+1;
				ny=y;
			}
			if (d==2)
			{
				nx=x;
				ny=y-1;
			}
			if (d==3)
			{
				nx=x-1;
				ny=y;
			}
			if (nx<1||ny<1||nx>n||ny>m||s[nx][ny]=='x')
			{
				cout<<"1"<<endl;
				continue;
			}
			else
			{
				cout<<"2"<<endl;
				continue;
			}
		}
		dfs(x,y,d,k);
		cout<<cnt<<endl;
		cnt=0;
	}
	return 0;
}
