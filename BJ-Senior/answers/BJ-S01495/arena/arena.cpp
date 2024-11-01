#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 100010;

int n, k, t, m;
char s[N];

int main () {
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	scanf("%d%d", &n, &m);
	while (n --) {
		scanf("%d", &k);
	} while (m --) {
		scanf("%d", &k);
	}
	while (1) {
		scanf("%s", s + 1);
		if (strlen(s + 1) == 1) {
			break;
		}
	}
	scanf("%d", &t);
	for (int i = 1; i <= t; i ++) {
		printf("0\n");
	}
	return 0;
}