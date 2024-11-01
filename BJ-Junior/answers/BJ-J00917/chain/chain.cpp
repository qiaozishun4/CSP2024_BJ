#include<iostream>
using namespace std;
int t,n,k,q,l[200010],r,c,s[200010],sum[200010],flag;
void dfs(int now,int p){
    if(flag)return ;
    if(now==r&&p==c){
        flag=1;
        return ;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=l[i];j++){
            if(s[sum[i-1]+i]=='p'){
                for(int o=sum[i-1]+j;j<=min(sum[i-1]+j+k,sum[i]);j++){
                    dfs(now+1,s[o]);
                }
            }
        }
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&k,&q);
        for(int i=1;i<=n;i++){
            scanf("%d",&l[i]);
            sum[i]=sum[i-1]+l[i];
            for(int j=1;j<=l[i];j++)scanf("%d",&s[sum[i-1]+i]);
        }
        while(q--){
            scanf("%d%d",&r,&c);
            flag=0;
            dfs(1,1);
            printf("%d\n",flag==1?1:0);
        }
    }
    return 0;
}
