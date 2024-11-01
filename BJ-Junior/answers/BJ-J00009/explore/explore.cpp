#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool vis[1050][1050];
char a[1050][1050];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k,ans=0;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		memset(vis,0,sizeof(vis));
		ans++;
		vis[x][y]=1;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
		for(int i=1;i<=k;i++)
		{
			int tx=x+dx[d],ty=y+dy[d];
			if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&a[tx][ty]!='x')
			{
				x=tx,y=ty;
				if(!vis[x][y])
				{
					ans++;
					vis[x][y]=1;
				}
			}
			else d=(d+1)%4;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
