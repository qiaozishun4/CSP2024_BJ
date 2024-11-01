#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int maxn=100+10;
int t,n,ans;
int a[maxn],c[maxn];
inline void ipt(){
    ans=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
}
inline void dfs(int u){
    if(u==n+1){
        int ret=0;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(c[i]==c[j]){
                    if(a[i]==a[j])ret+=a[i];
                    break;
                }
            }
        }
        ans=max(ans,ret);
        return ;
    }
    for(int i=0;i<=1;i++){
        c[u]=i;
        dfs(u+1);
    }
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        ipt();
        dfs(1);
        printf("%lld\n",ans);
    }

    return 0;
}