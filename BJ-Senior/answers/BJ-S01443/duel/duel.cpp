#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 100005;
int a[N];
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	int l = 1;
	for (int i = 1; i <= n; i++) {
		if (a[l] < a[i])
			++l;
	}
	printf("%d\n", n - l + 1);
	return 0;
}
