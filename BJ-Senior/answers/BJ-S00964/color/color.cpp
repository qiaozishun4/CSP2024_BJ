
#include<bits/stdc++.h>
using namespace std;
int a[25];
int vis[25];
int ans=0;
int n;
void dfs(int x){
    if(x==n+1){
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(vis[i]==vis[j]){
                    if(a[i]==a[j])cnt+=a[i];
                    break;
                }
            }
        }
        if(cnt>ans)ans=cnt;
        return ;
    }
    vis[x]=1;
    dfs(x+1);
    vis[x]=2;
    dfs(x+1);

}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    int T;cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        memset(vis,0,sizeof(vis));
        ans=0;
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
