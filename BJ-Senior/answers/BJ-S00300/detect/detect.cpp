#include <bits/stdc++.h>
using namespace std;
#define _for(i, a, b) for(int i = a, IM = b; i <= IM; i ++)
#define _rep(i, a, b) for(int i = a, IM = b; i >= IM; i --)
#define endl '\n'
#define _mp(a, b) make_pair(a, b)
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int N = 2000009, M = 1000009, mod = 1e9 + 7, inf = 1e9;
const double eps = 1e-6;

int d[N], fv[N], a[N];
int p[N];

using pdd = pair<double, double>;
pdd b[N];
int tot;

int v;
double ask(double v0, double a) {
    //return 9;
	return (v - v0) * v0 / a + pow(v - v0, 2) / (2 * a);
}
void solved() {
	int n, m, l;	cin >> n >> m >> l >> v;
	_for(i, 1, n) cin >> d[i] >> fv[i] >> a[i];
	_for(i, 1, m) cin >> p[i];
	double r = l + eps;
	_for(i, 1, n) {
	    //int pre = tot;
		if(a[i] == 0) {
			if(fv[i] > v) b[++ tot] = _mp(d[i] - eps, r);
		} else if(a[i] > 0) {
			if(fv[i] <= v) {
                double s = d[i] + ask(fv[i], a[i]);
                if(s <= l) b[++ tot] = _mp(s + eps, r);
			} else {
                b[++ tot] = _mp(d[i] - eps, r);
			}
		} else {
			if(fv[i] <= v) continue;
			double s = min((double)l + 2, d[i] + ask(fv[i], a[i]));
			b[++ tot] = _mp(d[i] - eps, s - eps);
		}
		//if(tot != pre) {
            //cout << i << ' ' <<b[tot].first << ' ' <<b[tot].second <<endl;
		//}
	}
	sort(b + 1, b + 1 + tot, [](pdd x, pdd y) -> bool {
		return x.second < y.second;
	});
	int pos = 0, ans = 0, pre = pos;
	set<int> se;
	p[0] = -inf;
	_for(i, 1, tot) {
		double l = b[i].first, r = b[i].second;
		if(p[pos] >= l) {
            ans ++;
            se.insert(pos);
            continue;
		}
		while(pre < m && p[pre + 1] <= r) pre ++;
		if(p[pre] >= l) {
            pos = pre;
			ans ++;
			se.insert(pos);
            //cout << "xxxx   " << l << ' ' <<r << ' ' << pos << endl;
		}
	}
	cout << ans << ' ' << m - se.size() << endl;
	tot = 0;
	return ;
}
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(6);
	int ttx;	cin >> ttx;	while(ttx --)
	solved();
	return 0;
}
