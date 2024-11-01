#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
int num[11] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
ll ans[N] = {-1, -1, 1, 7, 4, 2, 6, 8, 10, 18, 23, 20, 60, 68, 88, 108, 188, 200, 208, 608, 688, 888, 1088, 1888};
int t, n;
int main(){
    freopen("sticks.in","r",stdin);
    /freopen("sticks.out","w",stdout);
    scanf(" %d",&t);
    while(t--){
        scanf(" %d",&n);
        if(ans[n] != 0){
            printf("%lld\n", ans[n]);
            continue;
        }
        if(n % 7 == 0){
            for(int i = 1; i <= n / 7; i++) printf("8");
            puts("");
            continue;
        }
        if(n % 7 == 1){
            if(n == 8) puts("10");
            else{
                printf("10");
                for(int i = 1; i <= (n - 8) / 7; i++) printf("8");
                puts("");
            }
            continue;
        }
        int k = n % 7;
        if(k == 2){
           printf("1");
            for(int i = 1; i <= n / 7; i++) printf("8");
        }
        else if(k == 3){
            printf("20");
            for(int i = 1; i <= n - 11; i++, n -= 6) printf("0");
        }
        else if(k == 4){
            printf("20");
            for(int i = 1; i <= n / 7 - 1; i++) printf("8");
        }
        else if(k == 5){
            printf("60");
            for(int i = 1; i <= n / 7 - 1; i++) printf("8");
        }
        else if(k == 6){
            printf("6");
            for(int i = 1; i <= n / 7; i++) printf("8");
        }
        puts("");

    }
    return 0;
}
