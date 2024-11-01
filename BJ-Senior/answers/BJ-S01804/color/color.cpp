#include<bits/stdc++.h>
using namespace std;

int T, n, a[200005], v[1000010], m, ans;

int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%d", &T);
    while(T --){
        memset(v, 0, sizeof v);
        scanf("%d", &n);
        ans = 0;
        for(int i = 0; i < n; i ++){
            scanf("%d", &a[i]);
            v[a[i]]++;
            m = max(m, a[i]);
        }
        for(int i = m; i >= 0; i --){
            if(v[a[i]] % 2 == 0){
                ans = a[i];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
