#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int NR = 1e5 + 5;

int n;
int r[NR];
int cnt[NR];
int ans = 0;

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    cin >> n;
    for (int i = 1;i <= n;i ++)
    {
        cin >> r[i];
        cnt[r[i]] ++;
    }

    int mx = 0, mn = 1e5 + 5;
    for (int i = 1;i <= 1e5;i ++)
    {
        mx = max(mx, cnt[i]);
        mn = min(mn, cnt[i]);
    }

    cout << mx;
    return 0;
}
