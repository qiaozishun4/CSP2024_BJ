#include <bits/stdc++.h>
using namespace std;
#define _for(i, a, b) for(int i = a, IM = b; i <= IM; i ++)
#define _rep(i, a, b) for(int i = a, IM = b; i >= IM; i --)
#define endl '\n'
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int N = 200009, M = 1000009, mod = 1e9 + 7, inf = 1e9;
int a[N];

void solved() {
	int n;	cin >> n;
	_for(i, 1, n) {
		int x;	cin >> x;
		a[x] ++;
	}
	int sum = 0, ans = 0;
	_rep(i, 1e5 + 1, 1) {
		if(a[i] > sum) ans += a[i] - sum;
		if(a[i] > sum) sum = a[i];
	}
	cout << ans;
	return ;
}
int main() {
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(6);
	// int ttx;	cin >> ttx;	while(ttx --)
	solved();
	return 0;
}
