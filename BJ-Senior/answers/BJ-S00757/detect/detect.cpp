#include <iostream>
#include <cmath>
#include <bitset>
#include <cstdlib>
#include <ctime>
using namespace std;
int T, n, m, L, V, pos[100005];
struct car {
	long long d, v, a;
} c[100005];
bitset<3010> cs[3010];
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	//if (T > 10) T = 1;
	while (T--) {
		cin >> n >> m >> L >> V;
		for (int i = 1; i <= m; i++) cs[i].reset();
		bool flagA = true;
		for (int i = 1; i <= n; i++) {
			cin >> c[i].d >> c[i].v >> c[i].a;
			if (c[i].a != 0) flagA = false;
		}
		for (int i = 1; i <= m; i++) cin >> pos[i];
		if (flagA) {
			long long _ans1 = 0, _ans2 = m;
			for (int i = 1; i <= n; i++) {
				if (c[i].v > V) _ans1++;
				_ans2 = min(_ans2, c[i].d);
			}
			//cout << _ans1 << ' ' << m - _ans2 << '\n';
			continue;
		}
		long long ans1 = 0, ans2 = 0;
		for (int i = 1; i <= n; i++) {
			bool chaosu = false;
			for (int j = 1; j <= m; j++) {
				long long s = pos[j] - c[i].d;
				if (s < 0) continue;
				long long now = c[i].v * c[i].v + 2 * c[i].a * s;
				//cout << "car=" << i << " pos=" << j << " num=sqrt(" << now << ")" << '\n';
				if (now < 0) {
					//cout << "leave car=" << i << " pos=" << j << '\n';
					break;
				}
				double nowv = 1.0 * sqrt((double)now);
				if (nowv - V > 1e-9) {
					chaosu = true;
					//cout << "limit car=" << i << " pos=" << j << '\n';
					cs[j][i] = 1;
				} else if (c[i].a < 0) {
					break;
				}
			}
			if (chaosu) ans1++;
		}
		bitset<3010> remain;
		remain.reset();
		for (int i = 1; i <= n; i++) remain[i] = 1;
		//cout << remain.count() << '\n';
		for (int i = 1; i <= m; i++) {
			//cout << i << "=>";
			//for (int j = 1; j <= n; j++) cout << cs[i][j];
			//cout << '\n';
		}
		for (int i = 1; i <= m; i++) {
			int MAX = -1, pos = -1;
			for (int j = 1; j <= m; j++) {
				int cnt = (cs[j] & remain).count();
				if (cnt > MAX) {
					MAX = cnt;
					pos = j;
				}
			}
			if (MAX == 0) {
				ans2 = i - 1;
				break;
			}
			remain &= (~cs[pos]);
			//cout << pos << ' ';
			//for (int i = 1; i <= n; i++) cout << cs[pos][i];
			//cout << ' ';
			//for (int i = 1; i <= n; i++) cout << remain[i];
			//cout << '\n';
			ans2 = i;
			if (!remain.count()) break;
		}
		cout << ans1 << ' ' << m - ans2 << '\n';
	}
	return 0;
}
