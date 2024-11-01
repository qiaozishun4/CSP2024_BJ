#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10, M = 1e6 + 10;
int c[N], a[N], lst[M], b[2], r[2], T, n;
set<int>s;
ll ans;
inline void dfs(int cur)
{
    if(cur == n + 1)
    {
        ll cnt = 0;
        int rl = 0, bl = 0;
        for(int i = 1;i <= n;++i)
        {
            if(c[i] == 0 && a[bl] == a[i])
                cnt += a[i];
            else if(c[i] == 1 && a[rl] == a[i])
                cnt += a[i];
            if(c[i] == 0)
                bl = i;
            else
                rl = i;
        }
        ans = max(ans, cnt);
        return;
    }
    for(int i = 0;i <= 1;++i)
    {
        c[cur] = i;
        dfs(cur + 1);
    }
}
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> T;
    a[0] = -1e9;
    while(T--)
    {
        s.clear();
        cin >> n;
        ans = 0;
        for(int i = 1;i <= n;++i)
        {
            scanf("%d", &a[i]);
            if(s.count(a[i]))
                ans += a[i];
            s.insert(a[i]);
        }
        if(s.size() == n)
        {
            cout << "0\n";
        }
        else if(n > 30)
            cout << ans << "\n";
        else
        {
            ans = 0;
            dfs(1);
            cout << ans << "\n";
        }
    }
    return 0;
}
