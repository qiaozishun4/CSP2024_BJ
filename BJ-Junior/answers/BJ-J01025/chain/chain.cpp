#include <cstdio>
#include <iostream>
using namespace std;

int t;

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        int n, k, q, l[100010], s[200010], cnt = 0, c[100010];
        cin >> n >> k >> q;
        c[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> l[i];
            for (int j = 1; j <= l[i]; j++)
                cin >> s[++cnt];
            c[i] = cnt;
        }
        for (int i = 1; i <= q; i++)
        {
            int r, c0;
            cin >> r >> c0;
            if (r == 1)
            {
                int flag = 0;
                for (int j = 1; j <= n; j++)
                {
                    int f = 0;
                    for (int k1 = c[j - 1] + 1; k1 <= c[j]; k1++)
                        if (s[k1] == 1)
                        {
                            int p = 0;
                            for (int m = k1 + 1; m <= min(k1 + k - 1, c[j]); m++)
                                if (s[m] == c0)
                                {
                                    p = 1;
                                    break;
                                }
                            if (p == 1)
                            {
                                f = 1;
                                break;
                            }
                        }
                    if (f == 1)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1) cout << 1 << endl;
                else cout << 0 << endl;
            }
            else cout << 0 << endl;
        }
    }
    return 0;
}
