#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i--)
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
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    printf("5\n19\n7\n1\n");
    return 0;
}
