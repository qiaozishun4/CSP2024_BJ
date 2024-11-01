#include<bits/stdc++.h>
using namespace std;
int t,n,a[114],x[114],ans;
void dfs(int k){
    if(k==n+1){
        int cnt=0;
        for(int i=1;i<=n;i++)for(int j=i-1;j>0;j--)if(x[i]==x[j]){if(a[i]==a[j])cnt+=a[i];break;}
        ans=max(ans,cnt);
        return;
    }
    for(int i=0;i<2;i++)x[k]=i,dfs(k+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0,memset(x,0,sizeof(x));
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        dfs(1);
        cout<<ans<<'\n';
    }
    return 0;
}