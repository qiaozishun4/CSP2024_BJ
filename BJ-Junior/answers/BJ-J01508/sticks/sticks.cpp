#include <bits/stdc++.h>
using namespace std;

int num[8] = {0, -1, 1, 7, 4, 2, 6, 8};
int n;
int T;

void print(int k){
    while(k-7>=0){
        k -= 7;
        printf("8");
    }
}

void dfs(int k){
    if(k%7==0){
        print(k);
    }else if(k%7==1){
        printf("10");
        print(k-7);
    }else if(k%7==2){
        printf("1");
        print(k);
    }else if(k%7==3){
        printf("22");
        print(k-7);
    }else if(k%7==4){
        printf("20");
        print(k-7);
    }else if(k%7==5){
        printf("2");
        print(k);
    }else{
        printf("68");
        print(k-7);
    }
}

int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        n = max(n, 1);
        if(n>=1 && n<=7) printf("%d", num[n]);
        else if(n>=8) dfs(n);
        printf("\n");
    }

    return 0;
}
