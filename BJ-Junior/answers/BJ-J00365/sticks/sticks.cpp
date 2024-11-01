#include<bits/stdc++.h>
using namespace std;
int a[21] = {0, 0, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 80, 88, 108, 220, 228, 280, 288, 688};
int main()
{
    freopen( "stick.in", "r", stdin );
    freopen( "stick.out", "w", stdout );
    int T, n, i;
    cin >> T;
    while( T-- )
    {
        cin >> n;
        if( n == 1 || n == 0 )
            cout << -1 << endl;
        else if( n <= 20 )
            cout << a[n] << endl;
        else if( n % 7 == 0 )
        {
            n /= 7;
            for( i = 0; i < n; i++ )
                cout << 8;
            cout << endl;
        }
        else if( n % 7 == 1 )
        {
            n /= 7;
            n -= 1;
            cout << 10;
            for( i = 0; i <n-1; i++ )
                cout << 8;
            cout << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
