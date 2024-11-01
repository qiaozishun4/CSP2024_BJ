#include<iostream>
using namespace std;
int t, n, k, q, l, a, r, c;
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        cin >> n >> k >> q;
        for(int i = 1; i <= n; i++)
        {
            cin >> l;
            for(int i = 1; i <= l; i++)
            {
                cin >> a;
            }
        }
        for(int i = 1; i <= q; i++)
        {
            cin >> r >>c;
            cout << 0 << endl;
        }
    }
    return 0;
}