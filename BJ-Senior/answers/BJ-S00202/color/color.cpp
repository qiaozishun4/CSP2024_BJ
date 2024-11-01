#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const long long inf = 1e16;

int T, n, m, a[N], b[N], c[N];
long long mx[N * 4], lz[N * 4];

void modifyv(int p, int l, int r, int x, long long v) {
	if (l == r) {
		mx[p] = max(mx[p], v);
		return;
	}
	if (lz[p]) {
		mx[p * 2] += lz[p];
		lz[p * 2] += lz[p];
		mx[p * 2 + 1] += lz[p];
		lz[p * 2 + 1] += lz[p];
		lz[p] = 0;
	}
	int mid = l + r >> 1;
	if (x <= mid) {
		modifyv(p * 2, l, mid, x, v);
	} else {
		modifyv(p * 2 + 1, mid + 1, r, x, v);
	}
	mx[p] = max(mx[p * 2], mx[p * 2 + 1]);
}

void modifya(int p, int l, int r, int a, int b, long long v) {
	if (l >= a && r <= b) {
		mx[p] += v;
		lz[p] += v;
		return;
	}
	if (lz[p]) {
		mx[p * 2] += lz[p];
		lz[p * 2] += lz[p];
		mx[p * 2 + 1] += lz[p];
		lz[p * 2 + 1] += lz[p];
		lz[p] = 0;
	}
	int mid = l + r >> 1;
	if (a <= mid) {
		modifya(p * 2, l, mid, a, b, v);
	}
	if (b > mid) {
		modifya(p * 2 + 1, mid + 1, r, a, b, v);
	}
	mx[p] = max(mx[p * 2], mx[p * 2 + 1]);
}

long long query(int p, int l, int r, int x) {
	if (l == r) {
		return mx[p];
	}
	if (lz[p]) {
		mx[p * 2] += lz[p];
		lz[p * 2] += lz[p];
		mx[p * 2 + 1] += lz[p];
		lz[p * 2 + 1] += lz[p];
		lz[p] = 0;
	}
	int mid = l + r >> 1;
	if (x <= mid) {
		return query(p * 2, l, mid, x);
	} else {
		return query(p * 2 + 1, mid + 1, r, x);
	}
}

void work() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	m = unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; i++) {
		c[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
	}
	m++;
	for (int i = 1; i <= m * 4; i++) {
		mx[i] = -inf;
		lz[i] = 0;
	}
	modifyv(1, 1, m, m, 0);
	for (int i = 2; i <= n; i++) {
		long long v = max(mx[1], query(1, 1, m, c[i]) + a[i]);
		if (c[i] == c[i - 1]) {
			lz[1] += a[i];
		}
		modifyv(1, 1, m, c[i - 1], v);
	}
	cout << mx[1] << '\n';
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		work();
	}

	return 0;
}