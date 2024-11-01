#include <bits/stdc++.h>
using namespace std;
bool ist[100005], b[100005];
int r[100005];

int main () {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n, ans = 0;
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> r[i];
    }
    sort(r + 1, r + n + 1);
    for (int i = 1;i <= n;i++)
    {
        if (!ist[i])
        {
            for (int j = i - 1;j >= 1;j--)
            {
                if (r[j] < r[i] && !ist[j])
                {
                    ist[j] = true;
                    break;
                }
            }
        }
    }
    for (int i = 1;i <= n;i++)
    {
        if (!ist[i])
        {
            ans++;
            b[r[i]] = true;
        }
    }
    cout << ans;
    return 0;
}