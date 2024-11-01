#include <bits/stdc++.h>
using namespace std;
#define _for(i, a, b) for(int i = a, IM = b; i <= IM; i ++)
#define _rep(i, a, b) for(int i = a, IM = b; i >= IM; i --)
#define endl '\n'
#define _mp(a, b) make_pair(a, b)
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int N = 100009, M = 1000009, mod = 1e9 + 7, inf = 1e9;
int f[N];
int len[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void solved() {
	int n;	cin >> n;
	if(f[n] > n) {
		cout << -1 << endl;
		return ;
	}
	bool tp = true;
	while(n) {
		_for(i, 0, 9) {
			if(tp && i == 0) continue;
			if(len[i] > n) continue;
			if(f[n] == f[n - len[i]] + 1) {
				cout << i;
				n -= len[i];
				break;
			}
		}
		tp = false;
	}
	cout << endl;
	return ;
}
void init() {
	int n = 100000;
	_for(i, 1, n) f[i] = inf;
	_for(i, 1, n) {
		_for(j, 2, 7) {
			if(i < j) continue;
			f[i] = min(f[i], f[i - j] + 1);
		}
	}
}
int main() {
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(6);
	init();
	int ttx;	cin >> ttx;	while(ttx --)
	solved();
	return 0;
}
