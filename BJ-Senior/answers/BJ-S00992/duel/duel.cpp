#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int maxn = 1e5 + 5;

int n, b[maxn];

int main () {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    scanf("%d", &n);
    int m = 0;
    for (int i = 1; i <= n; i ++) {
        int a;
        scanf("%d", &a);
        b[a] ++;
        m = max(m, a);
    }
    bool first = true;
    int val = 0;
    int cunhuo = 0;
    for (int i = 0; i <= m; i ++) {
        if (b[i] > 0) {
            if (first) {
                first = false;
                val = b[i];
                cunhuo = b[i];
                continue;
            }
            if (b[i] >= cunhuo) {
                cunhuo = b[i];
            } else {
                cunhuo = cunhuo;
            }
        }
    }
    printf("%d\n", cunhuo);
    return 0;
}

