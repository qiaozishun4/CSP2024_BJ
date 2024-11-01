#include <iostream>
#include <cstring>
#include <vector>
#include <bitset>
#define int long long
using namespace std;
int T, n, k, q, l[100005], lsum[100005], posS[200005], r, c;
vector<int> S[100005];
bitset<200005> visnot[105]; // 1 : can't 0 : can
int p[105][200005];
signed main()
{
    freopen("chain2.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while (T--)
    {
        cin >> n >> k >> q;
        l[0] = lsum[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> l[i];
            S[i].clear();
            for (int j = 0; j < l[i]; j++)
            {
                posS[lsum[i - 1] + j] = i;
                S[i].push_back(j);
            }
        }
        memset(p, 0, sizeof(p));
        for (int t = 1; t <= 100; t++)
        {
            for (int i = 1; i <= n; i++)
            {
                int lenlft = 0;
                for (int j = 0; j < l[i]; j++)
                {
                    int pos = lsum[i - 1] + j;
                    if (lenlft)
                    {
                        if (p[t][S[i][j]] && p[t][S[i][j]] != i)
                            p[t][S[i][j]] = n + 1;
                        else
                            p[t][S[i][j]] = i;
                    }
                    if (!visnot[t][pos])
                    {
                        lenlft = k;
                    }
                    k--;
                }
            }
            for (int i = 1; i <= n; i++)
                for (int j = 0; j < l[i]; j++)
                    visnot[t][lsum[i - 1] + j] = !(p[t][S[i][j]] && p[t][S[i][j]] != i);
        }
        for (int i = 1; i <= q; i++)
        {
            cin >> r >> c;
            cout << (bool)p[r][c] << endl;
        }
    }
    return 0;
}
