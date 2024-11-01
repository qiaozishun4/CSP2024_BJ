#include <iostream>
#include <cstring>
using namespace std;
int a[200005], c[200005], vis[1000005];
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        memset(a, 0, sizeof(a));
        memset(vis, 0, sizeof(vis));
        memset(c, 0, sizeof(c));
        int cur = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (vis[a[i]] == 0)
            {
                cur++;
                c[cur] = a[i];
            }
            vis[a[i]]++;
        }
        long long sum = 0;
        for (int i = 1; i <= cur; i++)
        {
            sum += (vis[c[i]] / 2) * c[i];
        }
        cout << sum << endl;
    }
    return 0;
}
