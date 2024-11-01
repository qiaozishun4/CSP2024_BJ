#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int n,m,k,sx,sy,dis[N][N];
char g[N][N];
bool vis[N][N];
struct node{
	int x,y,step;
};
void bfs(int x)
{
	queue<node> q;
	q.push((node){sx,sy,x});
	vis[sx][sy]=1;
	int nx,ny,num=0;
	while(!q.empty())
	{
		node cur=q.front();
		int i=cur.step;
		q.pop();
		for(int j=0;j<4;j++)
		{
			nx=cur.x+dx[i];
			ny=cur.y+dy[i];
			if(nx<1||nx>n||ny<1||ny>m||g[nx][ny]=='x'||vis[nx][ny])
			{
				num++;
				i=(i+1)%4;
				continue;
			}
			if(dis[cur.x][cur.y]+num>k)
			{
				i=(i+1)%4;
				num=0;
				continue;
			}
			q.push((node){nx,ny,i});
			vis[nx][ny]=1;
			dis[nx][ny]=dis[cur.x][cur.y]+num+1;
			num=0;
			i=(i+1)%4;
		}
	}
	return;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t,d,ans=0;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		cin>>sx>>sy>>d;
		for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					cin>>g[i][j];
		bfs(d);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				ans+=vis[i][j];
		cout<<ans<<endl;
		ans=0;
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
	}
	return 0;
}

