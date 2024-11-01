#include <iostream>
#include <algorithm>

using namespace std;

constexpr int maxn = 1e5+5;
int ary[maxn];
int done[maxn], pos = 0;

int main () {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ary[i];
	}
	sort(ary + 1, ary + n + 1);
	int cur = -1, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (ary[i] != cur) {
			done[pos] = cnt;
			cur = ary[i];
			++pos, cnt = 1;
		}
		else ++cnt;
		// cout << cnt << " ";
	}
	// cout << endl;
	done[pos] = cnt;
	int remain = 0;
	for (int i = 1; i <= pos; i++) {
		// cout << done[i] << " ";
		remain = done[i] + max(0, remain - done[i]);
	}
	// cout << "\n";
	cout << remain << "\n";
	return 0;
}