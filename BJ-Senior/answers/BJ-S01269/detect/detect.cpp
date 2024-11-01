#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 100000;
int d[N], v[N], a[N];
int p[N];

int main() {
	freopen("detect.in", "r", stdin); freopen("detect.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m, l, vv;
		scanf("%d %d %d %d", &n, &m, &l, &vv);
		for(int i = 0; i < n; i++) {
			scanf("%d %d %d", &d[i], &v[i], &a[i]);
		}
		for(int i = 0; i < m; i++) {
			scanf("%d", &p[i]);
		}
		
		int cnt = 0;
		set<int> s;
		for(int i = 0; i < n; i++) {
			auto lb = lower_bound(p, p + m, d[i]);
			int lbi = lb - p;
			bool over = false;
			for(int j = lbi; j < m; j++) {
				double vvv = sqrt((ll)v[i] * v[i] + 2ll * a[i] * (p[j] - d[i])); 
				if(vvv < 0) {
					break;
				}
				if(vvv > vv) {
					over = true;
					break;
				} else {
					if(a[i] < 0) {
						break;
					}
				}
			}
			if(over) {
				s.insert(lbi);
				cnt++;
			}
		}
		printf("%d %d\n", cnt, (int)s.size());
	}
}
