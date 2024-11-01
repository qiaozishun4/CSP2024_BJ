#include <iostream>
#include <algorithm>
using namespace std;
int n, r[100005], cnt = 1;
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> r[i];
    sort(r + 1, r + n + 1);
    // now, r[1] can't kill anyone
    for (int i = 2; i <= n; i++)
    {
        // r[i] start killing, target: i - cnt
        if (r[i] <= r[i - cnt])
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}
