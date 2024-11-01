#include<bits/stdc++.h>
using namespace std;
const int maxl = 2e3 + 10;

int t, n, k, q, r, c, l;
int s[maxl];

unordered_map<int, bool> spair;

int main () {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);

    scanf("%i", &t);
    while (t--) {
        spair.clear();

        scanf("%i%i%i", &n, &k, &q);
        for (int i = 1; i <= n; ++i) {
            scanf("%i", &l);
            for (int j = 1; j <= l; ++j) {
                scanf("%i", &s[j]);
            }

            for (int j = 1; j <= l; ++j) {
                if (s[j] != 1) {
                    continue;
                }
                for (int a = j; a <= l && a <= j + k - 1; ++a) {
                    spair[s[a]] = true;
                }
            }
        }
        while (q--) {
            scanf("%i%i", &r, &c);

            printf("%i\n", spair[c]);
        }
    }
    return 0;
}