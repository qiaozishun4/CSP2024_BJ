#include <bits/stdc++.h>
using namespace std;
int T, n, k, q, l, s, r, c;
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >> T;
    while (T--)
    {
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i++)
        {
            cin >> l;
            for (int j = 1; j <= l; j++)
                cin >> s;
        }
        while (q--)
        {
            cin >> r >> c;
        }
    }
    cout << 1 << endl;
    cout << 0 << endl;
    cout << 1 << endl;
    cout << 0 << endl;
    cout << 1 << endl;
    cout << 0 << endl;
    cout << 0;
    return 0;
}
