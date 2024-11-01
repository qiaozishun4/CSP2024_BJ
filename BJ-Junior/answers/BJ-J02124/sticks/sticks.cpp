#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
        scanf("%d",&n);
        if(n <= 1) puts("-1");
        else if(n%7 == 0){
            for(int i = 1;i <= n/7;i++){
                printf("8");
            }
            puts("");
        }else if(n%7 == 1){
            printf("10");
            for(int i = 1;i < n/7;i++){
                printf("8");
            }
            puts("");
        }else if(n%7 == 2){
            printf("1");
            for(int i = 1;i <= n/7;i++){
                printf("8");
            }
            puts("");
        }else if(n%7 == 3){
            printf("7");
            for(int i = 1;i <= n/7;i++){
                printf("8");
            }
            puts("");
        }else if(n%7 == 4){
            printf("20");
            for(int i = 1;i < n/7;i++){
                printf("8");
            }
            puts("");
        }else if(n%7 == 5){
            printf("2");
            for(int i = 1;i <= n/7;i++){
                printf("8");
            }
            puts("");
        }else if(n%7 == 6){
            printf("6");
            for(int i = 1;i <= n/7;i++){
                printf("8");
            }
            puts("");
        }
    }

    return 0;
}
