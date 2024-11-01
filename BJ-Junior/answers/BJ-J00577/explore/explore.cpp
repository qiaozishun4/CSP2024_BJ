#include<bits/stdc++.h>
using namespace std;
char g[1001][1001];
int ans=1,n,m;
bool vis[1001][1001];
void dfs(int x,int y,int to,int left)
{
	int nx,ny;
	nx=x;
	ny=y;
	if(left<1)
	{
		return ;
	}
	if(to==0) ny++;
	else if(to==1) nx++;
	else if(to==2) ny--;
	else nx--;
	if(nx<1||ny<1||nx>n||ny>m||g[nx][ny]=='x')
	{
		to++;
		to%=4;
		dfs(x,y,to,left-1);
		return ;
	}
	if(vis[nx][ny]!=1) ans++;
	vis[nx][ny]=1;
	dfs(nx,ny,to,left-1);
	return ;
}
void clean()
{
	int i,j;
	ans=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			vis[i][j]=0;
		}
	}
	return ;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
    int t,x,y,k,i,j,z;
    string s;
    cin>>t;
    while(t--)
    {
		cin>>n>>m>>k>>x>>y>>z;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cin>>g[i][j];
			}
		}
		vis[x][y]=1;
		dfs(x,y,z,k);
		cout<<ans<<endl;
		clean();
	}
    return 0;
}
