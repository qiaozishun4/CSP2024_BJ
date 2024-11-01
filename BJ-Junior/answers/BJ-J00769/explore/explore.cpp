#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=1e3+5;
int t,n,m,k,x,y,xx,yy,d,ans;
bool vis[N][N];
char mp[N][N];
signed main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(cin>>t;t;t--)
	{
		ans=0;
		cin>>n>>m>>k>>x>>y>>d;
		vis[x][y]=true;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>mp[i][j];
			}
		}
		for(int i=1;i<=k;i++)
		{
			if(d==0)
			{
				xx=x;
				yy=y+1;
			}
			else if(d==1)
			{
				xx=x+1;
				yy=y;
			}
			else if(d==2)
			{
				xx=x;
				yy=y-1;
			}
			else
			{
				xx=x-1;
				yy=y;
			}
			if(1<=xx&&xx<=n&&1<=yy&&yy<=m&&mp[xx][yy]!='x')
			{
				x=xx;
				y=yy;
			}
			else
			{
				d++;
				d%=4;
			}
			vis[x][y]=true;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(vis[i][j])
				{
					ans++;
					vis[i][j]=false;
				}
			}
		}
		cout<<ans<<"\n";
	}
	exit(0);
}