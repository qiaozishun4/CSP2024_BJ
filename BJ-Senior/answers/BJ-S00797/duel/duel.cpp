#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005], nw, ans;
int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	nw = 1; ans = n;
	for(int i = 2; i <= n; i++)
		if(a[i] > a[nw]) nw++, ans--;
	cout << ans << endl;
	return 0;
}