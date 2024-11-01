#include <iostream>
#include <algorithm>
using namespace std;
int a[100005];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int pos = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (pos >= n)
        {
            cout << n - cnt << endl;
            return 0;
        }
        pos = upper_bound(a + pos + 1, a + n + 1, a[i]) - a;
        if (pos <= n) cnt++;
    }
    cout << n - cnt << endl;
    return 0;
}
