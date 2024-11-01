#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 1e6 + 10;

int T;
int n;
int a[maxn];
int c[maxn];

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	memset(c, 0, sizeof c);
	int ans = 0;
	for (int i = 0; i < (1 << n); i++)
	{
		int res = 0;
		for (int j = 1; j <= n; j++)
		{
			for (int k = j - 1; k >= 1; k--)
				if (!(((i >> (j - 1)) & 1) ^ ((i >> (k - 1)) & 1)))
				{
					if (a[j] == a[k]) c[j] = a[k];
					else c[j] = 0;
					break;
				}
			res += c[j];
		}
		ans = max(res, ans);
	}
	cout << ans << "\n";

}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> T;
	while (T--) solve();	
	return 0;
}