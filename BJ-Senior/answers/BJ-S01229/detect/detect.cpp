#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef array<int, 2> arr;
const int N = 1e5 + 10;
int n, m, len, V;
int v[N], a[N], d[N];
int p[N];
int l[N], r[N];
vector<arr> b;

bool check(int i, int pos) {
	int k = p[pos] - d[i];
	LL su = 1ll * v[i] * v[i] + 2ll * a[i] * k;
	return su > 1ll * V * V;
}

void init() {
	b.clear();
	for (int i = 1; i <= n; i ++ ) l[i] = r[i] = 0;
}

bool cmp(arr x, arr y) {
	return x[1] < y[1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int T;
	cin >> T;
	while (T -- ) {
		init();
		cin >> n >> m >> len >> V;
		for (int i = 1; i <= n; i ++ ) cin >> d[i] >> v[i] >> a[i];
		for (int i = 1; i <= m; i ++ ) cin >> p[i];
		int ans1 = 0, ans2 = 0;
		for (int i = 1; i <= n; i ++ ) {
			if (d[i] > p[m]) continue;
			if (a[i] >= 0) {
				if (check(i, m)) {
					ans1 ++;
					int ll = 1, rr = m;
					while (ll < rr) {
						int mid = ll + rr >> 1;
						if (p[mid] < d[i]) ll = mid + 1;
						else if (check(i, mid)) rr = mid;
						else ll = mid + 1;
					}
					l[i] = ll, r[i] = m;
				}
			}
			else {
				int pos = lower_bound(p + 1, p + m + 1, d[i]) - p;
				if (check(i, pos)) {
					ans1 ++;
					l[i] = pos;
					int ll = pos, rr = m;
					while (ll < rr) {
						int mid = ll + rr + 1 >> 1;
						if (check(i, mid)) ll = mid;
						else rr = mid - 1;
					}
					r[i] = ll;
				}
			}
		}
		
		for (int i = 1; i <= n; i ++ )
			if (l[i]) b.push_back((arr){l[i], r[i]});
		sort(b.begin(), b.end(), cmp);
		int now = 0;
		for (int i = 0; i < b.size(); i ++ ) {
			// cout << b[i][0] << ' ' << b[i][1] << ' ' << now << '\n';
			if (now >= b[i][0]) continue;
			ans2 ++;
			now = b[i][1];
		}
		cout << ans1 << ' ' << m - ans2 << '\n';
	}
	return 0;
}
