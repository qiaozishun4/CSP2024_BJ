#include <iostream>
#define int long long
using namespace std;
int T, n, k, d;
int cost[10] = {1, 5, 2, 2, 3, 2, 1, 4, 0, 1};
int num[7] = {8, 0, 2, 4, 7, 1, -1};
int nummin[7] = {8, 0, 0, 0, 0, 0, 0};
int numtop[7] = {8, 6, 2, 4, 7, 1, -1};
int numtopmin[7] = {8, 6, 2, 2, 2, 1, 1};
signed main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while (T--)
    {
        cin >> n;
        k = (n + 6) / 7;
        d = 7 * k - n;
        if (n == 1) // d = 6 special
        {
            cout << -1 << endl;
            continue;
        }
        if (k == 1)
        {
            cout << numtop[d] << endl;
            continue;
        }
        for (int i = 1; i < k; i++)
        {
            if (i == 1)
            {
                cout << numtopmin[d];
                d -= cost[numtopmin[d]];
            }
            else
            {
                cout << nummin[d];
                d -= cost[nummin[d]];
            }
        }
        cout << num[d] << endl;
    }
    return 0;
}
