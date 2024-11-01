#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 100;
vector<int> a[N];

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
        for (int i = 1; i <= n; i++) a[i].clear();
        for (int i = 1; i <= n; i++)
        {
            int lenth;
            cin >> lenth;
            for (int j = 1; j <= lenth; j++) 
            {
                int tmp;
                cin >> tmp;
                a[i].push_back(tmp);
            }
        }
        while (q--)
        {
            int r, c;
            scanf("%d%d", &r, &c);
            bool flag = 0;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 0; j < a[i].size(); j++)
                {
                    if (a[i][j] == 1)
                    {
                        for (int t = 2; t <= k; t++)
                            if (a[i][j + t - 1] == c) {flag = 1;break; }
                    }
                    if (flag) break; 
                }
                if (flag) break;
            }
            if (flag) cout << 1 << endl;
            else cout << 0 << endl;

        }
    }
    return 0;
}