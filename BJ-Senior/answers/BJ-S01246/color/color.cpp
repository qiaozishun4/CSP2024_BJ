#include<bits/stdc++.h>
using namespace std;
int n,a[200010],t,ans;
int vis[200010];
int getsum(){
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            if(vis[i]==vis[j]){
                if(a[i]==a[j]){
                    ans+=a[i];
                }
                break;
            }
        }
    }
    return ans;
}
int dfs(int x){
    if(x==n){
        ans=max(ans,getsum());
        return 0;
    }
    vis[x+1]=1;
    dfs(x+1);
    vis[x+1]=0;
    dfs(x+1);

    return 0;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            vis[i]=-1;
            cin>>a[i];
        }
        dfs(0);
        cout<<ans<<'\n';
    }

    return 0;
}
