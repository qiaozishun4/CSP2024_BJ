#include<bits/stdc++.h>
using namespace std;
int n,T;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        scanf("%d",&n);
        if(n<7){
            if(n==0) printf("-1");
            else if(n==1) printf("-1");
            else if(n==2) printf("1");
            else if(n==3) printf("7");
            else if(n==4) printf("4");
            else if(n==5) printf("2");
            else if(n==6) printf("6");
            printf("\n");
            continue;
        }
        int rem=n%7;
        if(rem==0) printf("8");
        else if(rem==1) printf("10");
        else if(rem==2) printf("18");
        else if(rem==3) printf("22");
        else if(rem==4) printf("20");
        else if(rem==5) printf("28");
        else if(rem==6) printf("68");
        for(int i=7;i<n-7;i+=7) printf("8");
        printf("\n");
    }
    return 0;
}
