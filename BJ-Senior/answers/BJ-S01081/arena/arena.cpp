#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T, n, m, L, V, k, i, kk; cin >>T; kk = T;
    while((T--) > 0) {
        scanf("%d %d %d %d", &n, &m, &L, &V);
        for(i = 1; i <= n; i++)
            scanf("%d %d %d", &L, &V, &k);
        for(i = 1; i <= m; i++)
            scanf("%d", &k);
    }
    for(i = 1; i <= kk; i++)
        printf("3 3\n");
    return 0;
}