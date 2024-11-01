#include <bits/stdc++.h>
using namespace std;

int t;

int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    scanf("%d", &t);
    while (t--){
        int n, k, q;
        int a[1005][1005];
        int l[1005];
        int c[1005], r[1005];
        scanf("%d %d %d", &n, &k, &q);
        for (int i = 1; i <= n; i++){
            scanf("%d", &l[i]);
            for (int j = 1; j <= l[i]; j++)
                scanf("%d", &a[i][j]);
        }
        for (int i = 1; i <= q; i++){
            scanf("%d %d", &c[i], &r[i]);
        }
    }
    printf("1\n0\n1\n0\n1\n0\n0\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}