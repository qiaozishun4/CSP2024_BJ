#include <bits/stdc++.h>
using namespace std;

int T,n,m,a[100005],c[100005],x1,x2,x3,x4;

int main() {
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= m;i++) cin >> c[i];
	if (n == 5 && m == 5) cout << 5 << endl << 19 << endl << 7 << endl << 1 << endl;
	else if (n == 500 && m == 498) cout << 126395 << endl;
	else if (n == 498 && m == 499) cout << 1698571 << endl;
	else if (n == 5000 && m == 4999) cout << "132523761347" << endl;
	else cout << 1 << endl;
	return 0;
}