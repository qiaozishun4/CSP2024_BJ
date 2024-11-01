#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
bool vis[100005];
int ans;
int get(){
    int t=0,f=0,s=0;
    for(int i=1;i<=n;i++){
        if(vis[i]){
            if(t!=0&&a[t]==a[i]){
                s+=a[i];
            }
            t=i;
        }
        else{
            if(f!=0&&a[f]==a[i]){
                s+=a[i];
            }
            f=i;
        }
    }
    return s;
}
void dfs(int x){
    if(x>n){
        ans=max(get(),ans);
        return;
    }
    vis[x]=true;
    dfs(x+1);
    vis[x]=false;
    dfs(x+1);
}
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    ans=0;
    memset(vis,0,sizeof(vis));
    dfs(1);
    cout<<ans<<endl;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}