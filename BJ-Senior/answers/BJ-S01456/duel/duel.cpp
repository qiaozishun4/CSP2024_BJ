#include <iostream>
#include <cstdio>
using namespace std;

int n, x, maxn;
int a[1000010];

int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		a[x]++;
		if (maxn < a[x]) {
			maxn = a[x];
		}
	}
	cout << maxn;
	return 0;
}
