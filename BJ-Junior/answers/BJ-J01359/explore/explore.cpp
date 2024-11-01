#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int t;
int n,m,k;
int x,y,d;
char a[N][N];
int dx[10]={0,1,0,-1};
int dy[10]={1,0,-1,0};
bool flag[N][N];
int ans;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(flag,0,sizeof(flag));
		ans=0;
		scanf("%d%d%d",&n,&m,&k);	
		scanf("%d%d%d",&x,&y,&d);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		flag[x][y]=1;
		for(int i=1;i<=k;i++)
		{
			int nx=x+dx[d],ny=y+dy[d];
			if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&a[nx][ny]=='.')
			{
				x=nx,y=ny;	
			}
			else
			{
				d=(d+1)%4;
			}
			flag[x][y]=1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(flag[i][j])
				{
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}