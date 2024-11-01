#include<bits/stdc++.h>
using namespace std;
int t,n,a[1005],c[1005],hl[1005],dp[1005][1005],hh=0;
int main(){
    freopen("color.in","r","stdin");
    freopen("color.iout","w","stdout");
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>a[i];
            hh=a[j];
        }
        for(int j=1;j<=n;j++){
            for(int x=1;x<=a[j];j++){
                dp[j][x]=max(dp[j-1][x],dp[j-1][x+a[x]]);
            }
        }
        cout<<dp[n][hh];
    }
    return 0;
}
