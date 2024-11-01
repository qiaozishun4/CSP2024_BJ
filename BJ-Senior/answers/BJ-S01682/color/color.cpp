#include<bits/stdc++.h>
using namespace std;
int t,n,s[200001],ans;
void dfs(int now,int score,int lred,int lblue){
    if(now>n){
        ans=max(ans,score);
        return;
    }
    dfs(now+1,score+((s[lred]==s[now])?s[now]:0),now,lblue);
    dfs(now+1,score+((s[lblue]==s[now])?s[now]:0),lred,now);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&s[i]);
        }
        dfs(1,0,0,0);
        printf("%d\n",ans);
    }
    return 0;
}
