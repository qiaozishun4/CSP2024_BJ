#include <iostream>
#include <cmath>
#include <algorithm>

#define db double
#define maxn 100007
#define eps 0.0000001

using namespace std;

int t , n , m , ans , a[maxn] , f[maxn]; db p[maxn] , L , V , d[maxn] , v[maxn] , b[maxn];

void get( db s1 , db s2 )
{
    if( s1 > s2 ) return;
    int r = ( lower_bound( p + 1 , p + m + 1 , s2 + eps ) - p - 1 );
    //if( p[a[r]] >= s1 ) return;
    int l = ( lower_bound( p + 1 , p + m + 1 , s1 ) - p );

    if( l > r ) return;
    ans ++;
    a[r] = max( a[r] , l );
    //cout << l <<" " << r << "\n";
}

int main()
{
    freopen( "detect.in" , "r" , stdin );
    freopen( "detect.out" , "w" , stdout );
    ios :: sync_with_stdio( false );
    cin.tie( 0 ); cout.tie( 0 );
    cin >> t;
    while( t -- ) {
        cin >> n >> m >> L >> V; ans = 0; p[0] = -114514114514114514;
        for( int i = 1 ; i <= n ; ++i ) {
            cin >> d[i] >> v[i] >> b[i];
        }
        for( int i = 1 ; i <= m ; ++i ) cin >> p[i];
        for( int i = 1 ; i <= n ; ++i ) {
            if( b[i] == 0 ) {
                if( v[i] > V ) get( d[i] , L );
                continue;
            }
            if( v[i] <= V && b[i] < 0 ) continue;
            if( v[i] > V && b[i] > 0 ) {
                get( d[i] , L );
                continue;
            }
            db l = -114154114514 , r = 114514114154 , mid , sum = 0;
            if( b[i] < 0 ) {
                get( d[i] , d[i] + ( V * V - v[i] * v[i] ) / ( 2 * b[i] ) - eps );
            }else {
                db pos = ( V * V - v[i] * v[i] ) / ( 2 * b[i] );
                //if( sqrt( v[i] * v[i] + 2 * d[i] * pos ) <= V ) cout << "kkk";
                get( max( d[i] , d[i] + ( V * V - v[i] * v[i] ) / ( 2 * b[i] ) + eps ) , L );
            }

        }
        int sum = 0; f[0] = 0;
        for( int i = 1 ; i<= m + 1 ; ++i ) {
            sum = max( sum , a[i - 1] );
            f[i] = f[sum] + 1;
        }
        cout << ans <<" " << m + 1 - f[m + 1] << "\n";
        for( int i = 1 ; i <= m ; ++i ) f[i] = a[i] = 0;
    }
    return 0;
}
