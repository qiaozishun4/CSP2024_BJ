#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int NR = 1e5 + 5;

const int NR = 1e5 + 5;

int n, m;
int a[NR];
int c[NR];
int d[NR];

int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);

    int T;
    cin >> T;
    while (T --)
    {
        cin >> n >> m;
        for (int i = 1;i <= n;i ++)
            cin >> a[i];
        for (int i = 1;i <= m;i ++)
        {
            cin >> c[i];
            int cnt = 0;

        }

        cout << n - 1 << '\n';
    }
    return 0;
}
