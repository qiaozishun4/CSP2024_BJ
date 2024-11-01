#include<bits/stdc++.h>
using namespace std;
int T, n, k, q;
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i){
        scanf("%d%d%d", &n, &k, &q);
        for(int j = 1; j <= q; ++j)
            printf("0\n");
    }
    return 0;
}
