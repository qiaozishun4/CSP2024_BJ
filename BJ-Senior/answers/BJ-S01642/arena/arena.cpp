#include<bits/stdc++.h>
using namespace std;
#define int long long
using PII=pair<int,int>;
#define Set(x,y) memset(x,y,sizeof(x))
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define irep(i,x,y) for(int i=y;i>=x;--i)
#define File(str) \
    freopen(str".in","r",stdin);\
    freopen(str".out","w",stdout)
#define Dbg(fmt,...) \
    fprintf(stderr,"[%s:%d %s]" fmt "\n",__FILE__,__LINE__,__FUNCTION__,##__VA_ARGS__)
#define fi first
#define se second
#define pb push_back
#define TLC (double)clock()/CLOCKS_PER_SEC<0.91
const int N=3030,P=1e9+7;
int n,m,a[N],qq[N];
int ans[N];
char s[N][N];
int get(int l,int r,int dep,int id){
    if(l==r) {
        if(l==1) ans[dep]=l;
        return l;
    }
    int mid=l+r>>1;
    int res1=get(l,mid,dep-1,id<<1);
    int res2=get(mid+1,r,dep-1,id<<1|1);
    int ch=s[dep][id];
    if(ch==0) ch=a[res1]>=dep?res1:res2;
    else ch=a[res2]>=dep?res2:res1;
    if(l==1) ans[dep]=ch;
    return ch;
}
main(){
    //File("arena");
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    rep(i,1,n)cin>>a[i];
    rep(i,1,m)cin>>qq[i];
    int k=0;
    while((1<<k)<n) ++k;
    rep(i,0,k-1) cin>>s[i];
    int T;cin>>T;T=1;
    int X[4];
    rep(i,0,3)cin>>X[i];
    rep(i,1,n)a[i]=a[i]^X[i&3];
    get(1,1<<__lg(n),__lg(n),0);
    //for(int i=0;i<=__lg(n);++i)
        //cout<<ans[i]<<'\n';
    int Ans=0;
    rep(i,1,m)
        Ans^=i*ans[__lg(qq[i])];
    cout<<Ans<<'\n';
}
