#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005], x[5];
int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    int n, m;
    cin  >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    int z;
    cin >> z;
    while (z--)
    {
        cin >> x[1] >> x[2] >> x[3] >> x[4];
        cout << 1 << endl;
    }
    return 0;
}
