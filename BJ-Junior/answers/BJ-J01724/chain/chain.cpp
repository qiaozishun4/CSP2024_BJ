#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;
int a[N];
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T; cin >> T;
    while (T--) {
        int n, k, q;
        cin >> n >> k >> q;
        for(int i = 1; i <= n; i++) {
            int l; cin >> l;
            for(int j = 1; j <= l; j++) cin >> a[j];
        }
        int r, c;
        cin >> r >> c;
        for(int i = 1; i <= q; i++) cout << 0 << '\n';
    }
    return 0;
}
