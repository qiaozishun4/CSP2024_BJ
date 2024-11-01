#include <bits/stdc++.h>
using namespace std;

char a[1005][1005];
bool vis[1005][1005];
int sx[]={0, 1, 0, -1}, sy[]={1, 0, -1, 0};
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	int T;
	cin >> T;
	while(T--){
		memset(a, 0, sizeof(a));
		memset(vis, 0, sizeof(vis));
		int x, y, d, ans=0, n, m, k;
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for(int i=1;i <= n;i++){
			for(int j=1;j <= m;j++){
				cin >> a[i][j];
			}
		}
		// cout << k << "\n";
		for(int i=1;i <= k;i++){
			vis[x][y]=1;
			int nx=x+sx[d], ny=y+sy[d];
			if(nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == 'x') d=(d+1)%4;
			else{
				x=nx;
				y=ny;
			}
			// if(T == 0) cout << x << " " << y << "\n";
		}
		vis[x][y]=1;
		for(int i=1;i <= n;i++){
			for(int j=1;j <= m;j++){
				if(vis[i][j]) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}