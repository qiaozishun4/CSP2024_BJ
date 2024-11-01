#include <iostream>
#include <algorithm>
using namespace std;

const int nr = 1e5 + 5;
int n, ans;
int cnt[nr];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int r;
        cin >> r;
        cnt[r]++;
    }
    for (int i = 1; i <= 1e5; i++)
    {
        ans = max(ans, cnt[i]);
    }
    cout << ans;
    return 0;
}
