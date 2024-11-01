#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cmath>
#define int long long
#define rep(i,n) for(int i=1;i<=n;++i)
#define reb(i,n) for(int i=0;i<n;++i)
#define pii pair<int,int>
#define X first
#define Y second
#define ld long double
using namespace std;
const int N=1e5+7,M=1e6+7;
int n,p[N],m,l,V,dd[N],aa[N],vv[N],lf[M],rf[M],tot,xk;
pii tmp[N],x[N];
int solve(){
    tot=xk=0;
    cin>>n>>m>>l>>V;
    reb(i,M)lf[i]=rf[i]=0;
    rep(i,n)cin>>dd[i]>>vv[i]>>aa[i];
    rep(i,m)cin>>p[i];
    p[m+1]=l+1;p[0]=-1;
    rep(i,m){
        for(int j=p[i-1]+1;j<=p[i];++j)
        lf[j]=i;
        for(int j=p[i];j<p[i+1];++j)
        rf[j]=i;
    }
    rep(i,n){
        int d=dd[i],v=vv[i],a=aa[i];
        if(!lf[d])continue;
        if(a==0){
            if(v>V){
                tmp[++tot]={lf[d],rf[l]};
                // cout<<"#"<<i<<'\n';
            }
            continue;
        }
        // cout<<"pj\n";
        if(a<0&&v<=V)continue;
        if(a>0&&v>V){
            tmp[++tot]={lf[d],rf[l]};
            // cout<<"++"<<i<<'\n';
            continue;
        }
        if(a>0){
            ld ss=(V*V-v*v)/2./a;
            int ns=ss;ns++;
            ns+=d;
            if(ns>l)continue;
            // cout<<ns<<"->>>"<<l<<'\n';
            if(lf[ns]){
                tmp[++tot]={lf[ns],rf[l]};
                // cout<<"->"<<i<<'\n';
            }
        }else{
            ld ss=(V*V-v*v)/2./a;
            int ns=ss;
            if(ns==ss)--ns;
            ns+=d;
            if(ns>l)ns=l;
            if(lf[d]<=rf[ns]){
                tmp[++tot]={lf[d],rf[ns]};
                // cout<<"imp"<<i<<'\n';
            }
        }
    }
    sort(tmp+1,tmp+1+tot);
    cout<<tot<<' ';
    if(tot==0)return cout<<m<<"\n",0;
    int mn=1e9;
    // cout<<"!$^-----\n";
    // rep(i,tot)cout<<tmp[i].X<<" "<<tmp[i].Y<<"\n";
    // cout<<"======\n";
    for(int i=tot;i;--i){
        if(tmp[i].Y>=mn)continue;
        mn=tmp[i].Y;x[++xk]=tmp[i];
    }
    reverse(x+1,x+1+xk);
    int now=1,ip=1,num=0;
    while(now<xk+1){
        while(ip<m&&ip+1<=x[now].Y)++ip;
        while(x[now+1].X<=ip&&now<xk)++now;
        ++now;++num;
    }
    cout<<m-num<<'\n';
    return 0;
}
main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;cin>>T;while(T--)solve();
    return 0;
}