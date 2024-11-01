#include <bits/stdc++.h>
using namespace std;
#define _for(i, a, b) for(int i = a, IM = b; i <= IM; i ++)
#define _rep(i, a, b) for(int i = a, IM = b; i >= IM; i --)
#define endl '\n'
#define _mp(a, b) make_pair(a, b)
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int N = 200009, M = 1000009, mod = 1e9 + 7, inf = 1e9;
int a[N], pre[N], b[M];
// ll f[N][4];
ll f[N][2];

void solved() {
	int n;	cin >> n;
	_for(i, 1, n) cin >>a[i];
	ll ans = 0;
	_for(i, 2, n) if(a[i] == a[i - 1]) ans += a[i];
	int m = 1;
	_for(i, 2, n) if(a[i] != a[m]) a[++ m] = a[i];
	n = m;
	// cout << "xxxx  " <<m <<endl;
	// _for(i, 1, n) cout <<a[i] << ' ';   cout <<endl;
	_for(i, 1, n) {
		pre[i] = b[a[i]];
		b[a[i]] = i;
	}
	_for(i, 1, n) b[a[i]] = 0;
	_for(i, 1, n) {
		// f[i][0] = max(f[i - 1][0], f[i - 1][3]);
		// if(pre[i + 1] != 0) {

		// }
		f[i][0] = max(f[i - 1][0], f[i - 1][1]);
		f[i][1] = 0;
		if(pre[i] != 0) {
			int x = pre[i];
			ll mx = max(f[x][0], f[x][1]);
			if(pre[x + 1] != 0) mx = max(mx, f[x + 1][1]);
			f[i][1] = mx + a[i];
		}
	}
	// _for(i, 1, n) cout << a[i] << '\t'; cout <<endl;
	// _for(i, 1, n) cout << f[i][0] << '\t';  cout <<endl;
	// _for(i, 1, n) cout << f[i][1] << '\t';  cout <<endl;
	cout << ans + max(f[n][0], f[n][1]) << endl;
	return ;
}
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(6);
	int ttx;	cin >> ttx;	while(ttx --)
	solved();
	return 0;
}
