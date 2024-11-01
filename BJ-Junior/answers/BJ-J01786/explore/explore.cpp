#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int t,n,m,k,sx,sy,sd,nowx,nowy,nowd,ans;
int mp[N][N];
int fx[8] = {0,1,1,0,0,-1,-1,0};//fangxiang
bool vis[N][N];
bool check(int x,int y)
{
	if (x < 1 || x > n) return 0;
	if (y < 1 || y > m) return 0;
	if (mp[x][y] == 1) return 0;
	return 1;
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	char c;
	scanf("%d",&t);
	while (t--)
	{
		ans = 0;
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&sx,&sy,&sd);
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= m;j++)
			{
				vis[i][j] = 0;
				scanf(" %c",&c);
				c == '.' ? mp[i][j] = 0 : mp[i][j] = 1;
			}
		}
		nowx = sx;
		nowy = sy;
		nowd = sd;
		vis[sx][sy] = 1;
		ans++;
		for (int i = 1;i <= k;i++)
		{
			//cout<<"now="<<nowx<<","<<nowy<<'\n';
			//cout<<"nowd="<<nowd<<'\n';
			if (check(nowx+fx[nowd*2],nowy+fx[nowd*2+1]))
			{
				nowx = nowx+fx[nowd*2];
				nowy = nowy+fx[nowd*2+1];
				if (!vis[nowx][nowy])
				{
					ans++;
					vis[nowx][nowy] = 1;
				}
			}
			else
			{
				nowd = (nowd+1)%4;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
