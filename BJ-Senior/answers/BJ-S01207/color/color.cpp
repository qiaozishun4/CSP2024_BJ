#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],vis[N],n,ans=0;
void dfs(int x){
    if(x==n+1){
        int sum=0,l=-1;
        for(int i=n;i>=1;i--){
            if(vis[i]==2)continue;
            if(a[i]==l)sum+=l;
            l=a[i];
        }
        l=-1;
        for(int i=n;i>=1;i--){
            if(vis[i]==1)continue;
            if(a[i]==l)sum+=l;
            l=a[i];
        }
        ans=max(ans,sum);
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
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        memset(vis,0,sizeof(vis));
        ans=0;
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
