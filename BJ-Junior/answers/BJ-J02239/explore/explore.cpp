#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e3+10;
int a[MAXN][MAXN],vis[MAXN][MAXN];
int dis[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
signed main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;cin>>T;
	while(T--) {
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		int n,m,k,x,y,d;cin>>n>>m>>k>>x>>y>>d;
		vis[x][y] = 1;
		for(int i = 1;i<=n;i++) {
			for(int j = 1;j<=m;j++) {
				char c;cin>>c;
				if(c=='x')	a[i][j] = 1;
			}
		}
		//for(int i = 1;i<=n;i++) {
                //        for(int j = 1;j<=m;j++) {
                //                cout<<a[i][j]<<' ';
                //        }
		//	cout<<endl;
                //}
		for(int i = 1;i<=k;i++) {
			int nx = x+dis[d][0],ny = y+dis[d][1],flag = 1;
			if(nx<1||nx>n||ny<1||ny>m)	flag = 0;
			if(a[nx][ny])			flag = 0;
			if(flag) 
				x = nx,y = ny,vis[x][y] = 1;
			else
				d = (d+1)%4;
			//cout<<x<<' '<<y<<' '<<d<<endl;
		}
		int ans = 0;
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=m;j++)
				if(vis[i][j])
					ans++;
		cout<<ans<<endl;
	}
	return 0;
}
