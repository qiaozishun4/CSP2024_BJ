#include<bits/stdc++.h>
#define int long long
#define rep(i,S,T) for(int i=S;i<=T;++i)
#define per(i,T,S) for(int i=T;i>=S;--i)
using namespace std;
template<typename T>
inline void read(T &x){
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    x*=f;
}
const int N=1e5+10,L=30;
int T,n,m,prea[N],a[N],c[N],d[L][N],flag,lg,now;
int x[5],ans;
int qpow(int x,int k){
    int res=1;
    while(k){
        if(k&1) res=res*x;
        x=x*x;
        k>>=1;
    }
    return res;
}
void solve_A(int x){
    vector<int> v;
    rep(i,1,c[x]) v.push_back(i);
    int l=log2(c[x]);
    rep(i,1,l){
        vector<int> tmp;
        rep(j,0,v.size()-1){
            if(j%2==0){
                int x=d[i][j/2+1];
                if(x==1) tmp.push_back(a[v[j+1]]>=i?v[j+1]:v[j]);
                else tmp.push_back(a[v[j]]>=i?v[j]:v[j+1]);
            }
        }
        v=tmp;
    }
    ans^=x*v[0];
}
void solve(){
    rep(i,0,3) read(x[i]);
    rep(i,1,n) a[i]=prea[i]^x[i%4];
    ans=0;
    if(!flag) rep(i,1,m) solve_A(i);
    printf("%lld\n",ans);
}
signed main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    read(n);read(m);
    rep(i,1,n) read(prea[i]);
    rep(i,1,m) read(c[i]);
    flag=0;
    rep(i,1,m) flag|=(c[i]!=(c[i]&-c[i]));
    lg=0,now=1;while(now<n) lg++,now*=2;
    now/=2;
    rep(i,1,lg){
        rep(j,1,now){
            char c;cin>>c;
            d[i][j]=c-'0';
        }now/=2;
    }
    read(T);
    while(T--) solve();
    return 0;
}
