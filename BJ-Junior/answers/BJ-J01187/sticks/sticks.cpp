#include<bits/stdc++.h>
using namespace std;
long long T;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
        long long n;
        scanf("%lld",&n);
        if(n==1){
            printf("-1\n");
            continue;
        }
        if(n==2){
            printf("1\n");
            continue;
        }
        if(n==3){
            printf("7\n");
            continue;
        }
        if(n==4){
            printf("4\n");
            continue;
        }
        if(n==5){
            printf("2\n");
            continue;
        }
        if(n==6){
            printf("6\n");
            continue;
        }
        if(n==10){
            printf("22\n");
            continue;
        }
        if(n==17){
            printf("200\n");
            continue;
        }
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                printf("8");
            }
            printf("\n");
            continue;
        }
        if(n%7==1){
            printf("10");
            for(int i=1;i<=(n-8)/7;i++){
                printf("8");
            }
            printf("\n");
            continue;
        }
        if(n%7==2){
            printf("1");
            for(int i=1;i<=(n-2)/7;i++){
                printf("8");
            }
            printf("\n");
            continue;
        }
        if(n%7==3){
            printf("200");
            for(int i=1;i<=(n-17)/7;i++){
                printf("8");
            }
            printf("\n");
            continue;
        }
        if(n%7==4){
            printf("20");
            for(int i=1;i<=(n-11)/7;i++){
                printf("8");
            }
            printf("\n");
            continue;
        }
        if(n%7==5){
            printf("2");
            for(int i=1;i<=(n-5)/7;i++){
                printf("8");
            }
            printf("\n");
            continue;
        }
        if(n%7==6){
            printf("6");
            for(int i=1;i<=(n-6)/7;i++){
                printf("8");
            }
            printf("\n");
            continue;
        }
    }
return 0;
}