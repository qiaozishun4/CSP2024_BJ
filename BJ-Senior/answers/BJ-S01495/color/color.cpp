#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 1000010;
int t, n;
int a[N];
int cnt[N];

int main () {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			scanf("%d", a + i);
			cnt[a[i]] ++;
		}
		int cp1 = -1, cp2 = -1, ans = 0;
		for (int i = 1; i <= n; i ++) {
			if (cp1 == -1 || a[i] == cp1) {
				if (a[i] == cp1) {
					ans += a[i];
				}
				cp1 = a[i];
				cnt[cp1] --;
			} else if (cp2 == -1 || a[i] == cp2) {
				if (a[i] == cp2) {
					ans += a[i];
				}
				cp2 = a[i];
				cnt[cp2] --;
			} else if (cnt[cp1] == 0) {
				cp1 = a[i];
				cnt[cp1] --;
			} else if (cnt[cp2] == 0) {
				cp2 = a[i];
				cnt[cp2] --;
			} else if (cp1 < cp2) {
				cp1 = a[i];
				cnt[cp2] --;
			} else {
				cp2 = a[i];
				cnt[cp2] --;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}