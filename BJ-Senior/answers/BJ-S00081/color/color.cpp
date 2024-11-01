#include <iostream>
using namespace std;
typedef long long ll;
const int N=200005;
int T, n, a[N], c[N], ans=0;
int check(){
    int res=0;
    for(int i=1;i<=n;i++)
        for(int j=i-1;j>=1;j--)
            if(c[i]==c[j]){
                if(a[i]==a[j]) res+=a[j];
                break;
            }
    return res;
}
void dfs(int p){
    if(p==n+1){
        ans=max(ans,check());
        return;
    }
    c[p]=-1;
    dfs(p+1);
    c[p]=1;
    dfs(p+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        ans=0;
        dfs(1);
        printf("%d\n",ans);
    }
    return 0;
}