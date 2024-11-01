#include <cstdio>
int max(int a, int b){
    return a > b ? a : b;
}
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n, a, maxn = 0, cnt[100005] = {};
    scanf("%d", &n);
    while(n--){
        scanf("%d", &a);
        maxn = max(maxn, ++cnt[a]);
    }
    printf("%d", maxn);
    return 0;
}
