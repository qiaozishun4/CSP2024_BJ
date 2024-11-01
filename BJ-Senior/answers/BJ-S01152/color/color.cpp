#include <bits/stdc++.h>
using namespace std;
int a[20];
int n;
int ans;
void dfs(int s,int t0,int t1,int x){
    if(x>n){
        ans=max(ans,s);
        return;
    }
    if(a[x]==t0){
        dfs(s+t0,a[x],t1,x+1);
        dfs(s,t0,a[x],x+1);
    }
    if(a[x]==t1){
        dfs(s+t1,t0,a[x],x+1);
        dfs(s,a[x],t1,x+1);
    }
    if(a[x]!=t0 && a[x]!=t1){
        dfs(s,a[x],t1,x+1);
        dfs(s,t0,a[x],x+1);
    }
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ans=0;
        dfs(0,-1,-1,0);
        cout<<ans<<endl;
    }
    return 0;
}
