#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5, L = 2e3 + 10;
int T, n, k, q, l, r, c;
int s[N][L];

bool dfs(int lastp, int last, int cnt)
{
    for (int p = 0; p < n; p++)
    {
        if (p != lastp)
        {
            for (int x = 0; x < s[p][0]; x++)
            {
                if (s[p][x] == last)
                {
                    if (s[p][0] - x == 1) break;
                    if (cnt == r) for (int y = x + 1; y < min(x + k, s[p][0]); y++) if (s[p][y] == c) return true;
                    else for (int y = x + 1; y < min(x + k, s[p][0]); y++) if (dfs(p, s[p][y], cnt + 1)) return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        cin >> n >> k >> q;
        for (int i = 0; i < n; i++)
        {
            cin >> l;
            s[i][0] = l;
            for (int j = 1; j <= l; j++) cin >> s[i][j];
        }
        for (int i = 1; i <= q; i++)
        {
            cin >> r >> c;
            if (dfs(-1, 1, 0)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}