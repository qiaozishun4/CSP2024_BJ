#include <bits/stdc++.h>
using namespace std;

const int maxn=1e3+5;
char a[maxn][maxn];
int vis[maxn][maxn];
int T,n,m,k,x,y,d,ans=0;
int step[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while (T--)
	{
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		ans=1,vis[x][y]=1;
		for (int i=0;i<n;i++) cin>>a[i];
		while (k--)
		{
			int nx,ny;
			nx=x+step[d][0],ny=y+step[d][1];
			if (1<=nx&&nx<=n&&1<=ny&&ny<=m&&a[nx-1][ny-1]=='.'){
				x=nx;
				y=ny;
				if (!vis[x][y]){
					vis[x][y]=1;
					ans++;
				}
			}
			else d=(d+1)%4;
		}
		if (T) cout<<ans<<endl;
		else cout<<ans;
	}
	return 0;
}

