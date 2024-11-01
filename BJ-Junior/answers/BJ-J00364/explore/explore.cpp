#include <bits/stdc++.h>
using namespace std;
#define _for(i, a, b) for(int i = a, IM = b; i <= IM; i ++)
#define _rep(i, a, b) for(int i = a, IM = b; i >= IM; i --)
#define endl '\n'
#define _mp(a, b) make_pair(a, b)
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int N = 1009, M = 1000009, mod = 1e9 + 7, inf = 1e9;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char a[N][N];
bool vis[N][N];
void solved() {
	int n, m, k;	cin >> n >> m >> k;
	int x, y, d;	cin >> x >> y >> d;
	_for(i, 1, n) _for(j, 1, m) cin >> a[i][j];
	vis[x][y] = true;
	while(k --) {
		int fx = x + dx[d], fy = y + dy[d];
		if(fx < 1 || fx > n || fy < 1 || fy > m || a[fx][fy] == 'x') {
			d = (d + 1) % 4;
		} else {
			x = fx, y = fy;
		}
		vis[x][y] = true;
	}
	int ans = 0;
	_for(i, 1, n) _for(j, 1, m) {
		ans += vis[i][j];
		vis[i][j] = false;
	}
	cout << ans << endl;
	return ;
}
int main() {
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(6);
	int ttx;	cin >> ttx;	while(ttx --)
	solved();
	return 0;
}
