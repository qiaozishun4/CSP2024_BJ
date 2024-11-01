# include <bits/stdc++.h>
using namespace std;
int t, n, m, l, V;
// d: where start
// a: jiasudu
// v: chushi sudu
int main() {
	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);
	cin >> t;
	while (t--) {
		scanf("%d %d %d %d", &n, &m, &l, &V);
		int d[100010], v[100010], a[100100], p[100010], cs=0;//, q=0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d %d %d", &d[i], &v[i], &a[i]);
		}
		for (int i = 1; i <= m; ++i) {
			scanf("%d", &p[i]);
		}
		sort(p+1, p+1+m);
		for (int i = 1; i <= n; ++i) {
			if (v[i] > V && !(d[i] > p[m])) cs++;
		}
		//int o = 1;
		/*for (int i = 1; i <= m; ++i) {
			for (int j = o; j <= n; ++j) {
				if (d[j] < p[i]) {
					//printf("d[%d] < p[%d] (%d, %d)\n", j, i, d[j], p[i]);
					q++; o++;
					break;
				}
			}
		}*/
		if (cs == 0) 
			printf("%d %d\n", cs, m);
		else
			printf("%d %d\n", cs, m - 1);
	}
	return 0;
}
