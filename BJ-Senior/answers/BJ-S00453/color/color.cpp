#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,a[N];
// namespace Part1{
//     const int MAXN=2005;
//     ll f[MAXN][MAXN];
//     void solve(){
//         a[0]=-1e9; f[1][1]=0;
//         for(int i=2;i<=n;++i){
//             for(int j=1;j<=i;++j){
//                 if(i!=j)f[i][j]=f[i-1][j]+(a[i-1]==a[i])*a[i];
//                 else{
//                     f[i][j]=0;
//                     for(int k=1;k<=i-1;++k)f[i][j]=max(f[i][j],f[i-1][k]+(a[k-1]==a[i])*a[i]);
//                 }
//             }
//         }
//         ll res=0;
//         for(int i=1;i<=n;++i)res=max(res,f[n][i]);
//         cout<<res<<'\n';
//     }
// };
ll f[N][2];
const int V=1e6+5;
ll s[N],maxv[V<<2];
void psu(int id){
    maxv[id]=max(maxv[id<<1],maxv[id<<1|1]);
}
void upd(int id,int l,int r,int x,ll v,bool op){    // 0: Add 1: Max
    if(l==r){
        if(op==0)maxv[id]+=v;
        else maxv[id]=max(maxv[id],v);
        return;
    }
    int mid=(l+r)>>1; x<=mid?upd(id<<1,l,mid,x,v,op):upd(id<<1|1,mid+1,r,x,v,op);
    psu(id);
}
void work(){
    a[0]=0;
    for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i]*(a[i]==a[i-1]);
    for(int i=0;i<(V<<2);++i)maxv[i]=-1e15;
    f[1][0]=0;
    upd(1,1,V-1,V-2,f[1][0]-s[1],1);
    for(int i=2;i<=n;++i){
        f[i][1]=max(f[i-1][0],f[i-1][1])+a[i]*(a[i]==a[i-1]);
        upd(1,1,V-1,a[i],a[i],0);
        f[i][0]=maxv[1]+s[i-1];
        upd(1,1,V-1,a[i],-a[i],0);
        upd(1,1,V-1,a[i-1],f[i][0]-s[i],1);
    }
    cout<<max(f[n][0],f[n][1])<<'\n';
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    work();
    // if(n<=2000)Part1::solve();
    // else work();
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}