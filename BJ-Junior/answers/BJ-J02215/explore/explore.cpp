#include<bits/stdc++.h>
using namespace std;
bool vis[1010][1010];
bool zt[1010][1010];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;cin >> T;
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		memset(zt,0,sizeof(zt));
		int n,m,k;cin >> n >> m >> k;
		int x,y,d;cin >> x >> y >> d;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				char c;cin >> c;
				if(c=='.')
					zt[i][j]=1;
			}
		for(int i=1;i<=k;i++)
		{
			vis[x][y]=1;
			int nx,ny;
			if(d==0)
				nx=x,ny=y+1;
			if(d==1)
				nx=x+1,ny=y;
			if(d==2)
				nx=x,ny=y-1;
			if(d==3)
				nx=x-1,ny=y;
			if(nx>=1 && nx<=n && ny>=1 && ny<=m && zt[nx][ny])
				x=nx,y=ny;
			else
				d=(d+1)%4;
		}
		vis[x][y]=1;
		long long sum=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
					sum += vis[i][j];
		cout << sum << endl;
	}
	return 0;
}
