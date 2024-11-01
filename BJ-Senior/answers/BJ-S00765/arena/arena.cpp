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
const int N=2e5+7;
int a[N],n,m,c[N],aa[N],x[4],b[N],winner[20][N],f[20][N];
bool d[20][N],win[20][N],fg=1;
void build_win_tree(int n){
    int k=__lg(n-1)+1;
    rep(i,n)b[i]=a[i];
    for(int i=n+1;i<=(1<<k);++i)b[i]=-1;
    rep(i,(1<<k))winner[0][i]=i;
    rep(rd,k)
    rep(i,(1<<(__lg(n-1)+1-rd))){
        if(d[rd][i]==0){
            int x=winner[rd-1][i*2-1];
            if(b[x]>=rd)winner[rd][i]=x,win[rd][i]=0;
            else winner[rd][i]=winner[rd-1][i*2],win[rd][i]=1;
        }else{
            int x=winner[rd-1][i*2];
            if(b[x]>=rd)winner[rd][i]=x,win[rd][i]=1;
            else winner[rd][i]=winner[rd-1][i*2-1],win[rd][i]=0;
        }
    }
}
// void calcer(int rd,int i){
//     f[rd][i]=1e9;
//     int lf=f[rd-1][i*2-1],rf=f[rd-1][i*2];
//     if(d[rd][i]==0){
//         if(lf>=rd)f[rd][i]=lf;
//         else f[rd][i]=rf;
//     }else{
//         if(rf>=rd)f[rd][i]=rf;
//         else f[rd][i]=lf;
//     }
//     if(f[rd][i]>rd){
//         int now=
//     }
// }
int solve(){
    reb(i,4)cin>>x[i];
    if(fg)n=(1<<__lg(n));
    rep(i,n)a[i]=aa[i]^x[i%4];
    int k=__lg(n-1)+1;
    int ans=0;
    if(fg){
        build_win_tree(n);
        rep(i,m){
            int rd=__lg(c[i]);
            ans^=(winner[rd][1]*i);
        }
        cout<<ans<<'\n';
        return 0;
    }
    // rep(i,m){
    //     build_winner_tree(c[i]);
    //     int k=__lg(c[i]-1)+1;
    //     rep(i,(1<<k))f[0][i]=b[i];
    //     rep(rd,k)
    //     rep(i,(1<<(k-rd)))
    //     calcer(rd,i);
    // }
    return 0;
}
main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    rep(i,n)cin>>aa[i];
    rep(i,m)cin>>c[i],fg&=((c[i]&(c[i]-1))==0);
    rep(rd,__lg(n-1)+1){
        string s;cin>>s;
    rep(i,(1<<(__lg(n-1)+1-rd)))
    d[rd][i]=s[i-1]-'0';
    }
    int T;cin>>T;while(T--)solve();
    return 0;
}