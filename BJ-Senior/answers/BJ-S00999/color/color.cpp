#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n;
vector<bool> ve;
ll ans=-1;
ll a[200005];
void dfs(ll now){
    // cout<<now<<'\n';
    // for(auto i:ve)
    //     cout<<i;
    // cout<<'\n';
    if(now==n+1){
        ll lab=0,lar=0;
        ll cnt=0;
        ll w=1;
        for(auto i:ve){
            if(i){
                if(a[lab]==a[w])
                    cnt+=a[w];
                lab=w;
            }
            else{
                if(a[lar]==a[w])
                    cnt+=a[w];
                lar=w;
            }
            w++;
        }
        ans=max(ans,cnt);
        return;
    }
    ve.push_back(1);
    dfs(now+1);
    ve.pop_back();
    ve.push_back(0);
    dfs(now+1);
    ve.pop_back();
    return;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        ans=-1;
        ve.clear();
        for(ll i=1;i<=n;i++)
            cin>>a[i];
        dfs(1);
        cout<<ans<<'\n';
    }
    return 0;
}