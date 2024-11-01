#include <bits/stdc++.h>
using namespace std;
#define _for(i, a, b) for(int i = a, IM = b; i <= IM; i ++)
#define _rep(i, a, b) for(int i = a, IM = b; i >= IM; i --)
#define endl '\n'
#define _mp(a, b) make_pair(a, b)
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int N = 200009, M = 1000009, mod = 1e9 + 7, inf = 1e9;

void solved() {
	int n;	cin >> n;
	set<string> se;
	_for(i, 1, n) {
        string s;   cin >> s;
        se.insert(s);
	}
	cout << 52 - se.size();
	return ;
}
int main() {
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(6);
	// int ttx;	cin >> ttx;	while(ttx --)
	solved();
	return 0;
}
