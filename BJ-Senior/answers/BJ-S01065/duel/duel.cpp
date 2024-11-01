#include <iostream>
using namespace std;

const int NR = 1e5 + 5;
int r[NR], cnt[NR];

int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);

	int n, maxn = 0, minn = NR + NR;

	scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		scanf("%d", &r[i]);
		maxn = max(maxn, r[i]);
		minn = min(minn, r[i]);
		cnt[r[i]]++;
	}

	int last = 0;
	for (int i=minn; i<=maxn; i++) {
		if (cnt[i] == 0)
			continue;

		last = max(0, last - cnt[i]);
		last += cnt[i];
	}

	printf("%d\n", last);
	return 0;
}
