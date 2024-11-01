#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5,H=19,L=1e6+5;
typedef long long ll;
ll V,v[N];
int n,m,l,d[N],a[N],p[N],cl[N],cr[N];
bool flg[N];
int sum[L],cnt[L];
struct Qry{
    int l,r;
    bool operator<(const Qry&qq)const{
        return r<qq.r;
    }
}q[N];
int tot=0;
multiset<int> S;
int nxt(int val){
    return *S.lower_bound(val);
}
int pre(int val){
    return *--S.upper_bound(val);
}
int g[N][H];
void initST(){
    for(int i=1;i<=tot;++i)g[i][0]=q[i].l;
    for(int j=1;j<H;++j){
        for(int i=1;i+(1<<j)-1<=tot;++i)g[i][j]=max(g[i][j-1],g[i+(1<<(j-1))][j-1]);
    }
}
int qryMax(int L,int R){
    int t=log2(R-L+1);
    return max(g[L][t],g[R-(1<<t)+1][t]);
}
int Nxt(int val,int x){
    int L=x+1,R=tot,res=tot+1;
    while(L<=R){
        int mid=(L+R)>>1;
        if(qryMax(x+1,mid)>val)res=mid,R=mid-1;
        else L=mid+1;
    }
    return res;
    // for(int i=x+1;i<=tot;++i){
    //     if(q[i].l>val)return i;
    // }
    // return tot+1;
}
int f[N];
void solve(){
    cin>>n>>m>>l>>V; ++l;
    for(int i=1;i<=n;++i)cin>>d[i]>>v[i]>>a[i],++d[i];
    S.clear();
    for(int i=1;i<=m;++i)cin>>p[i],++p[i],++cnt[p[i]],S.insert(p[i]); sort(p+1,p+m+1);
    for(int i=1;i<=l;++i)sum[i]=sum[i-1]+cnt[i];
    for(int i=1;i<=n;++i){
        if(v[i]<=V&&a[i]<=0){ flg[i]=0; continue; }
        if(a[i]==0){
            flg[i]=1,cl[i]=d[i],cr[i]=l;
            continue;
        }
        double dis=1.0*(V*V-v[i]*v[i])/(2.0*a[i]);
        bool tt=(V*V-v[i]*v[i])%(2*a[i])==0;
        if(a[i]>0&&d[i]+(int)floor(dis)>=l){ flg[i]=0; continue; }
        flg[i]=1;
        if(a[i]>0){
            cr[i]=l;
            if(v[i]>V)cl[i]=d[i];
            else cl[i]=d[i]+ceil(dis)+tt;
        }else cl[i]=d[i],cr[i]=min((int)(d[i]+floor(dis)-tt),l);
    }
    int res1=0; tot=0;
    for(int i=1;i<=n;++i){
        if(flg[i]&&sum[cr[i]]-sum[cl[i]-1]>0){
            ++res1;
            q[++tot]={nxt(cl[i]),pre(cr[i])};
            // cout<<"illegal:"<<i<<'\n';
        }
    }
    if(res1==0){
        cout<<0<<' '<<m<<'\n';
        for(int i=1;i<=m;++i)--cnt[p[i]];
        for(int i=1;i<=l;++i)sum[i]=0;
        return;
    }
    sort(q+1,q+tot+1);
    initST();
    f[tot+1]=0;
    for(int i=tot;i>=1;--i)f[i]=f[Nxt(q[i].r,i)]+1;
    cout<<res1<<' '<<m-f[1]<<'\n';
    // memset(cnt,0,sizeof cnt),memset(sum,0,sizeof sum),memset(f,0,sizeof f),memset(g,0,sizeof g);
    for(int i=1;i<=m;++i)--cnt[p[i]];
    for(int i=1;i<=l;++i)sum[i]=0;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}