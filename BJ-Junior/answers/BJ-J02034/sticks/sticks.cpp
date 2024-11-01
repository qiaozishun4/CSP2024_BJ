#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
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
        if(n==7){
            printf("8\n");
            continue;
        }
        if(n%7==1){
            printf("10");
            n-=8;
            for(int i=1;i<=n/7;i++)printf("8");
            printf("\n");
            continue;
        }
        if(n%7==0){
            n/=7;
            for(int i=1;i<=n;i++)printf("8");
            printf("\n");
            continue;
        }
        if(n%7==2){
            printf("18");
            n-=9;
            for(int i=1;i<=n/7;i++)printf("8");
            printf("\n");
            continue;
        }
        if(n%7==3){
            if(n==10){
                printf("22");
                continue;
            }
            printf("200");
            n-=17;
            for(int i=1;i<=n/6;i++)printf("8");
            printf("\n");
            continue;
        }
        if(n%7==4){
            printf("20");
            n-=11;
            for(int i=1;i<=n/6;i++)printf("8");
            printf("\n");
            continue;
        }
        if(n%7==5){
            printf("28");
            n-=12;
            for(int i=1;i<=n/6;i++)printf("8");
            printf("\n");
        }
        if(n%7==6){
            printf("68");
            n-=13;
            for(int i=1;i<=n/6;i++)printf("8");
            printf("\n");
        }
    }
    return 0;
}
