#include<bits/stdc++.h>
using namespace std;
int T,n,a[2000005],b[2000005],ans;
void dfs(int x){
    if(x==n){
        int pts=0;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(b[i]==b[j] && a[i]==a[j]){
                    pts+=a[i];
                    break;
                }
            }
        }
        ans=max(ans,pts);
        return;
    }
    b[x]=0;
    dfs(x+1);
    b[x]=1;
    dfs(x+1);
    return;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
