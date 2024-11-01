#include<bits/stdc++.h>
using namespace std;
const int N=1e3+7;
int n,m,k;
int x,y,d;
int ans;
int dx[7]={0,1,0,-1};
int dy[7]={1,0,-1,0};
bool vis[N][N];
int flag;
char a[N][N];
void dfs(int x,int y,int opp,int move,int dir)
{
//	printf("x=%d,y=%d,opp=%d,move=%d,dir=%d\n",x,y,opp,move,dir);
	if(flag==0)
	{
		vis[x][y]=1;
		if(opp==k)
		{
			ans=move;
			flag=1;
			return;
		}
		int nx=dx[dir]+x;
		int ny=dy[dir]+y;
		if(nx<1 or nx>n or ny<1 or ny>m or a[nx][ny]=='x')
		{
			dfs(x,y,opp+1,move,(dir+1)%4);
		}
		if(vis[nx][ny]==1)
		{
			dfs(nx,ny,opp+1,move,dir);
		}
		vis[nx][ny]=1;
		dfs(nx,ny,opp+1,move+1,dir);
		vis[nx][ny]=0;
		vis[x][y]=0;
	}
	else
	{
		return;
	}
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		flag=0;
		ans=0;
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>a[i][j];
			}
		}
		dfs(x,y,0,1,d);
		cout<<ans<<endl;
	}
	return 0;
}
