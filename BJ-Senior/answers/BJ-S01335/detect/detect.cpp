#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 3010;

int l[N], r[N];
int p[N];
bool st[N][N]; // st[i][j]: camera j & car i 
bool ov[N];
int cnt[N];

int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	int T;
	cin >> T;
	while (T -- ) {
		memset(st, 0, sizeof st);
		memset(cnt, 0, sizeof cnt);
		memset(ov, 0, sizeof ov);
		int n, m, L, V;
		cin >> n >> m >> L >> V;
		for (int i = 0; i < n; i ++ ) {
			int d, v, a;
			cin >> d >> v >> a;
			double t;
			if (a != 0) t = (double)(V - v) / (double)a;
			if (a >= 0 && v > V) l[i] = d, r[i] = L;
			else if (a > 0 && v <= V) l[i] = d + ceil(10*floor((double)v * t*0.1 + 0.05*v*t*t + 1e-6)), r[i] = L;
			else if (a < 0 && v > V) l[i] = d, r[i] = d + floor(10 * ceil((double)v*t*0.1+0.05*v*t*t - 1e-6));
			else l[i] = -1, r[i] = -1;  
		}
		int res1 = 0;
		for (int i = 0; i < m; i ++ ) {
			cin >> p[i];
			for (int j = 0; j < n; j ++ ) {
				if (p[i] >= l[j] && p[i] <= r[j]) {
					if (!ov[j]) res1 ++ ;
					st[j][i] = true, cnt[j] ++ , ov[j] = true;
				}
			}
		}
		int res2 = 0;
		for (int i = 0; i < m; i ++ ) {
			bool flag = true;
			for (int j = 0; j < n; j ++ ) {
				if (cnt[j] == 1 && st[j][i]) flag = false;
			}
			if (flag)  {
				for (int j = 0; j < n; j ++ ) cnt[j] -- ; 
				res2 ++ ;
			}
		}
		cout << res1 << ' ' << res2 << endl;
	}
	return 0;
}
