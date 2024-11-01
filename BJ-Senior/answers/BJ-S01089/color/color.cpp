#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll a[N],n,vis[N];
ll ans;
void dfs(int u){
    if(u>n){
        ll res=0;
        for(int i=1;i<=n;++i){
            for(int j=i-1;j>=1;--j){
                if(vis[i]==vis[j]){
                    if(a[i]==a[j]) res+=a[i];
                    break;
                }
            }
        }
        ans=max(ans,res);
        return ;
    }
    vis[u]=0;
    dfs(u+1);
    vis[u]=1;
    dfs(u+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
