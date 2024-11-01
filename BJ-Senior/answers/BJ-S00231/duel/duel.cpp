# include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
bool flag[N];
int r[N];

int main(){
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	if (n == 1){
		cout << 1;
		return 0;
	}
	for (int i = 1; i <= n; i++) cin >> r[i];
	sort(r + 1, r + n + 1);
	if (n == 2){
		if (r[1] ^ r[2]) cout << 1;
		else cout << 2;
		return 0;
	}
	int cnt = 0;
	for (int i = 2, j = 1; i <= n && j <= n; i++, j++){
		while (i <= n && r[i] <= r[j]) i++;
		if (i > n) break;
		cnt++;
	}
	cout << n - cnt;
	return 0;
}