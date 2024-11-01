#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int col[200005];
int a[200005];
int ans;
void dfs(int step){
    if(step>n){
        int res=0;
        for(int i=2;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(col[j]==col[i]){
                    if(a[i]==a[j]) res+=a[i];
                    break;
                }
            }
        }
        ans=max(ans,res);
        return;
    }
    col[step]=1;
    dfs(step+1);
    col[step]=0;
    dfs(step+1);
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dfs(1);
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
