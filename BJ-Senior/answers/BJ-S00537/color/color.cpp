//HMZ于东方升起，如利剑般驱散黑暗，撒遍光明，化解迷茫，指引道路，构筑世界之真理！
#include <bits/stdc++.h>
using namespace std;
void write(__int128 x) {
	if (x < 10) {
		putchar(x ^ 48);
		return;
	}
	write(x / 10);
	putchar(x % 10 ^ 48);
}
char d[21][1000005];
int A[100005], c[100005], a[100005];
long long ans[100005];
int ABC[4];
int cnt[21];
bool p[1000005];
long long sum[1000005];
int id[1000005], Dep[1000005], MAXN[1000005];
int Log[1000005];
void update(int x) {
	if (!p[x]) {
		if (id[(x << 1)] == -1) {
			sum[x] = sum[(x << 1)] + sum[(x << 1) | 1];
			id[x] = -1;
		}
		else if (id[(x << 1)] >= Dep[x]) {
			id[x] = id[(x << 1)];
			sum[x] = sum[(x << 1)];
		}
		else {
			id[x] = id[(x << 1) | 1];
			sum[x] = sum[(x << 1) | 1];
		}
	}
	else {
		if (id[(x << 1) | 1] == -1) {
			sum[x] = sum[(x << 1)] + sum[(x << 1) | 1];
			id[x] = -1;
		}
		else if (id[(x << 1) | 1] >= Dep[x]) {
			id[x] = id[(x << 1) | 1];
			sum[x] = sum[(x << 1) | 1];
		}
		else {
			id[x] = id[(x << 1)];
			sum[x] = sum[(x << 1)];
		}
	}
}
void query(int x, int l, int r) {
	cout << x << ' ' << l << ' ' << r << ' ' << sum[x] << ' ' << id[x] << '\n';
	int mid = (l + r) / 2;
	if (l == r) return;
	query((x << 1), l, mid);
	query((x << 1) | 1, mid + 1, r);
}
void build(int x, int l, int r) {
	int mid = (l + r) / 2;
	id[x] = -1;
	sum[x] = (1ll * l + r) * (r - l + 1) / 2;
	if (l == r) return;
	build((x << 1), l, mid);
	build((x << 1) | 1, mid + 1, r);
}
void Build(int x, int l, int r, int dep) {
	int mid = (l + r) / 2;
	cnt[dep]++;
	Dep[x] = dep;
	p[x] = d[dep][cnt[dep]] - '0';
	if (l == r) {
		return;
	}
	Build((x << 1), l, mid, dep - 1);
	Build((x << 1) | 1, mid + 1, r, dep - 1);
}
int main() {
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= m; i++) cin >> c[i];
	int N = log2(n - 1) + 1;
	Log[1] = 0;
	for (int i = 1; i <= N + 1; i++) {
		for (int j = (1 << (i - 1)) + 1; j <= (1 << i); j++) Log[j] = i;
	}
	for (int i = 1; i <= N; i++) for (int j = 1; j <= (1 << (N - i)); j++) cin >> d[i][j];
	Build(1, 1, (1 << N), N);
	int T;
	cin >> T;
	while (T--) {
		build(1, 1, (1 << N));
		cin >> ABC[0] >> ABC[1] >> ABC[2] >> ABC[3];
		for (int i = 1; i <= n; i++) a[i] = A[i] ^ ABC[i % 4];
		// for (int i = 1; i <= n; i++) cout << a[i] << ' '; cout << '\n';
		for (int i = 1; i <= n; i++) {
			int xx = i + (1 << N) - 1, num = Log[i], num1 = (1 << (N - num));
			int x = xx;
			sum[x] = i;
			id[x] = a[i];
			while (x != num1) {
				int X = (x >> 1);
				if (!(p[X] ^ (x & 1)) && Dep[X] > a[i]) sum[xx] = 0;
				x >>= 1;
			}
			x = xx;
			x >>= 1;
			while (x) {
				update(x);
				x >>= 1;
			}
			ans[i] = sum[num1];
			if ((1 << num) == i) {
				int X = (num1 >> 1);
				if (!(p[X] ^ (num1 & 1)) && Dep[X] > id[num1]) {
					sum[num1] = 0;
				}
			}
		}
		long long ANS = 0;
		for (int i = 1; i <= m; i++) {
			ANS ^= ans[c[i]] * i;
		}
		cout << ANS << '\n';
		// write(ANS);
	}
	return 0;
}