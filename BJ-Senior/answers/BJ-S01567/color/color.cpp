#include<bits/stdc++.h>
using namespace std;
int t,n,a[200001],b[200001],maxn=-1;
void dfs(int x){
    if(x==n){
        int last_red=-1,last_blue=-1,sum=0;
        for(int i=1;i<=n;i++){
            if(b[i]==0){
                if(last_red==a[i]){
                    sum+=a[i];
                }
                last_red=a[i];
            }else{
                if(last_blue==a[i]){
                    sum+=a[i];
                }
                last_blue=a[i];
            }
        }
        maxn=max(maxn,sum);
        return;
    }
    b[x]=0;
    dfs(x+1);
    b[x]=1;
    dfs(x+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        maxn=-1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        dfs(1);
        printf("%d\n",maxn);
    }
    return 0;
}