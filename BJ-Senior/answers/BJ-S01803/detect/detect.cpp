#include <bits/stdc++.h>
#define int long long
using namespace std;
int T,n,m,L,V,cnt,d[1000001],v[1001],a[1001],p[1000001];
signed main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while (T--)
    {
        cin>>n>>m>>L>>V;
        for (int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
        for (int i=1;i<=m;i++) cin>>p[i];
        for (int i=1;i<=n;i++)
        {
            int lgth=L=d[i];
            if (v[i]>V) cnt++;
        }
        cout<<cnt<<" "<<m-1<<"\n";
    }
    return 0;
}
//Long live OI
