#include <iostream>
#include <cstdio>
using namespace std;
int T,n,m,k,x,y,d;
char dt[1010][1010];
bool vis[1010][1010];
int main(void) {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	for (;T--;) {
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				vis[i][j]=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				cin >> dt[i][j];
		vis[x][y]=1;
		for (;k--;) {
			int xx,yy;
			if (d==0) xx=x,yy=y+1;
			if (d==1) xx=x+1,yy=y;
			if (d==2) xx=x,yy=y-1;
			if (d==3) xx=x-1,yy=y;
			if (xx>=1&&xx<=n&&yy>=1&&yy<=m&&dt[xx][yy]=='.') {
				x=xx,y=yy;
				vis[x][y]=1;
			} else {
				d=(d+1)%4;
			}
		}
		int ans=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				ans+=vis[i][j];
		cout << ans << endl;
	}
	return 0;
}