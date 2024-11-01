#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y,d;
	int step;
};
char mp[1010][1010];
int _,res=0;
int n,m,k,vis[1010][1010];
int dix[]={0,1,0,-1};
int diy[]={1,0,-1,0};
void bfs(int xx,int yy,int dd,int smm)
{
	queue<node>q;
	memset(vis,0,sizeof(vis));
	node stt;
	stt.x=xx;
	stt.y=yy;
	stt.d=dd;
	stt.step=0;
	q.push(stt);
	vis[xx][yy]=1;
	res++;
	while (!q.empty())
	{
		if (res==smm) break;
		node f=q.front();
		q.pop();
		if (f.step==k) continue;
		int nwx=f.x+dix[f.d],nwy=f.y+diy[f.d];
		node g;
		if (nwx<1||nwx>n||nwy<1||nwy>m||mp[nwx][nwy]=='x')
		{
			g.x=f.x;
			g.y=f.y;
			g.d=(f.d+1)%4;
			g.step=f.step+1;
			q.push(g);
		}
		else
		{
			g.x=nwx;
			g.y=nwy;
			g.d=f.d;
			g.step=f.step+1;
			q.push(g);
			if (!vis[nwx][nwy])
			{
				vis[nwx][nwy]=1;
				res++;
			}
		}
	}
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>_;
	while (_--)
	{
		cin>>n>>m>>k;
		int xx,yy,dd;
		cin>>xx>>yy>>dd;
		int smm=0;
		for (int i=1;i<=n;i++)
		{
			cin>>(mp[i]+1);
			for (int j=1;j<=m;j++) if (mp[i][j]=='.') smm++;
		}
		res=0;
		bfs(xx,yy,dd,smm);
		cout<<res<<'\n';
	}
	return 0;
}
