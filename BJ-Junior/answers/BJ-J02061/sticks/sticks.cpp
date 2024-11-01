#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n%7==0){
            if(n==0){
                printf("-1\n");
                continue;
            }
            for(int i=7;i<=n;i+=7){
                printf("8");
            }
            printf("\n");
        }
        if(n%7==1){
            if(n==1){
                printf("-1\n");
                continue;
            }
            printf("10");
            for(int i=15;i<=n;i+=7){
                printf("8");
            }
            printf("\n");
        }
        if(n%7==2){
            printf("1");
            for(int i=9;i<=n;i+=7){
                printf("8");
            }
            printf("\n");
        }
        if(n%7==3){
            if(n==3){
                printf("7\n");
                continue;
            }
            printf("22");
            for(int i=17;i<=n;i+=7){
                printf("8");
            }
            printf("\n");
        }
        if(n%7==4){
            if(n==4){
                printf("4\n");
                continue;
            }
            printf("20");
            for(int i=18;i<=n;i+=7){
                printf("8");
            }
            printf("\n");
        }
        if(n%7==5){
            printf("2");
            for(int i=12;i<=n;i+=7){
                printf("8");
            }
            printf("\n");
        }
        if(n%7==6){
            printf("6");
            for(int i=13;i<=n;i+=7){
                printf("8");
            }
            printf("\n");
        }
    }
    return 0;
}
