#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 2e5 + 10;
const LL INF = 1e18;
int n;
int a[N], b[N];
struct Node{
	int l, r;
	LL mx;
}tr[N * 4];

void pushup(int u) {
	tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
}

void build(int u, int l, int r) {
	tr[u].l = l, tr[u].r = r, tr[u].mx = -INF;
	if (l == r) {
		if (l == 0) tr[u].mx = 0;
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

void update(int u, int l, LL x) {
	if (tr[u].l == tr[u].r) {
		tr[u].mx = max(tr[u].mx, x);
		return;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if (l < mid) update(u << 1, l, x);
	else update(u << 1 | 1, l, x);
	pushup(u);
}

LL query(int u, int l) {
	if (tr[u].l == tr[u].r) return tr[u].mx;
	int mid = tr[u].l + tr[u].r >> 1;
	if (l < mid) return query(u << 1, l);
	else return query(u << 1 | 1, l);
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T -- ) {
		cin >> n;
		for (int i = 1; i <= n; i ++ ) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b + 1, b + n + 1);
		for (int i = 1; i <= n; i ++ ) {
			a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
			// cout << a[i] << ' ';
		}
		build(1, 0, n);
		LL add = 0;
		for (int i = 1; i < n; i ++ ) {
			int t = (a[i] == a[i + 1] ? b[a[i]] : 0);
			add += t;
			LL k = max(tr[1].mx, query(1, a[i + 1]) + b[a[i + 1]]) - t;
			update(1, a[i], k);
			//cout << a[i] << ' ' << k << '\n';
		}
		cout << max(0ll, tr[1].mx + add) << '\n';
	}
	return 0;
}
