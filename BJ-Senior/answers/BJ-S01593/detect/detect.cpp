#include<bits/stdc++.h>
using namespace std;
int t,n,m,L,V,d[100005],v[100005],a[100005],p[100005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> t;
    for (int i = 1;i <= t;i++)
    {
        int maxx = 0,ans = 0;
        cin >> n >> m >> L >> V;
        for (int j = 1;j <= n;j++)
        {
            cin >> d[i] >> v[i] >> a[i];
        }
        for (int j = 1;j <= m;j++)
        {
            cin >> p[i];
            maxx = max(maxx,p[i]);
        }
        for (int i = 1;i <= n;i++)
        {
            if (d[i] < maxx && v[i] > V)
            {
                ans++;
            }
        }
        cout << ans << ' ' << m - 1 << endl;
    }
    return 0;
}