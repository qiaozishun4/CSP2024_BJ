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
const int N=1e6+10;
int T,n,f[N],a[N],sum[N],val[N];
int mxf[N],pos[N],g[N],b[N];
vector<int> mf[N];
int book[N],bcnt;
void solve(){
    read(n);
    bcnt=0;
    rep(i,1,n) read(a[i]),f[i]=0,book[++bcnt]=a[i],g[i]=0;
    sort(book+1,book+n+1);
    bcnt=unique(book+1,book+n+1)-book-1;
    rep(i,0,n) mf[i].clear(),mxf[i]=0;
    rep(i,1,n+1){
        mf[a[i-1]].push_back(0);pos[i]=mf[a[i-1]].size()-1;
    }
    rep(i,2,n) val[i]=(a[i]==a[i-1])*a[i],sum[i]=sum[i-1]+val[i];
    rep(i,2,n){
        f[i]=max(f[i],mxf[i-1]+sum[i-1]-val[i]);
        if(pos[i+1]!=0) f[i]=max(f[i],mf[a[i]][pos[i+1]-1]+sum[i-1]-val[i]+a[i]);
        mxf[i]=max(mxf[i-1],f[i]-sum[i]);
        if(pos[i]==0) mf[a[i-1]][0]=f[i]-sum[i];
        else mf[a[i-1]][pos[i]]=max(mf[a[i-1]][pos[i]-1],f[i]-sum[i]);

    }
    int ans=0;
    rep(i,1,n) ans=max(ans,f[i]+sum[n]-sum[i]);
    printf("%lld\n",ans);
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    read(T);while(T--) solve();
    return 0;
}
