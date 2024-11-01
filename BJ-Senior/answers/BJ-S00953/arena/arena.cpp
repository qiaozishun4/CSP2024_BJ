#include <iostream>
#include <cmath>
#include <algorithm>

#define ll long long
#define maxn 1000007

using namespace std;

ll T , n , m , K , t[maxn] , A[maxn] , c[maxn] , a[maxn] , f[maxn] , val[maxn];
ll ans[maxn] , p[maxn] , q[maxn] , g[maxn];

ll get( ll l , ll r )
{
    return l + r;
}

void work2( ll k , ll P )
{
    for( int i = 1 ; i <= ( 1 << P ) ; ++i ) val[2 * i] = i;
    for( int i = 1 ; i <= P ; ++i )
        for( int j = 1 ; j <= ( 1 << P ) ; j += ( 1 << i ) ) {
            int now = get( j , j + ( 1 << i ) - 1 );
            int ls = get( j , j + ( 1 << ( i - 1 ) ) - 1 );
            int rs = get( j + ( 1 << ( i - 1 ) ) , j + ( 1 << i ) - 1 );
            if( f[now] == 0 ) {
                val[now] = ( a[val[ls]] >= i ? val[ls] : val[rs] );
            }else {
                val[now] = ( a[val[rs]] >= i ? val[rs] : val[ls] );
            }
            t[now] ++;
            //if( t[now] >= 2 ) cout <<"kkk";
        }
    for( int i = P ; i >= 1 ; --i )
        for( int j = 1 ; j <= ( 1 << P ) ; j += ( 1 << i ) ) {
            int now = get( j , j + ( 1 << i ) - 1 );
            int ls = get( j , j + ( 1 << ( i - 1 ) ) - 1 );
            int rs = get( j + ( 1 << ( i - 1 ) ) , j + ( 1 << i ) - 1 );
            if( f[now] == 0 ) {
                p[ls] = max( p[now] , (ll)i );
                p[rs] = ( a[val[ls]] >= i ? 1145141145414514 : p[now] );
            }else {
                p[ls] = p[now];
                p[rs] = max( p[now] , (ll)i );
            }
            if( q[now] == j - 1 ) {
                q[ls] = q[now];
                if( ( f[now] == 0 && a[val[ls]] >= i ) ) {
                    q[rs] = q[now];
                }else q[rs] = q[now] + ( 1 << ( i - 1 ) );
            }else {
                q[ls] = q[rs] = q[now];
            }
        }
    int now = 0;
    for( int i = 1 ; i <= k + 1 ; ++i ) g[i] = 0;
    for( int i = 1 ; i <= k / 2 ; ++i ) if( p[i * 2] <= a[i] ) now = i;
    for( int i = k / 2 + 1 ; i <= k ; ++i ) {
        if( p[2 * i] <= a[i] ) {
            now = i;
        }
        ans[i] += now;
        g[q[2 * i]] += i;
       // cout << q[2 * i] << "\n";
    }
    for( int i = k ; i >= 1 ; --i ) g[i] += g[i + 1];
    for( int i = k / 2 + 1 ; i <= k ; ++i ) ans[i] += g[i];
     for( int i = 1 ; i <= 4 *k ; ++i )
        g[i] = p[i] = q[i] = val[i] = 0;
}

void work()
{
    //for( int i = 1 ; i <= n ; ++i ) cout << a[i] << " ";
    //cout << "\n";
    for( int i = 1 ; i <= ( 1 << K ) ; ++i ) val[2 * i] = i;

    ans[1] = 1;
    for( int i = 1 ; i <= K ; ++i ) {
       work2( 1 << i , i );
    }
    ll sum = 0;

    //cout << val[1 + 8 ] <<"\n";
    //work2( 8 , 3 );
    //for( int i = 1 ; i <= ( 1 << K ) ; ++i ) cout << ans[i] << " ";
    //return;
    for( ll i = 1 ; i<= m ; ++i ) sum ^= i * ans[c[i]];
    cout << sum << "\n";
}

signed main()
{
    freopen( "arena.in" , "r" , stdin );
    freopen( "arena.out" , "w" , stdout );
    ios :: sync_with_stdio( false );
    cin.tie( 0 ); cout.tie( 0 );
    cin >> n >> m;
    for( int i = 1 ; i <= n ; ++i ) cin >> A[i];
    for( int i = 1 ; i <= m ; ++i ) cin >> c[i];
    while( ( 1 << K ) < n ) {
        K ++;
    }
    for( int i = 1 ; i <= K ; ++i )
        for( int j = 1 ; j <= ( 1 << K ) ; j += ( 1 << i ) ) {
            char c; cin >> c;
            f[j + j + ( 1 << i ) - 1] = c - '0';
        }
    cin >> T;
    while( T -- ) {
        ll x[4]; cin >> x[0] >>x[1] >> x[2] >> x[3];
        for( int i = 1 ; i <= n ; ++i ) a[i] = A[i] ^ x[i % 4];
        work();
        //return 0;
        for( int i = 1 ; i <= 250000 ; ++i )
            a[i] = g[i] = p[i] = q[i] = ans[i] = val[i] = 0;
    }
    return 0;
}
