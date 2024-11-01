#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n;
ll ans,a[N];
void dfs(int pos,ll lastblue,ll lastred,ll sum){
    if(pos > n){
        ans  = max(ans , sum);
        return;
    }
    if(a[pos] == lastblue || a[pos] == lastred) dfs(pos+1,lastblue,lastred,sum+a[pos]);
    else{
        dfs(pos+1,a[pos],lastred,sum);
        dfs(pos+1,lastblue,a[pos],sum);
    }
    return;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T; scanf("%d",&T);
    while(T--){
        ans = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        dfs(1,0,0,0);
        printf("%lld\n",ans);
    }
    return 0;
}
