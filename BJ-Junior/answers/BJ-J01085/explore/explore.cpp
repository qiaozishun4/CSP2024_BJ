#include<bits/stdc++.h>
using namespace std;
int n,m,k,d;
const int N=1e3+5;
char g[N][N];
int ans=0;
void dfs(int x,int y,int d,int c)
{
	if(c==k) exit(0) ;
	if(d==0)
	{
		if(x<0||x>n||y+1<0||y+1>m||g[x][y]=='x')
		{
			c++;
			d=(d+1)%4;
		}
		else
		{
			ans++;
			dfs(x,y+1,d,c++);
		}
	}
	if(d==1)
	{
		if(x+1<0||x+1>n||y<0||y>m||g[x][y]=='x')
		{
			c++;
			d=(d+1)%4;
		}
		else
		{
			ans++;
			dfs(x+1,y,d,c++);
		}
	}
	if(d==2)
	{
		if(x<0||x>n||y-1<0||y-1>m||g[x][y]=='x')
		{
			c++;
			d=(d+1)%4;
		}
		else
		{
			ans++;
			dfs(x,y-1,d,c++);
		}
	}
	if(d==3)
	{
		if(x-1<0||x-1>n||y<0||y>m||g[x][y]=='x')
		{
			c++;
			d=(d+1)%4;
		}
		else
		{
			ans++;
			dfs(x-1,y,d,c++);
		}
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
		int x,y;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>g[i][j];
			}
		}
		dfs(x,y,d,1);
		cout<<ans+1<<"\n";
		ans=0;
		memset(g,0,sizeof(g));
		n=m=k=x=y=d=0;
	}
	return 0;
}
