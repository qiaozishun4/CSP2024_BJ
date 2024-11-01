# include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, nr, nb;
long long ans, a[N];

void DFS(int k, long long res){
	if (k > n){
		ans = max(ans, res);
		return;
	}
	res += a[k] * (a[k] == a[nr]);
	int tnr = nr;
	nr = k;
	DFS(k + 1, res);
	nr = tnr;
	res -= a[k] * (a[k] == a[nr]);
	res += a[k] * (a[k] == a[nb]);
	int tnb = nb;
	nb = k;
	DFS(k + 1, res);
	nb = tnb;
	res -= a[k] * (a[k] == a[nb]);
}

int main(){
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	int t;
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		ans = 0;
		DFS(1, 0);
		cout << ans << endl;
	}
	return 0;
}