#include <bits/stdc++.h>
using namespace std;

int n,r[100005],cur = 1,ans;

int main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> r[i];
	sort(r + 1,r + n + 1);
	ans = n;
	for (int i = 2;i <= n;i++)
		if (r[i] > r[cur]) ans--,cur++;
	cout << ans << endl;
	return 0;
}