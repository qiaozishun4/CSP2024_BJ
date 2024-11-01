#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
long long a[N] , b[N];
int main()
{
    freopen( "color.in" , "r" , stdin );
    freopen( "color.out" , "w" , stdout );
    ios::sync_with_stdio( false );
    cin.tie( 0 ) , cout.tie( 0 );
    int T;
    cin >> T;
    while( T-- )
    {
        memset( a , 0 , sizeof( a ) );
        memset( b , 0 , sizeof( b ) );
        int n;
        cin >> n;
        long long c = 0;
        for( int i = 0; i < n; i++ )
        {
            cin >> a[i];
            b[a[i]]++;
            //cout << a[i] << " " << b[a[i]] << endl;
        }
        //cout << endl;
        for( int i = 0; i < n; i++ )
        {
            if( b[a[i]] == 0 || b[a[i]] == 1 )
            {
                continue;
            }
            c += ( b[a[i]] - 1 ) * a[i];
            b[a[i]] = 0;
            //cout << i << " " << b[a[i]] << " " << a[i] << endl;
        }
        cout << c << endl;
    }
    return 0;
}
