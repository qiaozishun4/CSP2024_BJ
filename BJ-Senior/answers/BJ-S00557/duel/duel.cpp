#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
const int MAXN = 100010;
const int V = 100010;
int n, arr[MAXN];
int bukkit[V], ans;
int main() {
	ios::sync_with_stdio(false);
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for (int i = 0, a; i < n; i++) {
		cin >> a;
		bukkit[a]++;
	}
	for (int i = 0; i < V; i++)
		ans = max(ans, bukkit[i]);
	cout << ans << endl;
	return 0;
}