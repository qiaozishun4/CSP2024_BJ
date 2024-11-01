#include<bits/stdc++.h>
using namespace std;
void f(){
    int n;
    scanf("%d",&n);
    if(n%7==1){
        printf("-1\n");
        return;
    }
    if(n==6){
        printf("6\n");
        return;
    }
    int c=0;
    while(n>=7){
        c++;
        n-=7;
    }
    if(n==2){
        printf("1");
        for(int i=0; i<c; i++){
            printf("8");
        }
        printf("\n");
    }else if(n==3){
        printf("7");
        for(int i=0; i<c; i++){
            printf("8");
        }
        printf("\n");
    }else if(n==4){
        if(c>0){
            printf("20");
            for(int i=0; i<c-1; i++){
                printf("8");
            }
            printf("\n");
        }else{
            printf("4\n");
        }
    }else if(n==5){
        printf("2");
        for(int i=0; i<c; i++){
            printf("8");
        }
        printf("\n");
    }else if(n==6){
        printf("6");
        for(int i=0; i<c; i++){
            printf("8");
        }
        printf("\n");
    }else{
        for(int i=0; i<c; i++){
            printf("8");
        }
        printf("\n");
    }
    return;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        f();
    }
    return 0;
}
