#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
vector<pii> e[200005];
vector<int>v[200005];
int vis[200005][105],dp[200005],a[200005],l[200005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;cin>>t;
    while(t--){
        memset(vis,0,sizeof(vis)),memset(dp,0,sizeof(dp));
        int n,k,Q,bs=0,mx=0,s=0;cin>>n>>k>>Q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                cin>>a[bs+j],mx=max(mx,a[bs+j]),v[a[bs+j]].emplace_back(bs+j);
                if(j>1) e[bs+j-1].push_back({bs+j,0});
                if(a[bs+j]==1&&!s) s=bs+j;
            }
            bs+=l[i];
        }
        for(int i=1;i<=mx;i++){
            for(int j=1;j<v[i].size();j++) e[v[i][j-1]].push_back({v[i][j],1});
        }
        deque<int> q,qd;
        q.push_back(s),qd.push_back(0);
        while(!q.empty()){
            int u=q.front(),d=qd.front();
            q.pop_front(),qd.pop_front();
            //cout<<u<<' '<<dp[u]<<' '<<d<<'\n';
            for(int i=0;i<e[u].size();i++){
                if(e[u][i].second&&d<100&&!vis[e[u][i].first][d+1]) dp[e[u][i].first]=1,vis[e[u][i].first][d]=1,q.push_back(e[u][i].first),qd.push_back(d+1);
                else{
                    if(dp[u]==k-1||d>100||!vis[e[u][i].first][d]) continue;
                    dp[e[u][i].first]=dp[u]+1,q.push_front(e[u][i].first),qd.push_front(d),vis[e[u][i].first][d]=1;
                }
            }
        }
        while(Q--){
            int r,c,f=0;cin>>r>>c;
            for(int i:v[c]) if(vis[i][r]) f=1;
            cout<<f<<'\n';
        }
    }
    return 0;
}
//CSP rp++;
