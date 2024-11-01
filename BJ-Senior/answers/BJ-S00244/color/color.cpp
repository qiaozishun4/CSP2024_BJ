#include <bits/stdc++.h>
using namespace std;
int t,n,a[200000],c[200000],ans;
void dfs(int x){
    if(x==n+1){
        int res=0;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(c[i]==c[j] && a[i]==a[j]){
                    res+=a[i];
                    break;
                }
            }
        }
        ans=max(ans,res);
        return;
    }
    c[x]=0;
    dfs(x+1);
    c[x]=1;
    dfs(x+1);
    return;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            c[i]=0;
        }
        ans=0;
        dfs(1);
        cout<<ans<<endl;
    }

    return 0;
}