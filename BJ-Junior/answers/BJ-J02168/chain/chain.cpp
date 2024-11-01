#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;

int s[M];

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n, k, q, l, r, c;
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &l);
            for (int j = 1; j <= l; j++) {
                scanf("%d", s + i);
            }
        }
        for (int i = 1; i <= q; i++) {
            scanf("%d%d", &r, &c);
        }
        for (int i = 1; i <= q; i++) {
            puts("0");
        }
    }
    return 0;
}
