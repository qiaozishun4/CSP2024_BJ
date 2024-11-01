#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n;
        scanf("%d",&n);
        if(n==1){
            printf("-1\n");
            continue;
        }
        if(n%7==0){
            for(int j=1;j<=n/7;j++)
                printf("8");
            printf("\n");
        }
        if(n%7==1){
            printf("10");
            for(int j=1;j<n/7;j++)
                printf("8");
            printf("\n");
        }
        if(n%7==2){
            printf("1");
            for(int j=1;j<=n/7;j++)
                printf("8");
            printf("\n");
        }
        if(n%7==3){
            printf("7");
            for(int j=1;j<=n/7;j++)
                printf("8");
            printf("\n");
        }
        if(n%7==4){
            printf("20");
            for(int j=1;j<n/7;j++)
                printf("8");
            printf("\n");
        }
        if(n%7==5){
            printf("17");
            for(int j=1;j<n/7;j++)
                printf("8");
            printf("\n");
        }
        if(n%7==6){
            printf("6");
            for(int j=1;j<=n/7;j++)
                printf("8");
            printf("\n");
        }
    }
}
