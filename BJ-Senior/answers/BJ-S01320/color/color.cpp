#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,a[100010];
ll ans;
void dfs(ll root,ll bl,ll wh,ll val){
    if(root==n+1){
        ans=max(ans,val);
        return;
    }
    if(a[bl]==a[root]){
        dfs(root+1,root,wh,val+a[root]);
    }else{
        dfs(root+1,root,wh,val);
    }
    if(a[wh]==a[root]){
        dfs(root+1,bl,root,val+a[root]);
    }else{
        dfs(root+1,bl,root,val);
    }
}
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(ll i=1;i<=n;i++)
            cin>>a[i];
        ans=0;
        dfs(1,0,0,0);
        cout<<ans<<endl;

    }
	return 0;
}
