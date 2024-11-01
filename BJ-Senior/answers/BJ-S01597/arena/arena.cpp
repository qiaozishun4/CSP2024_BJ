#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define M 25
#define int long long
int n,m,T,k,pwk,out,lb[N],o[N],a[N],c[N],X[5];
string s[M];
int win[N<<2],R[N<<2],nn;
void build(int p,int l,int r,int d){
    if(l==r){
        win[p]=l;
        return;
    }
    int mid=(l+r)>>1;
    build(p<<1,l,mid,d-1),build(p<<1|1,mid+1,r,d-1);
    if(r<=n){
        if(R[p]==0){
            if(a[win[p<<1]]>=d) win[p]=win[p<<1];
            else win[p]=win[p<<1|1];
        }else{
            if(a[win[p<<1|1]]>=d) win[p]=win[p<<1|1];
            else win[p]=win[p<<1];
        }
    }else win[p]=-1;
}
inline int ss(int l,int r){
    return (l+r)*(r-l+1)/2;
}
struct info{int sm,mn;multiset<int> s;};
info query(int p,int l,int r,int d,int ql,int qr){
    if(1<<d>qr){
        int mid=(l+r)>>1;
        return query(p<<1,l,mid,d-1,ql,qr);
    }
    if(ql<=l&&r<=qr){
        info i;
        i.sm=i.mn=win[p];
        i.s.insert(win[p]);
        return i;
    }
    int mid=(l+r)>>1;
    if(qr<=mid){
        int ar=ss(mid+1,r);
        if(R[p]==0){
            auto pl=query(p<<1,l,mid,d-1,ql,qr);
            auto it=pl.s.begin();
            while(*it<d){
                pl.sm-=*it;
                it++;
            }
            pl.s.erase(pl.s.begin(),it);
            if(pl.mn<d){
                pl.sm+=ss(mid+1,r);
                pl.mn=-1;
            }
            if(pl.mn!=-1) pl.mn=pl.s.size()?*pl.s.begin():1e9;
            return pl;
        }else{
            auto pl=query(p<<1,l,mid,d-1,ql,qr);
            pl.sm+=ss(mid+1,r),pl.mn=-1;
            return pl;
        }
    }else{
        auto pl=query(p<<1,l,mid,d-1,ql,qr),pr=query(p<<1|1,mid+1,r,d-1,ql,qr);
        if(R[p]==1) swap(pl,pr);
        auto it=pl.s.begin();
        while(*it<d){
            pl.sm-=*it;
            it++;
        }
        pl.s.erase(pl.s.begin(),it);
        if(pl.mn<d){
            pl.sm+=pr.sm,pl.mn=min(pl.mn,pr.mn);
            for(int v:pr.s) pl.s.insert(v);
        }
        if(pl.mn!=-1) pl.mn=pl.s.size()?*pl.s.begin():1e9;
        return pl;
    }
}
signed main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>o[i];
    for(int i=1;i<=m;++i) cin>>c[i];
    k=0,pwk=1;
    while(pwk<n) k++,pwk<<=1;
    for(int i=1;i<=k;++i) cin>>s[i];
    for(int i=k;i>=1;--i){
        for(int j=0;j<s[i].size();++j) R[++nn]=s[i][j]-'0';
    }
    cin>>T;
    while(T--){
        for(int i=0;i<4;++i) cin>>X[i];
        for(int i=1;i<=n;++i) a[i]=o[i]^X[i%4];
        build(1,1,pwk,k);
        out=0;
        for(int i=1;i<=m;++i) out^=i*query(1,1,pwk,k,1,c[i]).sm;
        cout<<out<<'\n';
    }
}
