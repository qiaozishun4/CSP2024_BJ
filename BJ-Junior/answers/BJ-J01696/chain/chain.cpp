#include <iostream>
#include <vector>
#include <map>
#include <bitset>

#define PII pair<int, int>
#define fst first
#define scd second
#define mkp(a, b) make_pair(a, b)

using namespace std;

const int maxn = 2e5 + 10;

int T;
int n, k, q;
int cnt[maxn];
vector<int> vec[maxn];
vector<PII> num[maxn];
map<PII, int> mp;
int tot;
bool dp[105][maxn];

void init()
{
	mp.clear();
	for (int i = 1; i <= n; i++) vec[i].clear();
	for (int i = 0; i < maxn; i++) num[i].clear();
}
void solve()
{
	cin >> n >> k >> q;
	init();
	for (int i = 1; i <= n; i++)
	{
		cin >> cnt[i];
		for (int j = 1; j <= cnt[i]; j++)
		{
			int x;
			cin >> x;
			vec[i].push_back(x);
			num[x].push_back({ i, j });
			mp[mkp(i, j)] = ++tot;
		}
	}
	for (int i = 0; i < num[1].size(); i++)
	{
		int x = num[1][i].fst, y = num[1][i].scd;
		if (y + 1 > cnt[x]) continue;
		int l = mp[mkp(x, y + 1)], r = mp[mkp(x, min(y + k - 1, cnt[x]))];
		// cout << x << " " << y << " " << l << " " << r << "\n";
		for (int j = l; j <= r; j++)
			dp[1][j] = 1;
	}
	for (int r = 2; r <= 100; r++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < cnt[i]; j++)
			{
				int col = vec[i][j];
				int pos = mp[mkp(i, j + 1)];
				// cout << r - 1 << " " << pos << "\n";
				if (!dp[r - 1][pos]) continue;
				for (int p = 0; p < num[col].size(); p++)
				{
					PII v = num[col][p];
					if (v.fst == i) continue;
					if (v.scd + 1 > cnt[v.fst]) continue;
					int l = mp[mkp(v.fst, v.scd + 1)], _r = mp[mkp(v.fst, min(v.scd + k - 1, cnt[v.fst]))];
					for (int d = l; d <= _r; d++)
						dp[r][d] |= dp[r - 1][pos];
				}
			}
		}
	}
	while (q--)
	{
		int r, c;
		cin >> r >> c;
		int ans = 0;
		for (int i = 0; i < num[c].size(); i++)
		{
			PII j = num[c][i];
			ans |= dp[r][mp[mkp(j.fst, j.scd)]];
		}
		cout << ans << "\n";
	}
}
int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);

	cin >> T;
	while (T--) solve();
	return 0;
}