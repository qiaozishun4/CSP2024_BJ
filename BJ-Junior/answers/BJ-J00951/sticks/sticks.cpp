#include <cstdio>
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t, n, a[20] = {-1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88}, b[10] = {888, 108, 188, 200, 208, 288, 688};
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(n < 15){
            printf("%d\n", a[n - 1]);
        }else{
            printf("%d", b[n % 7]);
            for(int i = 1; 7 * (i + 2) < n; i++){
                printf("8");
            }
            printf("\n");
        }
    }
    return 0;
}
