#include <iostream>
#include <cstring>
using namespace std;

int t, n, m, k, x, y, d;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
char a[1005][1005];
bool f[1005][1005];

int solve()
{
	memset(f, 0, sizeof f);
	int ti = k, ans = 0;
	f[x][y] = true;
	while (ti--)
	{
		int nx = dx[d] + x, ny = dy[d] + y;
		if (1 > nx || n < nx || 1 > ny || m < ny || a[nx][ny] == 'x') {
			d = (d + 1) % 4; 
			continue;
		}
		f[nx][ny] = true;
		x = nx, y = ny;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) ans += f[i][j];
	return ans;
}

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> k >> x >> y >> d;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) cin >> a[i][j];
		cout << solve() << "\n";
	}
	return 0;
}