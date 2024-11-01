#include <bits/stdc++.h>
using namespace std;
int n,a[100010];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    int maxx=0,minn=1000000,ans,x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a[x]++;
        maxx=max(maxx,x);
        minn=min(minn,x);
    }
    ans=a[maxx];
    for(int i=maxx-1;i>=minn;i--)
    {
        if(a[i]!=0)
            if(a[maxx]<a[i])
                ans+=a[i]-ans;
    }
    cout<<ans;
    return 0;
}
