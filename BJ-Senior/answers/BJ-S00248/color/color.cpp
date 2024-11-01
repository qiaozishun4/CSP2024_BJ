#include<bits/stdc++.h>
using namespace std;
int n,a[100100],t,ans;
bool f[100100];
void dfs(int x){
    if(x>n){
        int r=0,b=0,ans1=0;
        for(int i=1;i<=n;i++){
            if(f[i]==0){
                if(a[r]==a[i])ans1+=a[i];
                r=i;
            }else{
                if(a[b]==a[i])ans1+=a[i];
                b=i;
            }
        }
        ans=max(ans,ans1);
        return;
    }
    f[x]=1;
    dfs(x+1);
    f[x]=0;
    dfs(x+1);
}
int main(){
   freopen("color.in","r",stdin);
   freopen("color.out","w",stdout);
    cin>>t;
    a[0]=-1;
    while(t--){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
