#include <bits/stdc++.h>
using namespace std;
int n,t,a[200005],now,ans;
void dfs(int k,int r,int b,int h){
    if(k==n+1){
        ans=max(ans,h);
        return;
    }
    dfs(k+1,a[k],b,h+((a[k]==r)?r:0));
    dfs(k+1,r,a[k],h+((a[k]==b)?b:0));
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dfs(1,-1,-1,0);
        cout<<ans<<endl;
    }
    return 0;
}
