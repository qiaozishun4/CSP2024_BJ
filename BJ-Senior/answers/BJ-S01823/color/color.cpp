#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (auto i=(a); i <= (b); i++)
typedef long long  ll;
#define N int(2e5+10)
#define D int(1e6+10)
ll n, a[N], mx[D];
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int N_;
    cin>>N_;
    while (N_--) 
    {
        cin>>n;
        rep (i, 1, n) cin>>a[i], mx[a[i]]=-1;
        ll ans=0, tag=0;
        rep (i, 1, n)
        {
            if (a[i]==a[i-1]) tag+=a[i];
            if (mx[a[i]]!=-1&&a[i]!=a[i-1]) ans=max(ans, mx[a[i]]+a[i]);
            mx[a[i-1]]=max(mx[a[i-1]], ans);
        }
        cout<<ans+tag<<'\n';
    }
    return 0;
} // 感觉这是我见过的最短T3