#include<bits/stdc++.h>
using namespace std;
int t,n,a[20],dp[105][105][105];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<=20;++i) a[i]=0;
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                dp[n][i][j]=0;
            }
        }
        for(int i=n;i>=1;--i){
            for(int j=1;j<i;++j){
                for(int k=1;k<i;++k){
                    dp[i][j][k]=max(dp[i+1][i][k]+max(a[i+1]==a[i]?a[i]:0,a[i+1]==a[k]?a[k]:0),dp[i+1][j][i]+max(a[i+1]==a[i]?a[i]:0,a[i+1]==a[j]?a[j]:0));
                }
            }
        }
        cout<<dp[2][1][1]<<endl;
    }
}
