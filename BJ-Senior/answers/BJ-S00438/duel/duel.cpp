#include <bits/stdc++.h>
#define int long long
using namespace std;

const int NR = 1e5;
int n, a[NR + 7], t[NR + 7], b[NR + 7];

signed main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        t[a[i]]++;
        b[a[i]]++;
    }
    int id = NR - 1;
    for(int i = NR; i >= 1; i--)
    {
        if(id >= i) id = i - 1;
        while(b[id] <= t[i] && id >= 1)
        {
            t[i] -= b[id];
            b[id] = 0;
            id--;
        }
        b[id] -= t[i];
        t[i] = 0;
    }
    int ans = 0;
    for(int i = 1; i <= NR; i++)
        ans += b[i];
    cout << ans << endl;
    return 0;
}
