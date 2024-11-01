#include<iostream>
#include<cmath>
using namespace std;
int t,n,a[1001],ans;
int vis[1001];
void dfs(int x){
    if(x==n+1){
        int cnt=0;
        for(int i=2;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(vis[i]==vis[j]){
                    if(a[i]==a[j]){
                        cnt+=a[i];
                    }
                    break;
                }
            }
        }
        ans=max(ans,cnt);
        return;
    }
    vis[x]=2;
    dfs(x+1);
    vis[x]=1;
    dfs(x+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ans=0;
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
