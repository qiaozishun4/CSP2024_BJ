#include<bits/stdc++.h>
using namespace std;
long long n,a[2000001],f[2000001],ans,T;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        cin>>n;
        ans=0;
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            f[a[i]]++;
        }
        for(int i=1;i<=1000;i++)
        {
            if(f[i]>=2) ans=ans+i*(f[i]-1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
