#include <bits/stdc++.h>
using namespace std;
const int N=200000+10;
int t,n,col[N];
long long a[N],ans;
void dfs(int dep){
    if(dep>n){
        long long sum=0;
        for(int i=2;i<=n;i++){
            long long cnt=0;
            for(int j=i-1;j>=1;j--)
                if(col[j]==col[i] && a[i]==a[j]){
                    cnt=a[i];break;
                }
            sum+=cnt;
        }
        ans=max(ans,sum);
        return ;
    }
    col[dep]=1;
    dfs(dep+1);
    col[dep]=0;
    dfs(dep+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        ans=0;
        dfs(1);
        printf("%lld\n",ans);
    }
    return 0;
}
