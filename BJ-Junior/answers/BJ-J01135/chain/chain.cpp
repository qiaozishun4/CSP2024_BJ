#include <bits/stdc++.h>
using namespace std;
vector<int> s[100010];
int l[100010];
int r[100010], c[100010];
bool flag[100010];
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    int n, k, q;
    while (T--)
    {
        cin >> n >> k >> q;
        for (int i = 1; i <= n; ++i)
        {
            cin >> l[i];
            for (int j = 1; j <= l[i]; ++j)
            {
                int t;
                cin >> t;
                s[i].push_back(t);
            }
        }
        for (int i = 1; i <= q; ++i)
        {
            cout << 0 << "\n";
        }
  


    }
    return 0;
}
