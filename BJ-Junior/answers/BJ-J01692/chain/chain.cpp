#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int a[1010][2010];

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, kk, q;
        cin >> n >> kk >> q;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i][0];
            for (int j = 1; j <= a[i][0]; ++j)
                cin >> a[i][j];
        }
        while (q--)
        {
            int r, c;
            cin >> r >> c;
            bool flag = 0;
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= a[i][0]; ++j)
                {
                    if (a[i][j] != 1)
                        continue;
                    for (int k = j; k <= j + kk - 1 && k <= a[i][0]; ++k)
                        if (a[i][k] == c)
                        {
                            flag = 1;
                            break;
                        }
                    if (flag) break;
                }
                if (flag) break;
            }
            if (flag)
                cout << 1 << endl;
            else
                cout << 0 << endl;;
        }
    }
    return 0;
}
