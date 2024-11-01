#include <bits/stdc++.h>
using namespace std;

int t, n, a[200005], ans;
bool have[200005], as[200005], flag[200005], flag2[200005];

int ffind(int p, int k) {
    for (int i = p;i >= 1;i--)
        if (a[i] == k)
            return i;
}
void dfs(int cnt) {
    if (cnt > n) {
        int as = 0;
        for (int i = 2;i <= n;i++) {
            int j = i - 1;
            for (;j >= 1;j--)
                if (flag2[j] == flag2[i])
                    break;
            as += a[i] * (a[j] == a[i] and flag2[j] == flag2[i]);
        }
        ans = max(ans, as);
        return;
    }
    flag2[cnt] = 1;
    dfs(cnt + 1);
    flag2[cnt] = 0;
    dfs(cnt + 1);
}




int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n;
        for (int i = 1;i <= n;i++)
            cin >> a[i];

        if (n <= 20) {
            ans = 0;
            dfs(1);
            cout << ans << '\n';
            continue;
        }

        for (int i = 1;i <= n;i++) {
            if (have[a[i]]) {
                int t = ffind(i - 1, a[i]);
                bool f0 = 1, f1 = 1;
                for (int j = i - 1;j > t;j--) {
                    if (as[j] == 0)f1 = 0;
                    if (as[j] == 1)f0 = 0;
                }
                if (f0) {
                    as[i] = as[t] = 1;
                    flag[i] = flag[t] = 1;
                } else if (f1) {
                    as[i] = as[t] = 0;
                    flag[i] = flag[t] = 1;
                } else {
                    int p = 0;
                    for (int j = i - 1;j > t;j--) {
                        if (flag[j]) {
                            p = flag[j];
                            break;
                        }
                    }
                    as[i] = as[t] = (1 ^ p);
                }
            }
            have[a[i]] = 1;
        }
        memset(have, 0, sizeof(have));
        for (int i = 1;i <= n;i++) {
            if (have[a[i]]) {
                int t = ffind(i - 1, a[i]);
                if (as[t] == as[i])
                    ans += a[i];
            }
            have[a[i]] = 1;
        }
        cout << ans << '\n';
    }
    return 0;
}






















