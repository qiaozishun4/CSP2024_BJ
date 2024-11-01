#include <bits/stdc++.h>
using namespace std;
int t,n,m,l,V,d[100001],v[100001],a[100001],p[100001],ans;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while (t--)
    {
        ans=0;
        cin>>n>>m>>l>>V;
        for (int i=1;i<=n;i++)
            cin>>d[i]>>v[i]>>a[i];
        for (int i=1;i<=m;i++)
            cin>>p[i];
        for (int i=1;i<=n;i++)
            if (d[i]<=p[m] && v[i]>V)
                ans++;
        cout<<ans<<' ';
        if (ans)
            cout<<m-1<<endl;
        else
            cout<<m<<endl;
    }
}