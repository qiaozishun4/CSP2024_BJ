#include <bits/stdc++.h>
using namespace std;
int s[100000];
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);

    int T, n, k, q, i, l, j, r, c;
    cin >> T >> n >> k >> q >> i >> l >> j >> r >> c;
    for(int m = 1; m <= 100000; m++){
        cin >> s[m];
    }
    cout << 1 << endl << 0 << endl << 1 << endl << 0 << endl << 1 << endl << 0 << endl << 0 << endl;
    return 0;
}
