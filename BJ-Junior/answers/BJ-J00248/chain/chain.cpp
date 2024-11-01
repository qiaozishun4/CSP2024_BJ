#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define int long long
const int maxn=2e5+10,inf=1e17;
int t,n,k,q,s[maxn],l,dis[maxn],ans[maxn],mx;
pair<int,pair<int,int>>c[maxn];
vector<pair<int,int>>g[maxn];
set<pair<int,pair<int,int>>>st;
void bfs(){
    queue<pair<int,int>>q;
    int cnt=1;
    for(auto x:g[1]){
        q.push(x);
        // cout<<x.first<<'\n';
        dis[x.first]=1;
        auto itr=st.lower_bound({dis[x.first],{x.first,0}});
        // if(dis[ux]==2&&ux==4)cout<<dis[ux]<<' '<<ux<<' '<<(*itr).second.second<<'\n';
        if((*itr).first==dis[x.first]&&(*itr).second.first==x.first){
            ans[(*itr).second.second]=1;
            // cout<<dis[ux]<<' '<<ux<<' '<<(*itr).second.second<<'\n';
        }
    }
    while(q.size()){
        auto u=q.front();
        int ux=u.first,uy=u.second;
        auto itr=st.lower_bound({dis[u.first],{u.first,0}});
        // if(dis[ux]==2&&ux==4)cout<<dis[ux]<<' '<<ux<<' '<<(*itr).second.second<<'\n';
        if((*itr).first==dis[u.first]&&(*itr).second.first==u.first){
            ans[(*itr).second.second]=1;
            // cout<<dis[ux]<<' '<<ux<<' '<<(*itr).second.second<<'\n';
        }
        // cout<<ux<<' '<<uy<<'\n';
        q.pop();
        for(auto y:g[ux]){
            if(y.second!=uy){
                q.push(y);
                dis[y.first]=dis[ux]+1;
                auto itr=st.lower_bound({dis[y.first],{y.first,0}});
                // if(dis[ux]==2&&ux==4)cout<<dis[ux]<<' '<<ux<<' '<<(*itr).second.second<<'\n';
                if((*itr).first==dis[y.first]&&(*itr).second.first==y.first){
                    ans[(*itr).second.second]=1;
                    // cout<<dis[ux]<<' '<<ux<<' '<<(*itr).second.second<<'\n';
                }
            }
        }
        if(dis[ux]>mx)return;
    }
}
signed main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        mx=0;
        for(int i=0;i<maxn;i++)g[i].clear();
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l;
            for(int j=1;j<=l;j++)cin>>s[j];
            for(int j=1;j<=l;j++){
                for(int p=j+1;p<=min(l,j+k-1);p++){
                    g[s[j]].push_back({s[p],i});
                }
            }
        }
        for(int i=1;i<=q;i++){
            cin>>c[i].first>>c[i].second.first;
            mx=max(mx,c[i].first);
            c[i].second.second=i;
            // cout<<i<<' '<<c[i].first<<' '<<c[i].second.first<<"*\n";
            st.insert(c[i]);
        }
        bfs();
        for(int i=1;i<=q;i++)cout<<ans[i]<<'\n';
    }
}