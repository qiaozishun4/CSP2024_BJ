#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[200010];
bool color[200010];     //0 is red,1 is blue
int ans;
void dfs(int cur){
    if(cur>n){
        int sum=0;
        int r=0,b=0;
        for(int i=1;i<=n;i++){
            if(color[i]){
                if(a[r]==a[i]) sum+=a[i];
                r=i;
            }
            else{
                if(a[b]==a[i]) sum+=a[i];
                b=i;
            }
        }
        ans=max(ans,sum);
        return;
    }
    color[cur]=false;
    dfs(cur+1);
    color[cur]=true;
    dfs(cur+1);
    return;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        dfs(1);
        cout<<ans;
    }
    return 0;
}
