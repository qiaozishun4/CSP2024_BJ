#include <iostream>
using namespace std;

struct node1 {
	int d, v0, a, s1, s2;
}a[100010];

struct node2{
	int s1, s2;
}d[100010];

bool cmp(node2 p, node2 q) {
	return p.s1 < q.s1;
}

int b[100010], c[1000010];
int t, n, m, l, v, x = 1, cnt, minn;

int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> t;
	while (t--) {
		cin >> n >> m >> l >> v;
		cin >> a[x].d >> a[x].v0 >> a[x].a;
		if (a[x].a > 0) {
			if (2 * a[x].a * (l - a[x].d) + a[x].v0 * a[x].v0 > v * v) {
				x++;
			}
		}else {
			if (a[x].v0 > v) {
				x++;
			}
		}
		if (a[x].a > 0) {
			for (int i = 2; i <= n; i++) {
				cin >> a[i].d >> a[i].v0 >> a[i].a;
			}
			for (int i = 1; i <= m; i++) {
				cin >> b[1];
			}
			for (int i = 1; i <= n; i++) {
				if (2 * a[i].a * (b[i] - a[i].d) + a[i].v0 * a[i].v0 > v * v) {
					x++;
				}
			}
			cout << x - 1 << " " << (x > 1) << "\n";
		}else if (a[x].a == 0) {
			for (int i = 2; i <= n; i++) {
				cin >> a[i].d >> a[i].v0 >> a[i].a;
			}
			for (int i = 1; i <= m; i++) {
				cin >> b[1];
			}
			for (int i = 1; i <= n; i++) {
				if (a[i].v0 > v && a[i].d <= b[1]) {
					x++;
				}
			}
			cout << x - 1 << " " << (x > 1) << "\n";
		}
	}
	return 0;
}
