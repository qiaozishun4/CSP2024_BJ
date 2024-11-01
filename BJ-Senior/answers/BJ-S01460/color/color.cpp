#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t,n,a[200005],c[200005];
long long sum,ans;
void dfs(int x){
    if(x==n+1){
        sum=0;
        for(int i=2;i<=n;i++){
            for(int j=i-1;j;j--){
                if(c[i]==c[j]){
                    if(a[i]==a[j]) sum+=a[i];
                    break;
                }
            }
        }
        ans=max(ans,sum);
        return;
    }
    c[x]=1;
    dfs(x+1);
    c[x]=2;
    dfs(x+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        ans=0;
        memset(c,0,sizeof(c));
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        dfs(1);
        printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
