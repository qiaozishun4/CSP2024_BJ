#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll T,n,a[200005],b[200005],maxn=-1,minn=1e8,ans=0;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--)
    {
        ans=0;
        memset(b,0,sizeof(b));
        cin>>n;
        for(ll i=1;i<=n;i++)
        {
            cin>>a[i];
            b[a[i]]++;
            maxn=max(maxn,a[i]);
            minn=min(minn,a[i]);
        }
        for(ll i=maxn;i>=minn;i--)
        {
            if(b[i]>=2)
            {
                ans+=i*(b[i]-1);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
