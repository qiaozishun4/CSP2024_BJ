#include <iostream>
#include <cstdio>
using namespace std;

int t, n, maxn, cnt;
int a[100000];
bool b[100000];

void dfs(int step) {
	if (step > n) {
		cnt = 0;
		for (int i = 2; i <= n; i++) {
			for (int j = i - 1; j > 0; j--) {
				if (b[j] == b[i]) {
					if (a[i] == a[j]) {
						cnt += a[i];
					}
					break;
				}
			}
		}
		if (cnt > maxn) {
			maxn = cnt;
		}
		return;
	}
	b[step] = 0;
	dfs(step + 1);
	b[step] = 1;
	dfs(step + 1);
}

int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> t;
	while (t--) {
		maxn = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		dfs(1);
		cout << maxn << "\n";
	}
	return 0;
}
