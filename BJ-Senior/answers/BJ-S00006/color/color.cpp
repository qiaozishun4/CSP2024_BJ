#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdlib>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
using namespace std;
int t;
int n;
int a[200005];
bool b[20];
int ans;
int solve(){
    int ret=0;
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            if(b[i]==b[j]){
                if(a[i]==a[j])ret+=a[i];
                break;
            }
        }
    }
    return ret;
}
void dfs(int x){
    if(x==n+1){
        ans=max(ans,solve());
        return;
    }
    b[x]=true;
    dfs(x+1);
    b[x]=false;
    dfs(x+1);
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        dfs(1);
        printf("%d\n",ans);
    }
    return 0;
}
