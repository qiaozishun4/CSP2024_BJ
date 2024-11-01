#include <iostream>
using namespace std;
typedef long long ll;
int T, n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        if(n<7){
            if(n==1) puts("-1");
            if(n==2) puts("1");
            if(n==3) puts("7");
            if(n==4) puts("4");
            if(n==5) puts("2");
            if(n==6) puts("6");
            continue;
        }
        int t=n/7-1, x=n-7*t;
        if(x==7) printf("8");
        if(x==8) printf("10");
        if(x==9) printf("18");
        if(x==10){
            if(n==10) printf("22\n");
            else{
                printf("200");
                for(int i=1;i<=t-1;i++) printf("8");
                printf("\n");
            }
            continue;
        }
        if(x==11) printf("20");
        if(x==12) printf("28");
        if(x==13) printf("68");
        for(int i=1;i<=t;i++) printf("8");
        printf("\n");
    }
    return 0;
}
