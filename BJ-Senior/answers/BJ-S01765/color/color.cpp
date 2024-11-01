#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define MAXN 200005

typedef long long ll;
ll n, T, ans;
ll a[MAXN], a1[MAXN];

ll chk(ll p[])
{
    ll sum = 0;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = i - 1; j >= 1; j --)
            if(p[j] == p[i])
            {
                if(a[i] == a[j])
                    sum += a[j];
                break;
            }
    }

    return sum;
}

void dfs(int t, ll p[])
{
    if(t == n + 1)
    {
        ans = max(ans, chk(p));
        return;
    }

    p[t] = 0;
    dfs(t + 1, p);
    p[t] = 1;
    dfs(t + 1, p);
}

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)  cin >> a[i];
    dfs(1, a1);
    cout << ans << endl;

    memset(a1, 0, sizeof(a1));
    ans = 0;
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    cin >> T;

    for(int i = 1; i <= T; i ++)
        solve();
    return 0;
}
