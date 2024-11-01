#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1005;
char a[N][N];
bool v[N][N];
int t, n, m, k, x, y, d, cnt;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
void find(int x, int y, int d, int cnt) {
	if(cnt >= k) return ;
	v[x][y] = 1;
	int rx = x+dx[d];
	int ry = y+dy[d];
	for(int i = 0; i < 4; i++) {
		if(rx>n || rx<1 || ry>m || ry<1 || a[rx][ry] == 'x') {
			d = (d+1)%4;
			rx = x + dx[d];
			ry = y + dy[d];
		}
		else {
			v[rx][ry] = 1;
			find(rx, ry, d, cnt+1);
			break;
		}
	}
}
signed main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin>>t;
	for(int l = 1; l <= t; l++) {
		cin>>n>>m>>k>>x>>y>>d;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				cin>>a[i][j];
			}
		}
		v[1][1] = 1;
		find(1, 1, d, 0);
		int ans = 0;
		for(int i = 1; i <= n; i++)
			for(int j = i+1; j <= m; j++)
				if(v[i][j] == 1) ans++;

		cout<<ans<<endl;
	}
	return 0;
}
