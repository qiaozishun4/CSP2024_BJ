#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
typedef long long ll;
ll t,n,a[200005];
ll ans;
void dfs(int step,int r,int b,ll s){
    if(step>n){
        ans=max(ans,s);
        return ;
    }
    dfs(step+1,a[step],b,s+(a[step]==r?a[step]:0));
    dfs(step+1,r,a[step],s+(a[step]==b?a[step]:0));
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        dfs(1,0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
