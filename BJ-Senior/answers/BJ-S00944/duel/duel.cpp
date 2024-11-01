#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int r[100010];
bool flag[100010];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
        flag[i] = 1;
    }
    sort(r + 1, r + n + 1);
    int ans = n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (flag[j] && r[j] > r[i])
            {
                flag[j] = 0;
                ans--;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
