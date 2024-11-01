#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, ans, a[100005];
bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    ans = n;
    int r = 2;
    for (int l = 1; l <= n; l++)
    {
        while (a[l] == a[r] && r <= n)
        {
            r++;
        }
        if (r > n)
        {
            break;
        }
        ans--;
        r++;
    }
    cout << ans << "\n";
    return 0;
}