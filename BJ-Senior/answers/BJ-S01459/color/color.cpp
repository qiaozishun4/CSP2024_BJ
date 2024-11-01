#include<iostream>
using namespace std;
const int Maxn=105;
int T,a[Maxn],n,dp[Maxn],c[Maxn],ans;
void dfs(int n){
    int cnt=0;
    if(!n)return ;
    c[n]=1;
    dfs(--n);
    c[n]=0;
    dfs(--n);
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            if(a[i]==a[j]&&c[i]==c[j]){
                cnt++;
                break;
            }if(c[i]==c[j])break;
        }
    }
    ans=max(ans,cnt);
}
void solve(){
    ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[i]=0;
    }
    dfs(n);
    cout<<ans<<endl;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
