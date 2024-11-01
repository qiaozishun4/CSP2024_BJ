#include<bits/stdc++.h>
using namespace std;
int cnt[100005],r;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,rmax=0;cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>r;
        rmax=max(rmax,r);
        cnt[r]++;
    }
    int ans=0;
    for(int i=0;i<=rmax;i++)
    {
        ans=max(ans,cnt[i]);
    }
    cout<<ans;
    return 0;
}