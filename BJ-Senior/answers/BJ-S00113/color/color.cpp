#include<bits/stdc++.h>
using namespace std;
int t,n,a[200002],v,w;
int vis[200002],cnt,ans;
void dfs(int x){
    if(x>n){
        cnt=max(cnt,ans);
        return ;
    }
    int y=ans,z=v;
    vis[x]=1;
    if(a[v]==a[x]) ans+=a[x];
    v=x;
    dfs(x+1);
    v=z,ans=y;
    z=w;
    vis[x]=0;
    if(a[w]==a[x]) ans+=a[x];
    w=x;
    dfs(x+1);
    w=z,ans=y;
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
        cnt=0;
        dfs(1);
        cout<<cnt<<endl;
    }
    return 0;
}
