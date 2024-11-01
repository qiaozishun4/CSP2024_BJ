#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool vis[1005][1005];
int dx[10]={0,1,0,-1};
int dy[10]={1,0,-1,0};
//感谢老天爷
bool check(int x,int y,int n,int m)
{
	return (x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]!='x');
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	for (int t=1;t<=T;t++)
	{
		int sum=1;
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		int n,m;
		int k;
		cin>>n>>m;
		cin>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		vis[x][y]=1;
		for (int i=1;i<=k;i++)
		{
			if (check(x+dx[d],y+dy[d],n,m))
			{
				if (!vis[x+dx[d]][y+dy[d]])
				{
					sum++;
					vis[x+dx[d]][y+dy[d]]=1;
				}
				x=x+dx[d];
				y=y+dy[d];
			}
			else
			{
				d=(d+1)%4;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
