#include <bits/stdc++.h>

using namespace std;
const int N=1e6+5;
int a[N],h[N];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T,n,ans=0;
    cin>>T;
    while(T--)
    {
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            h[a[i]]++;
        }
        for(int i=1;i<=N;i++)
        {
            h[a[i]]/=2;
            ans+=h[a[i]]*a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
