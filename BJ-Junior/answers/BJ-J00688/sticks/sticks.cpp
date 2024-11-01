#include<bits/stdc++.h>
using namespace std;
int t;
int n;
long long dp[100005];
int maxx=8;
int num[10]={6,2,5,5,4,5,6,3,7,6};
void ddpp(int n){
    for(int i=maxx+1;i<=n;i++){
        dp[i]=dp[i-num[0]]*10;
        for(int j=1;j<=10;j++){
            dp[i]=min(dp[i],dp[i-num[j]]*10+j);
        }
    }
    return;
}
int main(){
     freopen("sticks.in","r",stdin);
     freopen("sticks.out","w",stdout);
     scanf("%d",&t);
     dp[0]=-1;
     dp[1]=-1;
     dp[2]=1;
     dp[3]=7;
     dp[4]=4;
     dp[5]=2;
     dp[6]=6;
     dp[7]=8;
     dp[8]=10;
    for(int i=1;i<=t;i++){
        scanf("%d",&n);
        if(n%7==0){
            for(int j=1;j<=n/7;j++){
                printf("8");
            }
            printf("\n");
            continue;
        }
        if((n-1)%7==0){
            printf("10");
            for(int j=1;j<(n-1)/7;j++){
                printf("8");
            }
            printf("\n");
            continue;
        }
        if(n<=maxx){
            printf("%d\n",dp[n]);
            continue;
        }
        ddpp(n);
        printf("%d\n",dp[n]);
        maxx=max(maxx,n);
     }
    return 0;
}
