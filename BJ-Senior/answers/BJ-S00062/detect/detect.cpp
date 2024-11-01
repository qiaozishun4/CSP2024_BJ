#include <iostream>
using namespace std;
int d[100005] = {0};
int u[100005] = {0};
int a[100005] = {0};
int p[100005] = {0};
int main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T = 0;
    scanf("%d", &T);
    while(T--){
        int n = 0, m = 0, l = 0, v = 0, sum = 0, ans = 0;
        int flag1 = 1, flag2 = 1;
        scanf("%d %d %d %d", &n, &m, &l, &v);
        for(int i = 1; i <= n; i++){
            scanf("%d %d %d", &d[i], &u[i], &a[i]);
            if(a[i] != 0){
                flag1 = 0;
            }
            if(a[i] >= 0){
                flag2 = 0;
            }
        }
        for(int i = 1; i <= n; i++){
            if(u[i] > v){
                sum++;
            }
        }
        if(flag1 == 1){
            if(sum > 0){
                ans = 1;
            }
        }
        if(flag2 == 1){
            ans = sum;
        }
        printf("%d %d", sum, ans);
    }
    return 0;
}
