#include<bits/stdc++.h>
using namespace std;
#define int long long
using PII=pair<int,int>;
#define pb push_back
#define fi first
#define se second
#define TLC (double)clock()/CLOCKS_PER_SEC<0.91
const int N=1010,P=1e9+7;
#define File(str) \
    freopen(str".in","r",stdin);\
    freopen(str".out","w",stdout)
#define Dbg(fmt,...)\
    fprintf(stderr,"[%s:%d %s]:" fmt "\n",__FILE__,__LINE__,__FUNCTION__,##__VA_ARGS__)
char mp[N][N];
int n,m,k,x,y,d;
bool vis[N][N];
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
void Solve(){
    memset(vis,0,sizeof vis);
    memset(mp,0,sizeof mp);
    cin>>n>>m>>k>>x>>y>>d;
    for(int i=1;i<=n;++i)
        cin>>mp[i]+1;
    vis[x][y]=1;
    for(int st=1;st<=k;++st){
        int rx=x+dx[d],ry=y+dy[d];
        if(rx>=1&&rx<=n&&ry>=1&&ry<=m&&mp[rx][ry]=='.')vis[x=rx][y=ry]=1;
        else d=d+1&3;
    }
    int ans=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(vis[i][j]) ++ans;
    cout<<ans<<'\n';
}
signed main(){
    File("explore");
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--)Solve();
    return 0;
}
