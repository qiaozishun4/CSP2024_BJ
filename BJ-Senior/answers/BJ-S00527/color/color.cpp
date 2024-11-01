#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int T,n,ans,a[N],col[N];
void dfs(int dep){
    if(dep==n+1){
        int o=0,l=0;
        for(o=1;o<=n;o++){
            if(!col[o]) break;
        }
        for(l=1;l<=n;l++){
            if(col[l]) break;
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(i==o && !col[i]) continue;
            if(i==l && col[i]) continue;
            if(col[i]) cnt+=(a[i]==a[l])*a[i],l=i;
            else cnt+=(a[i]==a[o])*a[i],o=i;
        }
        ans=max(ans,cnt);
        return;
    }
    col[dep]=0;
    dfs(dep+1);
    col[dep]=1;
    dfs(dep+1);
    return;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        ans=0,dfs(1);
        printf("%d\n",ans);
    }
    return 0;
}
