#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int a[100005], box[100005], b[100005];
signed main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        box[a[i]]++;
    }
    sort(a + 1, a + n + 1);
    int cur = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != a[i + 1])
        {
            b[++cur] = a[i];
        }
    }
    int cnt = 0;
    for (int i = 1; i < cur; i++)
    {
        cnt += min(box[b[i]], box[b[i + 1]]);
    }
    cout << n - cnt;
    return 0;
}
