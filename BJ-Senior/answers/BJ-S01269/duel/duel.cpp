#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100000;
int cnt[N];
int unused[N];

int main() {
	freopen("duel.in", "r", stdin); freopen("duel.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for(int i = n; i--; ) {
		int ri;
		scanf("%d", &ri);
		cnt[ri]++;
		unused[ri]++;
	}

	for(int i = 1; i < N; i++) {
		for(int j = i + 1; cnt[i] > 0 && j < N; j++) {
			if(unused[j] > 0) {
				int tmp = min(cnt[i], unused[j]);
				cnt[i] -= tmp;
				n -= tmp;
				unused[j] -= tmp;
			}
		}
	}

	printf("%d\n", n);
}
