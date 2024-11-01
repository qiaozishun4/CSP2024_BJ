#include <bits/stdc++.h>
using namespace std;

const int NR = 1e5 + 10, LIM = 1e5;
int a[NR], cnt[NR], ans, n;

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(int i = 1; i <= LIM; i++)
    {
        ans = max(ans, cnt[i]);
    }
    cout << ans << "\n";
    return 0;
}