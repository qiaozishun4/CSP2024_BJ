#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 200010;
int T, n, A[MAXN], ans;
vector<int> B, R;
int check() {
	int res = 0;
	for (int i = 1; i < B.size(); i++)
		if (B[i] == B[i - 1]) res += B[i];
	for (int i = 1; i < R.size(); i++)
		if (R[i] == R[i - 1]) res += R[i];
	return res;
}
void dfs(int i) {
	if (i == n) {
		ans = max(ans, check());
		return;
	}
	B.push_back(A[i]);
	dfs(i + 1);
	B.pop_back();
	R.push_back(A[i]);
	dfs(i + 1);
	R.pop_back();
}
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> A[i];
		dfs(0);
		cout << ans << endl;
		ans = 0;
		R.clear();
		B.clear();
	}
	return 0;
}