#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5;
char mp[N][N];
bool vis[N][N];
int n,m,k;
int h=0;
int mx[4]={0,1,0,-1};
int my[4]={1,0,-1,0};
bool ok(int x,int y)
{
	if(!(x>=1&&x<=n)) return 0;
	if(!(y>=1&&y<=m)) return 0;
	return mp[x][y]=='.';
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>mp[i][j];
		
		int ans=1;
		
		memset(vis,0,sizeof(vis));
		vis[x][y]=1;
		for(int i=0;i<k;i++)
		{
			int willx=x+mx[d],willy=y+my[d];
			if(!ok(willx,willy))
			{
				++d;
				d%=4;
			}
			else
			{
				x=willx;
				y=willy;
			}
			if(!vis[x][y])
			{
				vis[x][y]=1;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}