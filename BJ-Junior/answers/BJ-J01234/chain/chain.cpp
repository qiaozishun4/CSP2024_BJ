#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int T, n, k, q;
int s[1005][2000];
int r[N], c[N];
//bool bl[2 * N];
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i++)
        {
            cin >> s[i][0];
            for (int j = 1; j <= s[i][0]; j++)
            {
                cin >> s[i][j];//
            }
        }
        bool f = 1;
        for (int i = 1; i <= q; i++)
        {
            cin >> r[i] >> c[i];
            if (r[i] > 1) f = 0;
        }
        if (f)
        {
            for (int i = 1; i <= q; i++)
            {
                bool fl = 0;
                for (int j = 1; j <= n; j++)
                {
                    int w1 = 0;
                    for (int p = 1; p <= s[j][0]; p++)
                    {
                        if (s[j][p] == c[i] && w1 != 0 && p - w1 + 1 <= k)
                        {
                            fl = 1;
                            break;
                        }
                        if (s[j][p] == 1)
                        {
                            w1 = p;
                        }
                    }
                    if (fl == 1) break;
                }
                if (fl == 1)
                {
                    cout << "1" << endl;
                }
                else
                {
                    cout << "0" << endl;
                }
            }
        }
    }

    return 0;
}