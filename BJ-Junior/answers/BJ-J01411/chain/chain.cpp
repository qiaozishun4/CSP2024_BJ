#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

bool a[200005];

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T;
    cin >> T;

    while (T--)
    {
        int n, k, q;
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i++)
        {
            int m, cnt = 0;
            cin >> m;
            for (int j = 1; j <= m; j++)
            {
                int x;
                cnt--;
                cin >> x;
                if (x == 1) cnt = k;
                if (cnt > 0 && cnt != k) a[x] = true;
            }
        }
        for (int i = 1; i <= q; i++)
        {
            int r, c;
            cin >> r >> c;
            if (a[c]) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}