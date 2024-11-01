#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
int a[200005], nxt[200005];
ll f[200005];
int lst[1000005];
void chk(ll &a, ll b) { a = max(a, b); }
void solve()
{
    memset(f, 0, sizeof(f));
    int n;
    cin >> n;
    ll tot = 0;
    a[0] = -1;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i], lst[a[i]] = n+1;
        if(a[i] == a[i-1]) tot += a[--i], n--;
    }
    for(int i = n; i >= 1; i--)
    {
        nxt[i] = lst[a[i]];
        lst[a[i]] = i;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans = max(ans, f[i]);
        chk(f[i+1], f[i]);
        if(nxt[i] <= n) chk(f[nxt[i]-1], f[i]+a[i]);
    }
    cout << ans+tot << endl;
}
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}