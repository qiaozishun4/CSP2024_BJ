#include <iostream>
#include <cmath>
#include <algorithm>

#define ll long long
#define maxn 1000007

using namespace std;

ll T , n , ans , sum , a[200007] , f[200007] , t[maxn] , b[200007];

int main()
{
    freopen( "color.in" , "r" , stdin );
    freopen( "color.out" , "w" , stdout );
    ios :: sync_with_stdio( false );
    cin.tie( 0 ); cout.tie( 0 );
    cin >> T;
    while( T -- ) {
        cin >> n; ans = 0;
        for( int i = 1 ; i <= n ; ++i ) cin >> a[i];
        for( int i =1  ; i<= n ; ++i ) b[i] = ( a[i] == a[i - 1] ? a[i] : 0 );
        for( int i = 1 ; i <= n ; ++i ) ans += b[i];
        f[0] = 0; sum = 0;
        ll tmp = 0;
        for( int i = 1 ; i <= n ; ++i ) tmp = max( tmp , a[i] );
        for( int i = 1 ; i <= tmp ; ++i ) t[i] = -114514114514114514;
        ll mx = 0;
        for( int i = 1 ; i <= n ; ++i ) {
            mx = max( mx , f[i - 1] );
            t[a[max( 0 , i - 2 )]] = max( t[a[max( 0 , i - 2 )]] , f[i - 1] );
            f[i] = -b[i] + max( mx , t[a[i]] +a[i] );
            sum = max( sum , f[i] );
        }
        cout << ans + sum << "\n";
        for( int i = 1 ; i<= n ; ++i ) b[i] = f[i] = 0;
     }
    return 0;
}
