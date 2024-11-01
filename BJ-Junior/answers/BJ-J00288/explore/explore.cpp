#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,m,k;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool can[N][N],vis[N][N];
inline bool inbound(int x,int y){return !(x<1||x>n||y<1||y>m);}
void dfs(int x,int y,int d,int op)
{
	vis[x][y]=1;
	if (op==k) return ;
	int nx=x+dx[d],ny=y+dy[d];
	if (inbound(nx,ny)&&can[nx][ny]) dfs(nx,ny,d,op+1);
	else dfs(x,y,(d+1)%4,op+1);
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		int x0,y0,d;
		cin>>n>>m>>k;
		cin>>x0>>y0>>d;
		char c;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				cin>>c;
				vis[i][j]=0;
				if (c=='.') can[i][j]=1;
				else can[i][j]=0;
			}
		}
		dfs(x0,y0,d,0);
		int ans=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				if (vis[i][j]) ans++;
		cout<<ans<<"\n";
	}
	return 0;
}