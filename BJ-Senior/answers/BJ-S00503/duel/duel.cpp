#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    vector<int> dp(n+1,1),a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(a[j]>a[i]) dp[i]=max(dp[i],dp[j]+1);
        }
    }
    cout<<n-(*max_element(dp.begin(),dp.end()));
    return 0;
}