#include <bits/stdc++.h>
using namespace std;
#define int long long

int l[1010], s[1010][1010];
signed main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k, q;
        cin >> n >> k >> q;
        for(int i = 1; i <= n; i++)
        {
            cin >> l[i];
            for(int j = 1; j <= l[i]; j++)
                cin >> s[i][j];
        }
        while(q--)
        {
            int r, c;
            cin >> r >> c;
            bool flag = false;
            for(int i = 1; i <= n; i++)
            {
                int last = 0;
                for(int j = 1; j <= l[i]; j++)
                {
                    if(s[i][j] == c && last && j - last + 1 <= k)
                    {
                        flag = true;
                        i = n + 1;
                        break;
                    }
                    if(s[i][j] == 1)
                        last = j;
                }
            }
            if(flag)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
    return 0;
}
