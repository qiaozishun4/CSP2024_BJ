#include<bits/stdc++.h>
using namespace std;
int n,m,s,p;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        m=(n+6)/7;
        s=n%7;
        if(s==0){
            p=m;
        }else if(s==1){
            if(m==1){
                printf("-1");
                p=0;
            }else{
                printf("10");
                p=m-2;
            }
        }else if(s==2){
            printf("1");
            p=m-1;
        }else if(s==3){
            if(m==1){
                printf("7");
                p=0;
            }else if(m==2){
                printf("22");
                p=0;
            }else{
                printf("200");
                p=m-3;
            }
        }else if(s==4){
            if(m==1){
                printf("4");
                p=0;
            }else{
                printf("20");
                p=m-2;
            }
        }else if(s==5){
            printf("2");
            p=m-1;
        }else{
            printf("6");
            p=m-1;
        }
        for(int i=1;i<=p;++i){
            printf("8");
        }
        printf("\n");
    }
    return 0;
}