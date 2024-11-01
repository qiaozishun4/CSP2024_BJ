# include <iostream>
# include <algorithm>
# include <fstream>
using namespace std;
const int MAXN = 100005;
int n, ans, t = 1;
int r[MAXN];

int main()
{
    freopen ("duel.in", "r", stdin);
    freopen ("duel.out", "w", stdout);
    cin >> n;
    ans = n;
    for (int i = 1; i <= n; i++)
        cin >> r[i];
    sort (r + 1, r + n + 1);
    for (int i = 2; i <= n; i++)
        if (r[i] > r[t])
        {
            ans--;
            t++;
        }
    cout << ans;
    return 0;
}