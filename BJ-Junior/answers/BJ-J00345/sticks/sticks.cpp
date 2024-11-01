#include<bits/stdc++.h>
using namespace std;
#define pt printf
#define fr(i,a,b) for(int i(a);i<=b;i++)
#define rf(i,a,b) for(int i(a);i>=b;i--)
#define eb emplace_back
#define pii pair<int,int>
#define file(f1,f2) if(f1!="")freopen(f1,"r",stdin);if(f2!="")freopen(f2,"w",stdout);
#define pc putchar
template<typename A,typename...B>inline void rd(A&x,B&...y) {
    char ch;bool f=0;
    while(!isdigit(ch=getchar()))if(ch=='-')f=1;
    x=0;do{x=(x<<1)+(x<<3)+(ch^48);}while(isdigit(ch=getchar()));
    if(f)x=-x;
    if constexpr(sizeof...(y))rd(y...);
}
int a[10]={6,2,5,5,4,5,6,3,7,6};
void so(int n){
    if(n==1){
        pt("-1\n");
        return;
    }
    int len=(n+7-1)/7;
    bool lead=1;
    while(len){
        int vv=0,nn;
        fr(v,lead,9){
            nn=n-a[v];
            if(0<=nn&&nn<=(len-1)*7&&nn!=1){
                vv=v;break;
            }
        }
        if(vv)lead=0;
        pc(vv+'0');
        n=nn,len--;
    }
    pc('\n');
}
signed main() {
    file("sticks.in","sticks.out");
    int t;
    rd(t);
    while(t--) {
        int n;
        rd(n);
        so(n);
    }
    return 0;
}
