#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 1005;

int T;
int n, m, k;
int x_0, y_0, d_0;
char mp[maxn][maxn];
int vis[maxn][maxn];

int fx[] = { 0, 1, 0, -1 };
int fy[] = { 1, 0, -1, 0 };

bool check(int x, int y)
{
	if (x > n || y > m || x <= 0 || y <= 0) return 1;
	if (mp[x][y] == 'x') return 1;
	return 0;
}
void init()
{
	memset(vis, 0, sizeof vis);
}
void solve()
{
	init();
	cin >> n >> m >> k;
	cin >> x_0 >> y_0 >> d_0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> mp[i][j];
	vis[x_0][y_0] = 1;
	while (k--)
	{
		int tx = x_0 + fx[d_0], ty = y_0 + fy[d_0];
		if (check(tx, ty))
			d_0 = (d_0 + 1) % 4;
		else x_0 = tx, y_0 = ty;
		vis[x_0][y_0] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans += vis[i][j];
	cout << ans << "\n";
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	
	cin >> T;
	while (T--) solve();	
	return 0;
}