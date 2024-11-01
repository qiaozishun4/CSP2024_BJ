#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,l,v;
struct car{
    double d,v,a;
};
struct over_speed{
    double l,r;
};
vector<car>cnt;
vector<over_speed>vis;
vector<over_speed>will;
int ans=0,ans2=1e9;
int p[100005];
void dfs(int have_get,vector<int>have_choose){
    if(have_get==will.size()){
        int len=have_choose.size();
        ans2=min(ans2,len);
        return;
    }
    for(int i:have_choose){
        if(i>=will[have_get].l&&i<=will[have_get].r){
            dfs(have_get+1,have_choose);
            return;
        }
    }
    for(int i:p){
        if(i>=will[have_get].l&&i<=will[have_get].r){
            have_choose.push_back(i);
            dfs(have_get+1,have_choose);
            have_choose.pop_back();
        }
    }
}
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cnt.clear();
        will.clear();
        vis.clear();
        ans=0,ans2=1e9;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            double d1,v1,a1;
            cin>>d1>>v1>>a1;
            cnt.push_back({d1,v1,a1});
        }
        for(int i=1;i<=m;i++)cin>>p[i];
        for(int i=0;i<n;i++){
            car x=cnt[i];
            if(x.a<=0&&x.v<=v){
                vis.push_back({-1,-1});
                continue;
            }
            if(x.a>=0&&x.v>v){
                vis.push_back({x.d,l});
                continue;
            }
            else{
                if(x.a>0){
                    vis.push_back({x.d+(v*v-x.v*x.v)/(2*x.a),l});
                    continue;
                }
                if(x.a<0){
                    vis.push_back({x.d,(v*v-x.v*x.v)/(2*x.a)+x.d});
                    continue;
                }
            }
        }
        for(int i=0;i<vis.size();i++){
            for(int j:p){
                if(j>=vis[i].l&&j<=vis[i].r){
                    ans++;
                    will.push_back(vis[i]);
                    break;
                }
            }
        }
        vector<int>have_choose;
        dfs(0,have_choose);
        cout<<ans<<' '<<m-ans2<<endl;
    }
}
