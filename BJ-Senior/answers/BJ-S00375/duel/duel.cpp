#include<bits/stdc++.h>
using namespace std;
int zls[100005];
int maxn;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,t,ans;
    cin>>n;
    ans=n;
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        zls[t]++;
        maxn=max(maxn,zls[t]);
    }
    cout<<maxn;
    return 0;
}
