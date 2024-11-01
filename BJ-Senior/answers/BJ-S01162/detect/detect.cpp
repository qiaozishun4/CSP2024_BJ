#include<bits/stdc++.h>
#include<decimal/decimal>
using namespace std;
enum{_n=100007};
struct node{
    mutable int l;
    int r;
    bool operator<(node $)const{
        return r<$.r;
    }
};
basic_string<node> G;
int d[_n],v[_n],a[_n],p[_n];
int main(){
freopen("detect.in","r",stdin);
freopen("detect.out","w",stdout);
cin.tie(0)->sync_with_stdio(0);
int T;
cin>>T;
while(T--){
    int n,m,L,K,cnt=0; G={};
    cin>>n>>m>>L>>K;
    for(int i=0;i<n;++i)
        cin>>d[i]>>v[i]>>a[i];
    for(int i=0;i<m;++i)
        cin>>p[i];
    for(int i=0;i<n;++i)
        if(v[i]>K){
            int t0=lower_bound(p,p+m,d[i])-p,
                t1=a[i]<0?lower_bound(p,p+m,
                   d[i]+ceil((K*K-v[i]*v[i])/(2.*a[i])))-p-1:m-1;
            if(t0<=t1) G+={t0,t1},++cnt;
        }else if(a[i]>0){
            int t=upper_bound(p,p+m,
                    d[i]+floor((K*K-v[i]*v[i])/(2.*a[i])))-p;
            if(t<m) G+={t,m-1},++cnt;
        }
    if(!cnt) cout<<0<<' '<<m<<'\n';
    else{
    sort(&G[0],&G[cnt]);
    int lst=G[0].r,k=1;
    for(int i=0;i<cnt;++i)
        if(G[i].l>lst) ++k,lst=G[i].r;
    cout<<cnt<<' '<<m-k<<'\n';
    }
}
}