#include <bits/stdc++.h> //Never gonna give you up
#define int long long
using namespace std;
int n,r[100005],cnt;
signed main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>r[i];
    sort(r+1,r+n+1);
    for (int i=1;i<n;i++)
        if (r[i]==r[i+1]) cnt++;
    if (cnt==0) cout<<"1";
    return 0;
}
//If we can glow with our own sparkle.
