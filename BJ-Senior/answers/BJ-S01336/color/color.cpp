#include <bits/stdc++.h>
#define ll long long
#define inf 1e18
using namespace std;

const int N = 1000010;
int T, n, a[N];
ll d, mx, f[N];
void Max(ll &x, ll y) {if (x < y) x = y; }

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i=1; i<=n; ++i) cin >> a[i];
		f[0] = 0;
		for (int i=1; i<=1000000; ++i) f[i] = -inf;
		d = mx = 0;
		for (int i=1; i<=n; ++i) {
			ll tmp = max(mx, f[a[i]] + a[i]) + d;
			if (a[i] == a[i - 1]) d += a[i];
			Max(f[a[i - 1]], tmp - d), Max(mx, tmp - d);
			//for (int j=0; j<=10; ++j) cout << f[j] << " ";
			//	cout << "\n";
		}
		cout << mx + d << "\n";
	}
	return 0;
}