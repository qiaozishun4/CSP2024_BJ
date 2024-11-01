#include<bits/stdc++.h>
using namespace std;

long long dp[1000][1000],t,n,a[100000];

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dp[1][0]=a[1];
        dp[1][1]=a[1];
        for(int k=2;k<=n;k++){
            for(int i=0;i<=1;i++){
                dp[k][i]=max(dp[k-1][i],dp[k-1][(i+1)%2]+a[k-1]);
            }
        }
        cout<<max(dp[n][0],dp[n][1]);
    }
    return 0;
}
