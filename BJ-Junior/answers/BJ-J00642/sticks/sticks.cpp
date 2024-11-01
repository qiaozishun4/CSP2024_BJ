#include<bits/stdc++.h>
using namespace std;

int T,n;
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                putchar('8');
            }
            puts("");
            continue;
        }
        if(n%7==1){
            if(n==1){
                puts("-1");
                continue;
            }
            putchar('1');
            putchar('0');
            for(int i=1;i<=(n-8)/7;i++){
                putchar('8');
            }
            puts("");
            continue;
        }
        if(n%7==2){
            putchar('1');
            for(int i=1;i<=(n-2)/7;i++){
                putchar('8');
            }
            puts("");
            continue;
        }
        if(n%7==3){
            if(n==3){
                puts("7");
                continue;
            }
            if(n==10){
                puts("22");
                continue;
            }
            putchar('2');
            putchar('0');
            putchar('0');
            for(int i=1;i<=(n-17)/7;i++){
                putchar('8');
            }
            puts("");
            continue;
        }
        if(n%7==4){
            if(n==4){
                puts("4");
                continue;
            }
            putchar('2');
            putchar('0');
            for(int i=1;i<=(n-11)/7;i++){
                putchar('8');
            }
            puts("");
            continue;
        }
        if(n%7==5){
            putchar('2');
            for(int i=1;i<=(n-5)/7;i++){
                putchar('8');
            }
            puts("");
            continue;
        }
        if(n%7==6){
            putchar('6');
            for(int i=1;i<=(n-6)/7;i++){
                putchar('8');
            }
            puts("");
            continue;
        }
    }
    return 0;
}
