#include<iostream>
#include<cstdio>
using namespace std;
int T;
int n,a[200010];
long long ans=0;
int c[200010];
long long check(){
    long long cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            if(c[i]==c[j]){
                if(a[i]==a[j]){
                    cnt+=a[i];
                    break;
                }else{
                    break;
                }
            }
        }
    }

    return cnt;

}
void dfs(int x){
    if(x>=n+1){
        ans=max(ans,check());
        return;
    }
    c[x]=1;
    dfs(x+1);
    c[x]=2;
    dfs(x+1);
    c[x]=0;

}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        dfs(1);
        printf("%lld\n",ans);
    }

    return 0;
}
