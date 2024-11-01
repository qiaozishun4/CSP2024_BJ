#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 100010;

int n;
int a[N];
int cnt[N];

int main () {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	scanf("%d", &n);
	int ma = -1;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
		cnt[a[i]] ++;
		ma = max (ma, a[i]);
	}
	int sheng = 0;
	for (int i = 1; i <= ma; i ++) {
		if (cnt[i] == 0)
			continue;
		if (sheng <= cnt[i]) {
			sheng = cnt[i];
		}
	}
	printf("%d\n", sheng);
	return 0;
}