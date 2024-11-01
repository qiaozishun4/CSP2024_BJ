#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool v[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T,n,m,k,x,y,d;
	cin>>T;
	while (T--)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				cin>>a[i][j];
		memset(v,0,sizeof(v));
		int ans=1;
		v[x][y]=1;
		while (k--)
		{
			int nx,ny;
			nx=x+dx[d];
			ny=y+dy[d];
			if (nx<1||nx>n||ny<1||ny>m||a[nx][ny]=='x')
				d=(d+1)%4;
			else
			{
				x=nx;
				y=ny;
				if (!v[x][y])
				{
					v[x][y]=1;
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
