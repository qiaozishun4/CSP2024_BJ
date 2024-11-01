#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int d[N] , v[N] , a[N] , p[N];
int main()
{
    freopen( "detect.in" , "r" , stdin );
    freopen( "detect.out" , "w" , stdout );
    ios::sync_with_stdio( false );
    cin.tie( 0 ) , cout.tie( 0 );
    int T;
    cin >> T;
    while( T-- )
    {
        int n , m , L , V;
        cin >> n >> m >> L >> V;
        int sum = 0;
        memset( d , 0 , sizeof( d ) );
        memset( v , 0 , sizeof( v ) );
        memset( a , 0 , sizeof( a ) );
        memset( p , 0 , sizeof( p ) );
        for( int i = 0 ;i < n; i++ )
        {
             cin >> d[i] >> v[i] >> a[i];
        }
        for( int i = 0 ;i < m; i++ )
        {
             cin >> p[i];
        }
        for( int i = 0; i < n; i++ )
        {
            if( d[i] > p[m - 1] )
            {
                continue;
            }
            if( a[i] == 0 )
            {
                if( v[i] > V )
                {
                    sum++;
                }
            }
            if( a[i] > 0 )
            {
                double vv = sqrt( v[i] * v[i] + 2 * a[i] * ( p[m - 1] - d[i] ) );
                if( d[i] > p[m - 1] )
                {
                    continue;
                }
                if( vv > V )
                {
                    sum++;
                }
            }
            if( a[i] < 0 )
            {
                sum++;
            }
        }
        cout << sum << " ";
        if( sum == 0 )
        {
            cout << m << endl;
        }
        else
        {
            cout << m - 1 << endl;
        }
    }
    return 0;
}
