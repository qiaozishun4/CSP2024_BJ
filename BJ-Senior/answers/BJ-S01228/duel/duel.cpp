#include<bits/stdc++.h>
using namespace std;
const int NR = 1e5 + 5;
int n, m;
int a[NR];
int ans;
int box[NR];
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n; ans = n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i], box[a[i]]++, m = max(m, a[i]);
	sort(a + 1, a + n + 1);
	int lim = 0;
	while(lim <= m && !box[lim]) lim++;
	if(lim > m) {
		cout << n << endl;
		return 0;
	}
	for(int i = 1; i <= n; ++i) {
		while(lim <= m && (!box[lim] || lim <= a[i])) lim++;
		if(lim > m) break;
		ans--, box[lim]--;
	}
	cout << ans << endl;
	return 0;
}