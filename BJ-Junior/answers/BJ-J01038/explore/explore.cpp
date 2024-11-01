#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5;
int n,m,k,t,xx,yy,dd,ans;
bool book[N][N];
char mp[N][N],js;
int u[]={0,1,0,-1},v[]={1,0,-1,0};
void dfs(int x,int y,int d)
{
	for(int i=1;i<=k;++i)
	{
		book[x][y]=1;
		int xn=x+u[d],yn=y+v[d];
		if(xn>=1&&xn<=n&&yn>=1&&yn<=m&&mp[xn][yn]=='.')
		{
			x=xn,y=yn;
		}
		else
		{
			d=(d+1)%4;
		}
	}
	book[x][y]=1;
}
signed main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	for(cin>>t;t;--t)
	{
		ans=0;
		cin>>n>>m>>k>>xx>>yy>>dd;
		scanf("%c",&js);
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				scanf("%c",&mp[i][j]);
			}
			scanf("%c",&js);
		}
		dfs(xx,yy,dd);
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				if(book[i][j])
				{
					ans++;
					book[i][j]=0;
				}
			}
		}
		cout<<ans<<endl;

	}
	return 0;
}