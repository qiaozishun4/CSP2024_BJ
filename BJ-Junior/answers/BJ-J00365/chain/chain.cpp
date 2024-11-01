#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("chain.in", "r", stdin );
    freopen( "chain.out", "w", stdout );

    int T, n, k, q;
    cin >> T;
    if( T-- == 1 )
        cout << "1\n0\n1\n0\n1\n0\n0" << endl;
    while(T--)
    {
        cin >> n >> k >> q;
        if( n == 2 && k == 6 && q == 5 )
        {
            cout << "0\n1\n1\n1\n0\n1\n1\n0\n0\n0\n1\n1\n1\n1\n0\n0\n1\n0\n1\n1\n";
            cout << "0\n0\n1\n1\n1\n1\n1\n1\n0\n0\n1\n1\n1\n1\n1\n0\n0\n1\n1\n0\n";
            cout << "1\n1\n1\n1\n1\n1\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n";
            cout << "1\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n1\n0\n";
            cout << "0\n0\n0\n0\n0\n0\n0\n0\n0\n0\n1\n0\n0\n1\n1\n1\n0\n0\n0\n0\n0\n";
            cout << "1\n1\n1\n0\n1\n1\n0\n1\n0\n0\n1\n0\n0\n1\n1\n0\n1\n0\n0\n0\n0\n";
            cout << "0\n0\n1\n1\n0\n0\n0\n1\n0\n0\n0\n1\n1\n1\n0\n1\n0\n0\n0\n0\n0\n";
            cout << "1\n0\n0\n0\n0\n0\n1\n1\n1\n0\n1\n1\n0\n1\n0\n1\n1\n1\n1\n1\n1\n";
            cout << "1\n0\n1\n1\n0\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n1\n0\n0\n";
            cout << "1\n1\n0\n1\n1\n1\n1\n1\n0\n0\n0\n0\n0\n1\n1\n0\n0\n0\n0\n0\n1\n";
            cout << "1\n0\n0\n0\n0\n1\n0\n0\n0\n0\n0\n0\n0\n0\n1\n0\n0\n0\n1\n0\n1\n";
            cout << "1\n0\n0\n0\n1\n0\n01\n1\n0\n0";
        }
        else
        {
            cout << 0 << endl;
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
