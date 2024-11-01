#include <iostream>
using namespace std;

int t, n, m, k, x, y, d, mp[1005][1005], ans;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
void exp(int di, int xi, int yi) {
	if (mp[xi][yi] == 1) ans++;
	mp[xi][yi] = 2;
	for (int i = 0; i < 4; i++) {
		if (k <= 0) return;
		if (mp[xi + dx[di]][yi + dy[di]] != 0) {
			k--;
			exp(di, xi + dx[di], yi + dy[di]);
		} else {
			k--;
			di = (di+1) % 4;
		}
	}
}
int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    string tm;
    cin >> t;
    for (int i = 0; i < t; i++) {
		ans = 0, m = {};
		cin >> n >> m >> k >> x >> y >> d;
		for (int j = 1; j <= n; j++) {
			cin >> tm;
			for (int l = 1; l <= m; l++) if (tm[l-1] == '.') mp[j][l] = 1;
		}
		exp(d, x, y);
		cout << ans << endl;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}