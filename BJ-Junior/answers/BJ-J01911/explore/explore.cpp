#include <bits/stdc++.h>
using namespace std;

long long n,m;
char g[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
map<long long,long long> mp;
void dfs(long long x,long long y,long long d,long long k)
{
	int j1=k-1,nx=x+dx[d],ny=y+dy[d];
	if(k==0)
	{
		return ;
	}
	while(nx>n||nx<1||ny>m||ny<1||g[nx][ny]=='x')
	{
		d++;
		if(j1==0)
		{
			return ;
		}
		if(d>=4)
		{
			d=0;
		}
		j1--;
		nx=x+dx[d],ny=y+dy[d];
	}
	mp[nx*1000+ny]++;
	dfs(nx,ny,d,j1);
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,k,x2,y2,d0;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		mp.clear();
		cin>>n>>m>>k>>x2>>y2>>d0;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				cin>>g[j][k];
			}
		}
		mp[x2*1000+y2]++;
		dfs(x2,y2,d0,k);
		cout<<mp.size()<<endl;
	}
	return 0;
}
