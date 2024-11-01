#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> a[100010];
signed main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k, q;
        cin >> n >> k >> q;
        for(int i = 1; i <= n; i++)
        {
            int d;
            cin >> d;
            while(d--)
            {
                int x;
                cin >> x;
                a[i].push_back(x);
            }
        }
        while(q--)
        {
            int r, c;
            cin >> r >> c;
            if(r == 1)
            {
                bool f = 0;
                for(int i = 1; i <= n; i++)
                {
                    for(int j = 0; j < a[i].size(); j++)
                    {
                        if(a[i][j] == 1)
                        {
                            for(int l = j + 2; l < j + k; l++)
                            {
                                if(l == c)
                                {
                                    f = 1;
                                    cout << 1 << endl;
                                    break;
                                }
                            }
                        }
                        if(f) break;
                    }
                    if(f) break;
                }
                if(!f) cout << 0 << endl;
            }
        }
    }
    return 0;
}
/*




*/
