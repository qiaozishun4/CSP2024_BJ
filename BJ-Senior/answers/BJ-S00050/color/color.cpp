#include <iostream>
using namespace std;

const int MAXN = 31;

int T;
int n, A[MAXN];
int ans = 0;
bool co[MAXN];

void dfs(int k) {
	if (k == n + 1) {
		int res = 0;
		int c0 = 0, c1 = 0;
		for (int i = 1; i <= n; i++) {
			if (co[i] == 0) {
				res += (A[i] == c0) * c0;
				c0 = A[i];
			} else {
				res += (A[i] == c1) * c1;
				c1 = A[i];
			}
		}
		ans = max(ans, res);
		return;
	}
	co[k] = 1;
	dfs(k + 1);
	co[k] = 0;
	dfs(k + 1);
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> A[i];
		ans = 0;
		dfs(1);
		cout << ans << endl;
	}
	return 0;
}
