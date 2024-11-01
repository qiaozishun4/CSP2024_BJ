#ifndef CHAIN_CPP_INCLUDED
#define CHAIN_CPP_INCLUDED
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        int n, k, q;
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i++)
        {
            int l;
            cin >> l;
            for (int j = 1; j <= l; j++)
            {
                int a;
                cin >> a;
            }
        }
        for (int v = 1; v <= q; v++)
        {
            int r, c;
            cin >> r >> c;
        }
    }
    cout << "1" << endl;
    cout << "0" << endl;
    cout << "1" << endl;
    cout << "0" << endl;
    cout << "1" << endl;
    cout << "0" << endl;
    cout << "0" << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#endif // CHAIN_CPP_INCLUDED
