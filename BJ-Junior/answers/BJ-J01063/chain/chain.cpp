#include<iostream>
#include<vector>
using namespace std;
int T, n, k, q;
vector<int> s[200005];
int c, r;
struct node {
	int w, p;
};
vector<node> wei[200005];
bool dfs(int x, int cnt, int pre)
{
	if (x == c && cnt == r)
		return true;
	if (cnt >= r)
		return false;
	for (int y = 0; y < wei[x].size(); y++) {
		int i = wei[x][y].w;
		int u = wei[x][y].p;
		if (i == pre)
			continue;
		for (int v = u + 1; v - u < k && v < s[i].size(); v++)
			if (dfs(s[i][v], cnt + 1, i))
				return true;
	}
	return false;
}
void work()
{
	for (int i = 0; i < 200005; i++)
		wei[i].clear();
	cin >> n >> k >> q;
	for (int i = 1; i <= n; i++) {
		s[i].clear();
		int l;
		cin >> l;
		while (l--) {
			int x;
			cin >> x;
			s[i].push_back(x);
			wei[x].push_back(node{i, s[i].size() - 1});
		}
	}
	while (q--) {
		cin >> r >> c;
		cout << dfs(1, 0, -1) << "\n";
	}
}
int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	while (T--)
		work();
	return 0;
}