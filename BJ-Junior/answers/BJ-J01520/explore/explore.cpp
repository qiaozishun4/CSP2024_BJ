#include<bits/stdc++.h>
using namespace std;

int ans=1,T,n,m,vis[1010][1010],num;
char g[1010][1010];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

void dfs(int x,int y,int d)
{
	if(num==0)
	{
		return ;
	}
	int nx=x+dx[d],ny=y+dy[d];
	if(nx>=1 && nx<=n && ny>=1 && ny<=m && g[nx][ny]=='.')
	{
		
		if(vis[nx][ny]==0)
		{
			//cout<<nx<<" "<<ny<<endl;
			ans++;
			vis[nx][ny]=1;
		}
		num--;
		//ans++;
		dfs(nx,ny,d);
	}
	else
	{
		num--;
		dfs(x,y,(d+1)%4);
	}
}

int main()
{
	int x,y,d;
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--)
    {
		cin>>n>>m>>num>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>g[i][j];
			}
		}
		vis[x][y]=1;
		dfs(x,y,d);
		cout<<ans<<endl;
		ans=1;
		memset(vis,0,sizeof(vis));
	}
    return 0;
}
