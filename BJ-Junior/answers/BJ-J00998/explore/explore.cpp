#include <bits/stdc++.h>
using namespace std;

int T,n,m,k,ans,x,y,d,dx[] = {0,1,0,-1},dy[] = {1,0,-1,0};
char a[1005][1005];
bool f[1005][1005];

int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n >> m >> k >> x >> y >> d;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++) cin >> a[i][j];
		memset(f,0,sizeof f);
		ans = 0;
		f[x][y] = 1;
		while (k--) {
			int nx = x + dx[d],ny = y + dy[d];
			if (nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == 'x') d = (d + 1) % 4;
			else x = nx,y = ny,f[x][y] = 1;
		}
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= m;j++)
				if (f[i][j]) ans++;
		cout << ans << endl;
	}
	return 0;
}