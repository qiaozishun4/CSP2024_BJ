#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m,k,x,y,d;
int dx[5]={0,1,0,-1},dy[5]={1,0,-1,0};
char a[N][N];
bool vis[N][N];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		int ans=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j],vis[i][j]=0;
		vis[x][y]=1;
		for(int i=1;i<=k;i++)
		{
			int nx=x+dx[d],ny=y+dy[d];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]=='.')
			{
				if(vis[nx][ny]==0) ans++;
				vis[nx][ny]=1;
				x=nx,y=ny;
			}
			else
			{
				d=(d+1)%4;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
