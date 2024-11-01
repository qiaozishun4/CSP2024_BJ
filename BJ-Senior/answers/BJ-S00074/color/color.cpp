#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
int t,n,a[maxn],f[maxn];
long long ans=0;

void dfs(int k){
    if(k==n+1){
        int x=0,y=0;
        long long sum=0;
        for(int i=1;i<=n;i++){
            if(f[i]==0){
                if(x && a[x]==a[i]) sum+=a[i];
                x=i;
            }
            else{
                if(y && a[y]==a[i]) sum+=a[i];
                y=i;
            }
        }
        ans=max(ans,sum);
        return;
    }
    f[k]=0;
    dfs(k+1);
    f[k]=1;
    dfs(k+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        ans=0;
        dfs(1);
        printf("%lld\n",ans);
    }
    return 0;
}