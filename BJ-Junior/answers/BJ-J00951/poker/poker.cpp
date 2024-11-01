#include <cstdio>
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, cnt = 52;
    char a, b;
    bool ans[130][130] = {};
    scanf("%d", &n);
    while(n--){
        scanf(" %c %c", &a, &b);
        if(!ans[a][b]){
            cnt--;
            ans[a][b] = 1;
        }
    }
    printf("%d", cnt);
    return 0;
}
