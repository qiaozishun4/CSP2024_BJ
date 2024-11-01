#include<bits/stdc++.h>
using namespace std;
int t,n;
unsigned long long dp[50];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    for(int i=1;i<=50;i++){
        dp[i]=1e19;
    }
    dp[2]=1,dp[3]=7,dp[4]=4,dp[5]=2,dp[6]=6,dp[7]=8;
    for(int i=8;i<=50;i++){
        dp[i]=min(dp[i],dp[i-6]*10);
        dp[i]=min(dp[i],dp[i-2]*10+1);
        dp[i]=min(dp[i],dp[i-5]*10+2);
        dp[i]=min(dp[i],dp[i-5]*10+3);
        dp[i]=min(dp[i],dp[i-4]*10+4);
        dp[i]=min(dp[i],dp[i-5]*10+5);
        dp[i]=min(dp[i],dp[i-6]*10+6);
        dp[i]=min(dp[i],dp[i-3]*10+7);
        dp[i]=min(dp[i],dp[i-7]*10+8);
        dp[i]=min(dp[i],dp[i-6]*10+9);
    }
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=50){
            if(dp[n]!=1e19){
                cout<<dp[n];
            }else{
                cout<<-1;
            }
        }else{
            if(n%7==0){
                for(int i=1;i<=n/7;i++){
                    cout<<'8';
                }
            }else{
                cout<<'1'<<'0';
                for(int i=1;i<n/7;i++){
                    cout<<'8';
                }
            }
        }
        cout<<'\n';
    }
    return 0;
}
