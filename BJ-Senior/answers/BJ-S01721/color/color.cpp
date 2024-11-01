#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,ans;
int a[200010];
bool vis[200010];
void dfs(int pos){
    if (pos==n+1){
        int r=0,b=0,sum=0;
        for (int i=1;i<=n;i++){
            if (vis[i]){
                if (a[i]==a[r]){
                    sum+=a[i];
                }
                r=i;
            }
            else {
                if (a[i]==a[b]){
                    sum+=a[i];
                }
                b=i;
            }
        }
        ans=max(ans,sum);
        return;
    }
    vis[pos]=false;
    dfs(pos+1);
    vis[pos]=true;
    dfs(pos+1);
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%lld",&t);
    while (t--){
        ans=0;
        scanf("%lld",&n);
        for (int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        dfs(1);
        printf("%lld\n",ans);
    }
    return 0;
}
