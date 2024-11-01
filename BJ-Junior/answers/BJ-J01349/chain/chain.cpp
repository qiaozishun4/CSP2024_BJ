#include<bits/stdc++.h>
using namespace std;
int n, k, q, l[200005]; bool v[200005];
vector<int> vis[200005], x[200005];
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &n, &k, &q);
        for(int z = 1; z <= n; z++){
            scanf("%d", &l[z]);
            for(int i = 1; i <= l[z]; i++){
                int a; scanf("%d", &a);
                x[z].push_back(a);
            }for(int i = 0; i < l[z]; i++){
                if(x[z][i] != 1) continue;
                for(int j = i + 1; j <= i + k - 1 && j < l[z]; j++){
                    v[x[z][j]] = 1;
                    //printf("%d ", x[z][j]);
                }
            }
        }for(int i = 1; i <= q; i++){
            int a, b; scanf("%d%d", &a, &b);
            printf("%d\n", v[b]);
        }
    }
    return 0;
}
