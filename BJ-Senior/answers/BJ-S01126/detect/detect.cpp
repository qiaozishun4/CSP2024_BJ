// 会赢吗？
//14:41 start B
//14:43 xian fang afng
//15:19 kai shi xie
//15:40 finish
#include <bits/stdc++.h>
#define int long long
#define _1 first
#define _2 second
#define rep(i,a,b,c)    for(int i=(a),i##end=(b);i<=(i##end);i+=(c))
#define per(i,a,b,c)    for(int i=(a),i##end=(b);i>=(i##end);i-=(c))
#define pb push_back
#define pii pair<int,int>
#define vint vector<int>
using namespace std;

const int maxn=1.2e5;

struct Car{
    int a,v,d;
}c[maxn];
int p[maxn];
pii o[maxn];
int cc,n,m,l,b;

void gen(int l,int r){
    if(l>r) return ;
    int tl=lower_bound(p+1,p+1+m,l)-p,tr=upper_bound(p+1,p+1+m,r)-p-1;
    if(tl>tr)   return ;
    o[++cc]={tl,tr}; 
}

void solve(){
    cin>>n>>m>>l>>b;
    rep(i,1,n,1)    cin>>c[i].d>>c[i].v>>c[i].a;
    rep(i,1,m,1)    cin>>p[i];
    cc=0;
    rep(i,1,n,1){
        auto [a,v,d]=c[i];
        if(a==0 && v>b) gen(d,l);
        if(a>0){
            if(v>b) gen(d,l);
            else{
                int fz=b*b+2*a*d-v*v,fm=2*a;
                int x=fz/fm+1;
                // cerr<<d<<" "<<x<<endl;
                gen(x,l);
            }
        }else if(a<0 && v>b){
            if(v<=b)    continue ;
            int fz=(b*b-v*v)+2*a*d,fm=2*a;
            fz=-fz,fm=-fm;
            int x;
            if(fz%fm==0)    x=fz/fm-1;
            else            x=fz/fm;
            gen(d,min(x,l));
        } 
    }
    cout<<cc<<" ";
    sort(o+1,o+1+cc,[](pii x,pii y){
        if(x._2==y._2)  return x._1<y._1;
        return x._2<y._2;
    });
    int a2=0,lst=-1000'000'000'000'000'000;
    rep(i,1,cc,1){
        auto [l,r]=o[i];
        // cerr<<l<<" "<<r<<endl;
        if(lst<l)   lst=r,a2++;
    }
    cout<<m-a2;
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;cin>>T;
    while(T--)  solve();
    return 0;
}