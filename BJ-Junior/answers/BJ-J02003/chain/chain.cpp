#include<bits/stdc++.h>
using namespace std;
#define int long long
using PII=pair<int,int>;
#define pb push_back
#define fi first
#define se second
#define TLC (double)clock()/CLOCKS_PER_SEC<0.91
const int N=1e5+10,P=1e9+7;
#define File(str) \
    freopen(str".in","r",stdin);\
    freopen(str".out","w",stdout)
#define Dbg(fmt,...)\
    fprintf(stderr,"[%s:%d %s]:" fmt "\n",__FILE__,__LINE__,__FUNCTION__,##__VA_ARGS__)
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define Set(aaa,bbb) memset(aaa,bbb,sizeof(aaa))
void smin(int&a,int b){a=min(a,b);}
int n,k,q,a[N<<1],tot,l[N],r[N],bel[N<<1],At[N],tem[N],tem1[N];
struct Qry{
    int num,id;
};
vector<Qry> qq[110];
vector<int> pos[N];
int ans[N];
bool vis[N];
void Solve(){
    cin>>n>>k>>q;
    rep(i,0,N-1)pos[i].clear();
    rep(i,0,109)qq[i].clear();
    Set(l,0),Set(r,0),Set(bel,0),Set(At,0),Set(ans,0),Set(vis,0);
    rep(i,1,n){
        int len;
        cin>>len;
        l[i]=tot+1;
        for(int j=1;j<=len;++j){
            cin>>a[++tot];
            pos[a[tot]].pb(tot);
            bel[tot]=i;
        }
        r[i]=tot;
    }
    rep(i,1,q){
        int r,c; cin>>r>>c;
        qq[r-1].pb({c,i});
    }
    Set(At,0x3f);
    for(int x:pos[1])
        smin(At[bel[x]],x);
    Set(tem,0x3f);
    rep(tt,1,100){
        rep(i,1,n) tem1[i]=At[i];
        rep(i,1,n)
            for(int j=tem1[i]+1;j<=min(tem[i],r[i]);++j)
                for(int k:pos[a[j]]) smin(At[bel[k]],k);
        rep(i,1,n) tem[i]=tem1[i];
        rep(i,1,n)rep(j,At[i],tem1[i]) vis[a[j]]=1;
        for(auto[x,qid]:qq[tt]){
            ans[qid]=vis[x];
        }
    }
    rep(i,1,q)cout<<ans[i]<<'\n';
}
signed main(){
    File("chain");
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--)Solve();
    return 0;
}

