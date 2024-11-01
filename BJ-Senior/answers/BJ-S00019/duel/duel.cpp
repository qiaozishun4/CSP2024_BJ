#include <bits/stdc++.h>
using namespace std;
int n,dp[100000];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    dp[0]=n;
    for(int i=1;i<=n;i++){
        scanf("%d",&dp[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=dp[i];j<=n;j++){
            dp[j]=min(dp[j],dp[j-dp[i]]);
        }
    }
    printf("%d",&dp[n]);
    return 0;
}