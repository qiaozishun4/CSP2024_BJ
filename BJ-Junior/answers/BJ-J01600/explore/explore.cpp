#include <bits/stdc++.h>
using namespace std;

const long long dx[]={0,1,0,-1};
const long long dy[]={1,0,-1,0};
char mp[1005][1005];
long long vis[1005][1005];
void work()
{
	long long n,m,k;
	cin>>n>>m>>k;
	long long nowx,nowy,d0;
	cin>>nowx>>nowy>>d0;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=m;j++)
		{
			cin>>mp[i][j];
			vis[i][j]=0;
		}
	}
	long long ans=0;
	vis[nowx][nowy]=1;
	ans++;
	while(k--)
	{
		long long nx=0;
		long long ny=0;
		nx=nowx+dx[d0];
		ny=nowy+dy[d0];
		if(!(nx>=1&&nx<=n&&ny>=1&ny<=m&&mp[nx][ny]=='.'))
		{
			d0=(d0+1)%4;
		}
		else
		{
			vis[nx][ny]++;
			nowx=nx;
			nowy=ny;
			if(vis[nx][ny]==1)ans++;
		}
		
		// cout<<"debug"<<" "<<nowx<<" "<<nowy<<endl;
	}
	cout<<ans<<endl;
}
signed main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	long long t;
	cin>>t;
	while(t--)
	{
		work();
	}
	return 0;
}