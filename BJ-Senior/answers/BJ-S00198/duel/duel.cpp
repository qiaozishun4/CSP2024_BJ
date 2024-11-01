#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int NR = 100010;
int a[NR], n, ans;
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int r = 1;
    for (int l = 1; l <= n && r <= n; l++)
    {
        while (a[l] == a[r] && r < n) r++;
        if (r == n && a[l] == a[r]) break;
        ans++, r++;
    }
    cout << n - ans << '\n';
    return 0;
}
