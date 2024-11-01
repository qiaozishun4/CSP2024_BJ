#include <bits/stdc++.h>
using namespace std;
vector <int> v;
vector <int> dp;
int ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    v.resize(n+1,0);
    dp.resize(n+1,0);
    for (int i=1;i<=n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int idx=1;
    for (int i=1;i<=n;i++){
        if (v[i]==v[idx]){
            dp[i]=dp[i-1];
        }
        else if (v[i]>v[idx]){
            dp[i]=dp[i-1]+1;
            idx++;
        }
    }
    int maxn=INT_MIN;
    for (int i=1;i<=n;i++){
        maxn=max(dp[i],maxn);
    }
    cout<<n-maxn;
    return 0;
}
