#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, n, a[200005];
ll cnt[1000005];
bool used[200005];
ll ans = -1;
inline ll calc(vector<ll> A, vector<ll> B)
{
    ll ans = 0;
    for (int i = 1; i < A.size(); i++)
        if (A[i] == A[i - 1])
            ans += A[i];
    for (int i = 1; i < B.size(); i++)
        if (B[i] == B[i - 1])
            ans += B[i];
    return ans;
}
void dfs(int now)
{
    if (now == n + 1)
    {
        vector<ll> A, B;
        for (int i = 1; i <= n; i++)
        {
            if (used[i])
                A.push_back(a[i]);
            else
                B.push_back(a[i]);
        }
        ans = max(ans, calc(A, B));
        return ;
    }
    used[now] = 1;
    dfs(now + 1);
    used[now] = 0;
    dfs(now + 1);
}
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%lld", &T);
    while (T--)
    {
        memset(cnt, 0 ,sizeof(cnt));
        scanf("%lld", &n);
        bool bad = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            cnt[a[i]]++;
            if (cnt[a[i]] >= 2) bad = 1;
        }
        if (!bad)
        {
            printf("0\n");
            continue;
        }
        memset(used, 0, sizeof(used));
        ans = -1;
        dfs(1);
        printf("%lld\n", ans);
    }
    return 0;
}
