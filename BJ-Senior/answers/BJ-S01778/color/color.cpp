#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005],b[10000005];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ll t,n,m,i,j,s,ans=0;
    cin>>t;
    while(t--)
    {
        memset(b,0,sizeof(b));
        s=0;
        m=0;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            b[a[i]]++;
            m=max(m,a[i]);
        }
        for(i=1;i<=m;i++)
        {
            if(b[i]>1)
            {
                s+=i*b[i]/2;
            }
        }
        cout<<s<<"\n";
    }
    return 0;
}
