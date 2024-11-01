#include <bits/stdc++.h>
using namespace std;
bool vis[200005];
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        int n, q, k;
        cin >> n >> k >> q;
        for(int i = 1; i <= n; i++)
        {
            int tk;
            cin >> tk;
            for(int j = 1; j <=tk; j++)
            {
                int x;
                cin >> x;
                if(j <= k && j > 1) vis[x] = 1;
            }
        }
        for(int i = 1; i <= q; i++)
        {
            int r;
            cin >> r >> r;
            if(r == 1) vis[r] = 0;
            cout << vis[r] << endl;
        }
    }
    return 0;
}
