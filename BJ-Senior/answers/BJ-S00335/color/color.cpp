#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
const ll inf = 1e18;

int T, n;
int a[N];
vector<int> val;
int qry(int x) { return lower_bound(val.begin(), val.end(), x) - val.begin() + 1;}

struct SGT {
	#define lc (p << 1)
	#define rc (lc | 1)
	ll mx[N << 2], tg[N << 2];
	void init() {
		for (int i = 1; i <= (val.size() + 1 << 2); ++i) mx[i] = -inf, tg[i] = 0;
	}
	void add(int p, ll v) { mx[p] += v, tg[p] += v;}
	void pushdown(int p) { add(lc, tg[p]), add(rc, tg[p]), tg[p] = 0;}
	void modify(int p, int sl, int sr, int idx, ll v) {
		if (sl == sr) { mx[p] = max(mx[p], v); return;}
		int mid = (sl + sr) >> 1; pushdown(p);
		if (idx <= mid) modify(lc, sl, mid, idx, v);
		else modify(rc, mid + 1, sr, idx, v);
		mx[p] = max(mx[lc], mx[rc]);
	}
	ll query(int p, int sl, int sr, int idx) {
		if (sl == sr) return mx[p];
		int mid = (sl + sr) >> 1; ll ret; pushdown(p);
		if (idx <= mid) ret = query(lc, sl, mid, idx);
		else ret = query(rc, mid + 1, sr, idx);
		return ret;
	}
} F, G;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	
	cin >> T;
	while (T--) {
		cin >> n; val.clear();
		for (int i = 1; i <= n; ++i) cin >> a[i], val.push_back(a[i]);
		sort(val.begin(), val.end());
		val.erase(unique(val.begin(), val.end()), val.end());
		
		F.init(), G.init();
		F.modify(1, 0, val.size(), 0, 0);
		for (int i = 2; i <= n; ++i) {
			int p = qry(a[i]);
			ll F_v = max(G.query(1, 0, val.size(), p) + a[i], G.mx[1]);
			ll G_v = max(F.query(1, 0, val.size(), p) + a[i], F.mx[1]);
			
		//	cerr << i << ' ' << F_v << ' ' << G_v << endl;
			
			F.add(1, (a[i] == a[i - 1]) * a[i]);
			G.add(1, (a[i] == a[i - 1]) * a[i]);
			F.modify(1, 0, val.size(), qry(a[i - 1]), F_v);
			G.modify(1, 0, val.size(), qry(a[i - 1]), G_v);
		}
		
		cout << max(F.mx[1], G.mx[1]) << endl;
	}
	
	return 0;
}