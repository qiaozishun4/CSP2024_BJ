#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005];
int tmp[100005],ans;
void dfs(int step){
    if(step==n+1){
        int cnt=0;
        for(int i=2;i<=n;i++){
            if(tmp[i]==tmp[i-1])continue;
            for(int j=i-1;j>=1;j--){
                if(tmp[i]==tmp[j]){
                    if(a[i]==a[j])cnt+=a[i];
                    break;
                }
            }
        }
        ans=max(ans,cnt);
        return ;
    }
    tmp[step]=1;
    dfs(step+1);
    tmp[step]=0;
    dfs(step+1);
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
