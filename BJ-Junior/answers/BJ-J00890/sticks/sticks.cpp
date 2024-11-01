#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i++)
#define pll pair<ll,ll>
#define mkp make_pair
using namespace std;
inline ll read(){
    ll x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-'){
            f=-1;
        }
        ch=getchar();
    }
    while(isdigit(ch)){
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ll _=read();
    while(_--){
        ll n=read();
        if(n==1){
            printf("-1\n");
            continue;
        }
        if(n<=7){
            if(n==2){
                printf("1\n");
            }else if(n==3){
                printf("7\n");
            }else if(n==4){
                printf("4\n");
            }else if(n==5){
                printf("2\n");
            }else if(n==6){
                printf("6\n");
            }else if(n==7){
                printf("8\n");
            }
            continue;
        }
        ll t=n%7,p=n/7;
        if(t==1){
            p--;
            printf("10");
            rep(i,1,p){
                printf("8");
            }
            printf("\n");
        }else if(t==0){
            rep(i,1,p){
                printf("8");
            }
            printf("\n");
        }else if(t==4){
            p--;
            printf("20");
            rep(i,1,p){
                printf("8");
            }
            printf("\n");
        }else if(t==2){
            printf("1");
            rep(i,1,p){
                printf("8");
            }
            printf("\n");
        }else if(t==3){
            p--;
            printf("22");
            rep(i,1,p){
                printf("8");
            }
            printf("\n");
        }else if(t==5){
            printf("2");
            rep(i,1,p){
                printf("8");
            }
            printf("\n");
        }else if(t==6){
            printf("6");
            rep(i,1,p){
                printf("8");
            }
            printf("\n");
        }
    }
    return 0;
}
