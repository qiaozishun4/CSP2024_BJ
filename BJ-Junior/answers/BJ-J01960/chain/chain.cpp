// chain.cpp
#include <bits/stdc++.h>
using namespace std;

#define clear(x) memset(x, 0, sizeof(x))
const int NR = 1e5 + 7;
const int KR = 2e5 + 7;
int S[NR][KR];
int l[NR];

void solve() {
    clear(S);
    clear(l);
    int n, k, q;
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
        for (int j = 1; j <= l[i]; j++) {
            cin >> S[i][j];
        }
    }
    while (q--) {
        int r, c;
        cin >> r >> c;
    }
}

int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
	return 0;
}
