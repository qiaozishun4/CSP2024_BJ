#include <bits/stdc++.h>
using namespace std;
const long long maxn=2e62-2;
const int cnts[10]={6,2,5,5,4,5,6,3,7,6};
long long t,n,dp[100002];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    memset(dp,maxn,sizeof(dp));
    dp[1]=-1;
    dp[2]=1;
    dp[3]=7;
    dp[4]=4;
    dp[5]=2;
    dp[6]=6;
    dp[7]=8;
    dp[8]=10;
    for(int i=9;i<=50;i++){
        for(int j=2;j<=7;j++){
            dp[i]=min(dp[i],dp[i-j]*10+dp[j]);
        }
    }
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=50){
            cout<<dp[n]<<endl;
        }
        else if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else if(n%7==1){
            n-=8;
            cout<<10;
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
        }
        else{
            cout<<"10000000000000000000000000000000000000"<<endl;
        }
    }
    return 0;
}
