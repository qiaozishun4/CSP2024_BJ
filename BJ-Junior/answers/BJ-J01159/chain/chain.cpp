#include<bits/stdc++.h>
#define int long long
using namespace std;
bool f[10];
signed main()
{

    freopen("chain.in" , "r" , stdin);
    freopen("chain.out" , "w" , stdout);

    int t;
    cin >> t;
    while (t--)
    {
        memset(f , 0 , sizeof f);
        int n , k , q;
        cin >> n >> k >> q;
        for (int i = 1 ; i <= n ; i++)
        {
            int l;
            cin >> l;
            for (int j = 1 ; j <= l ; j++)
            {
                int s;
                cin >> s;
                f[s] = 1;
            }
        }
        for (int i = 1 ; i <= q ; i++)
        {
            int r , c;
            cin >> r >> c;
            if (!f[c])
            {
                cout << 0 << endl;
            }
            else
            {
                cout << 1 << endl;
            }
        }
    }
    return 0;
}
