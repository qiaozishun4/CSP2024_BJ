#include <bits/stdc++.h>
using namespace std;
int a[100005];
bool flag[100005];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[j] > a[i] && flag[j] != 1)
            {
                flag[j] = 1;
                break;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (flag[i] != 1) ans++;
    }
    cout << ans << endl;
    return 0;
}
