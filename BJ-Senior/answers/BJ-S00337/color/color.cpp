#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+10;
int t,n,a[N],b[N],ans;
void check(){
    int tmp0=0,sum=0,tmp1=0;
    for(int i = 1;i <= n;i++){
        if(b[i]==1&&a[tmp1]==a[i]) sum+=a[i];
        if(b[i]==0&&a[tmp0]==a[i]) sum+=a[i];
        if(b[i]==1) tmp1=i;
        if(b[i]==0) tmp0=i;
    }
    //cout<<sum<<endl;
    ans=max(ans,sum);
}
void dfs(int k){
    b[k]=0;
    if(k==n) check();
    else dfs(k+1);
    b[k]=1;
    if(k==n) check();
    else dfs(k+1);
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
        ans=0;
        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
