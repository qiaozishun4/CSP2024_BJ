#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, a[100010], f[100010], ans;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for (ll i=1; i<=n; ++i)
    {
        cin >> a[i];
        f[i]=1;
    }
    sort(a+1,a+n+1);
    for (ll i=1; i<n; ++i)
    {
        if(a[i]==a[i+1])
        {
            f[i+1]=f[i]+1;
        }
    }
    for (ll i=1; i<=n; ++i)
    {
        ans=max(ans,f[i]);
    }
    cout << ans;
    return 0;
}
