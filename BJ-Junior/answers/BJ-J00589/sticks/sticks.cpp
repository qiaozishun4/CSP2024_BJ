#include<bits/stdc++.h>
using namespace std;
int T, n, ans[21] = {0, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 200, 208, 288, 688};
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i){
        scanf("%d", &n);
        if(n < 20){
            printf("%d\n", ans[n]);
            continue;
        }
        if(n % 7 == 0){
            for(int j = 1; j <= n / 7; ++j)
                printf("8");
            printf("\n");
            continue;
        }
        if(n % 7 == 1 && n > 35){
            n -= 36;
            printf("666666");
            while(n > 0){
                printf("8");
                n -= 7;
            }
            printf("\n");
            continue;
        }
        printf("-1\n");
    }
    return 0;
}
