/*0 1 2  3 4  5 6 7 8  9
  6 2 5 -1 4 -1 6 3 7 -1*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
int n,m;
int dp[N];
int a[10]{6,2,5,-1,4,-1,6,3,7,-1};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.ans","w",stdout);
    cin>>n;
    while(n--){
        memset(dp,0x3f,sizeof(dp));
        dp[0]=0;dp[1]=0;dp[2]=1;dp[3]=7;dp[4]=4;dp[5]=2;dp[6]=6;dp[7]=8;
        scanf("%d",&m);
        if(m==1) {
            printf("-1\n");
            continue;
        }
        else{
            for(int j=2;j<=m;j++){
                for(int i=0;i<=9;i++){
                    if(dp[j]==0&&i==0) continue;
                    if(a[i]>=0&&j>7) dp[j]=min(dp[j],(dp[j-a[i]]*10+i));
                    //cout<<i<<" "<<dp[j]<<" ";
                }
                //cout<<"\n";
            }
        }
        printf("%ld\n",dp[m]);
    }
    return 0;
}
