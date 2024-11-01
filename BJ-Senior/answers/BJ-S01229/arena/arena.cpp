#include <bits/stdc++.h>

using namespace std;

const int N = 5010;
int n, m;
int a[N], c[N];
int go[N * 4];
bool jue[N * 4];

inline int gett(int l, int L, int f, int depth) {
	if (l <= L) return a[l];
	else if (l == f) return 1e9;
	else return depth;
}

inline void pushup(int u, int l, int f, int depth) {
	int x1 = gett(go[u << 1], l, f, depth), x2 = gett(go[u << 1 | 1], l, f, depth);
	if (!jue[u]) {
		go[u] = (x1 >= depth ? go[u << 1] : go[u << 1 | 1]);
	}
	else {
		go[u] = (x2 >= depth ? go[u << 1 | 1] : go[u << 1]);
	}
}

void build(int u, int l, int r, int L, int f, int depth) {
	assert(l <= r);
	if (l == r) {
		go[u] = l;
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid, L, f, depth - 1);
	build(u << 1 | 1, mid + 1, r, L, f, depth - 1);
	pushup(u, L, f, depth);
	// cout << u << ' ' << l << ' ' << r << ' ' << go[u] << ' ' << depth << ' ' << jue[u] << '\n';
}

/*
void debug(int u, int l, int r) {
	cout << jue[u];
	int mid = l + r >> 1;
	if (l == r) return;
	debug(u << 1, l, mid);
	debug(u << 1 | 1, mid + 1, r);
}
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("arena.in", "r", stdin);
	 freopen("arena.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	for (int i = 1; i <= m; i ++ ) cin >> c[i];
	int lg = 0;
	while ((1 << lg) < n) lg ++;

	for (int i = 1; i <= lg; i ++ ) {
		string s;
		cin >> s;
		for (int j = 1; j <= (1 << lg - i); j ++ ) {
			int x = (1 << lg - i) + j - 1;
			jue[x] = s[j - 1] - '0';
		}
		assert(s.size() == (1 << lg - i));
	}


	int T;
	cin >> T;
	T = 1;
	while (T -- ) {
		int x[4]; 
		for (int i = 0; i < 4; i ++ ) cin >> x[i];
		for (int i = 1; i <= n; i ++ )
			a[i] ^= x[i % 4];
		
		long long res = 0;
		
		for (int i = 1; i <= m; i ++ ) {
			long long ans = 0;
			int lgg = 0;
			while ((1 << lgg) < c[i]) lgg ++;
			for (int j = 1; j <= (1 << lgg); j ++ ) {
				build(1, 1, (1 << lgg), c[i], j, lgg);
				if (go[1] == j) ans += j;
				// cout << '\n';
			}
			// cout << ans << '\n';
			res ^= (ans * i);
		}
		
		cout << res << '\n';
	}

}
/*
你说的对，但是调不下去了
2小时得0分，不愧是你。
想必有两个神已经ak了
最若之的一集
致敬传奇读题王，致敬传奇假做法王，致敬传奇挂分王
不要挂分谢谢喵。
*/