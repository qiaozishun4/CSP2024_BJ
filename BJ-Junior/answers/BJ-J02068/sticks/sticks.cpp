#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        if(n==1){
            printf("-1");
        }else if(n==2){
            printf("1");
        }else if(n==3){
            printf("7");
        }else if(n==4){
            printf("4");
        }else if(n==5){
            printf("2");
        }else if(n==6){
            printf("6");
        }else if(n==7){
            printf("8");
        }else if(n==8){
            printf("10");
        }else if(n==9){
            printf("18");
        }else if(n==10){
            printf("22");
        }else if(n==11){
            printf("20");
        }else if(n%7==0){
            for(int i=1;i<=n/7;i++){
                printf("8");
            }
        }else if(n%7==1){
            printf("10");
            for(int i=1;i<n/7;i++){
                printf("8");
            }
        }else if(n%7==2){
            printf("18");
            for(int i=1;i<n/7;i++){
                printf("8");
            }
        }else if(n%7==3){
            printf("200");
            for(int i=1;i<n/7-1;i++){
                printf("8");
            }
        }else if(n%7==4){
            printf("20");
            for(int i=1;i<n/7;i++){
                printf("8");
            }
        }else if(n%7==5){
            printf("28");
            for(int i=1;i<n/7;i++){
                printf("8");
            }
        }else if(n%7==6){
            printf("68");
            for(int i=1;i<n/7;i++){
                printf("8");
            }
        }
        printf("\n");
    }
    return 0;
}
