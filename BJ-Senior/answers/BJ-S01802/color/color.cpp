#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int t;
ll n, a[200010], b[1000010], ans, maxx;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin >> t;
    for (int q=1; q<=t; ++q)
    {
        ans=0;
        for (int i=1; i<=1000010; ++i)
            b[i]=0;
        cin >> n;
        for (ll i=1; i<=n; ++i)
        {
            cin >> a[i];
        }
        sort(a+1,a+n+1);
        for (ll i=1; i<=n; ++i)
        {
            b[a[i]]++;
            maxx=max(maxx,a[i]);
        }
        for (ll i=1; i<=maxx; ++i)
        {
            if(b[i]>=2)
            {
                ans+=b[i]/2*i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
