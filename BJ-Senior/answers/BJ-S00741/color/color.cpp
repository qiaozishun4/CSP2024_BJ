#include<bits/stdc++.h>
using namespace std;
int a[200010],h[1000010];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            mx=max(mx,a[i]);
            h[a[i]]++;
        }
        int ans=0;
        for(int i=1;i<=mx;i++)
            ans+=max(h[i]-1,0)*i;
        cout<<ans<<endl;
        memset(h,0,sizeof(h));
    }
    return 0;
}
