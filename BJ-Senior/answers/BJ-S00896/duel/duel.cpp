#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int cnt[100005],a[100005];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i=0;i<100005;i++)
    {
        ans=max(ans,cnt[i]);
    }
    cout<<ans<<endl;
    return 0;
}
