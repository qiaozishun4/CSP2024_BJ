#include<bits/stdc++.h>
using namespace std;
const int N=1005;
bool mp[N][N],vis[N][N];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	int T,n,m,k,x,y,d;
	char c;
	cin>>T;
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		vis[x][y]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>c;
				if(c=='x')mp[i][j]=1;
				else mp[i][j]=0;
			}
		}
		int ans=1;
		for(int i=1;i<=k;i++)
		{
			int nx=x,ny=y;
			if(d==0)ny++;
			if(d==1)nx++;
			if(d==2)ny--;
			if(d==3)nx--;
			if(nx<1||nx>n||ny<1||ny>m||mp[nx][ny])
			{
				d=(d+1)%4;
				continue;
			}
			if(!vis[nx][ny])ans++,vis[nx][ny]=1;
			x=nx,y=ny;
		}
		cout<<ans<<endl;
	}
	return 0;
}