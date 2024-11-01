#include <bits/stdc++.h>
using namespace std;

int n, k, q, r, c, l[100005], mp[100005][1005];
bool box[200005];

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i++)
        {
            cin >> l[i];
            for (int j = 1; j <= l[i]; j++)
            {
                cin >> mp[i][j];
                box[mp[i][j]] = true;
            }
        }

        for (int i = 1; i <= q; i++)
        {
            cin >> r >> c;
            if (box[c]) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}