#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int ans=0,n,m,k;
bool g[N][N],vis[N][N];
const int nxtx[7]={0,1,0,-1},nxty[7]={1,0,-1,0};
inline void Solve(int x,int y,int d,int step)
{
	if(x<1||x>n||y<1||y>m||d<0||d>3)
		return;
	if(!vis[x][y])
		ans++;
	vis[x][y]=1;
	if(step==k)
		return;
	int nx=x+nxtx[d],ny=y+nxty[d];
	if(nx<1||nx>n||ny<1||ny>m||g[nx][ny]==0)
	{
		d=(d+1)%4;
		Solve(x,y,d,step+1);
	}
	else
		Solve(nx,ny,d,step+1);
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t,x,y,d,step;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			for(int j=1;j<=m;j++)
			{
				if(s[j-1]=='x')
					g[i][j]=0;
				else
					g[i][j]=1;
				vis[i][j]=0;
			}
		}
		ans=0;
		step=0;
		while(step<k)
		{
			if(!vis[x][y])
				++ans;
			vis[x][y]=1;
			int nx=x+nxtx[d],ny=y+nxty[d];
			if(nx<1||nx>n||ny<1||ny>m||g[nx][ny]==0)
			{
				d=(d+1)%4;
			}
			else
			{
				x=nx;
				y=ny;
			}
			++step;
		}
		if(!vis[x][y])
			++ans;
		cout<<ans<<'\n';
	}
	return 0;
}