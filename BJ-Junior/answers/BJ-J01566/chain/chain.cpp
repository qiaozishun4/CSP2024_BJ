#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 1e5 + 5;
vector<int> a[N];
int main(){
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T --)
    {
        int n, k, q;
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i ++)
        {
            a[i].clear();
            int m;
            cin >> m;
            a[i].push_back(m);
            for (int j = 1; j <= m; j ++)
            {
                int x;
                cin >> x;
                a[i].push_back(x);
            }
        }
        while (q --)
        {
            int r, t;
            cin >> r >> t;
            bool flg = 0;
            for (int i = 1; i <= n && !flg; i ++)
            {
                for (int l = 1; l <= a[i][0] && !flg; l ++) if (a[i][l] == 1)
                    for (int r = l + 1; r - l + 1 <= k && r <= a[i][0]; r ++)
                        if (a[i][r] == t)
                        {
                            flg = 1;
                            break;
                        }
            }
            cout << flg << "\n";
        }
    }

    return 0;
}