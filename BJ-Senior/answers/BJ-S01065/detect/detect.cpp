#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int NR = 1e5 + 5;
int n, m;
struct car_t {
	double d, v, a;
} car[NR];
double p[NR];

bool flag[NR];
int ans1;

void judge(int c, double l, double r, bool flagL, bool flagR) {
	int fist = lower_bound(p+1, p+1+m, l) - p;
	for (int i=fist-1; i<=n; i++) {
		if ((p[i] > l || (!flagL&& p[i] == l)) && (p[i] < r || (!flagR && p[i] == r))) {
			flag[c] = 1;
			break;
		}

		if (p[i] > r)
			break;
	}

	if (flag[c])
		ans1++;
}

void solve(double L, double V) {
	double VV = V * V;
	double d, v, a;
	double llim, rlim, s;
	bool fll, flr;

	for (int i=1; i<=n; i++) {
		llim = rlim = -1.0;
		fll = flr = 0;

		d = car[i].d, v = car[i].v, a = car[i].a;

		if (a == 0) {
			if (v > V)
				llim = d, rlim = L;
		}
		else {
			s = (VV - v * v) / (a * 2.0);
			if (a > 0 && d + s < L) {
				llim = d + s, rlim = L;
				fll = 1;
			}
		}

		if (llim != -1.0)
			judge(i, llim, rlim, fll, flr);
	}

	printf("%d %d\n", ans1, m-1);
}

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	double L, V;

	cin >> T;
	while (T--) {
		cin >> n >> m >> L >> V;
		for (int i=1; i<=n; i++)
			cin >> car[i].d >> car[i].v >> car[i].a;
		for (int i=1; i<=m; i++)
			cin >> p[i];

		solve(L, V);

		ans1 = 0;
		memset(flag, 0, sizeof(flag));
	}
	return 0;
}
