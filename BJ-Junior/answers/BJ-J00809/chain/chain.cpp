#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int t, n, k, q, c[200005], li, ri, qi;
bool f[200005][105];
struct node{
	int y, id;
};
vector<node> g[100005];

void dfs(int x, int r, int ii)
{
	if (r > 10) return;
//	cout << x << " " << r << " " << endl;
	f[x][r] = true;
	for (auto t:g[x]) if (ii != t.id) dfs(t.y, r + 1, t.id);
}

int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n >> k >> q;
		for (int i = 1; i <= 1e5; i++) g[i].clear();
		for (int i = 1; i <= n; i++) {
			cin >> li;
			for (int aa = 1; aa <= li; aa++) cin >> c[aa];

			for (int x = 1; x <= li; x++)
			for (int y = 1; y < k && y + x <= li; y++) g[c[x]].push_back({c[x + y], i}); 
		}
		memset(f, 0, sizeof f);
		dfs(1, 0, 0);
		for (int i = 1; i <= q; i++)
		{
			cin >> ri >> qi;
			cout << f[qi][ri] << endl;
		}
	}
	return 0;
}