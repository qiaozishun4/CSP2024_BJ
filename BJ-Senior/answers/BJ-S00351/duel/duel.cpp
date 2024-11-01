#include<bits/stdc++.h>
using namespace std;
int r[100005],dp[100005],t[100005],ms[1000005],n;
long long ans;
stack<int> f;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    int k=1;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
        t[r[i]]++;
    }
    sort(r+1,r+n+1);
    dp[1]=t[r[1]];
    for(int i=2;i<=n;i++)
    {
        dp[i]=max(dp[i-1],t[r[i]]);
    }
    cout<<dp[n];
    return 0;
}
