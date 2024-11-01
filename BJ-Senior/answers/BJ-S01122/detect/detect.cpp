#include <bits/stdc++.h>
using namespace std ;

const int N = 1e5 +5 ;
int num , n , m , L, V , T ;
int a[N][2] , p[N] ,d[N] , v[N] , aj[N],ansmin ;
bool fm[N] ;
int findmin ( int x ) { // 能检测到的最前检测器即大于等于x的
    int l = 1 , r = m ;
    while ( l <= r ) {
        int mid = ( l +r ) / 2 ;
        if ( p[mid] == x ) {
            return mid ;
        }
        if ( p[mid] > x ) r = mid -1;
        else l = mid + 1 ;
    }
    return l ;
}
int findmax ( int x ) { // 能检测到的最后检测器即小于等于x的
    int l = 1 , r = m ;
    while ( l <= r ) {
        int mid = ( l +r ) / 2 ;
        if ( p[mid] == x ) {
            return mid ;
        }
        if ( p[mid] > x ) r = mid -1;
        else l = mid + 1 ;
    }
    return r ;
}
bool rig () {
    for ( int i = 1 ; i <= n ; ++ i ) {
        bool fll = 0 ;
        for ( int j = a[i][0] ; j <= a[i][1] ; ++ j ) {
            if ( fm[j] ) { fll = 1 ; break ; }
        }
        if ( !fll ) return 0 ;
    }
    return 1 ;
}
void dfs ( int mi , int anss ) {
    if ( mi > m ) {
        if ( rig() )
            ansmin = min ( ansmin , anss );
    }
    else if ( anss < ansmin ) {
        fm[mi] = 0 ;
        dfs ( mi + 1 , anss ) ;
        fm[mi] = 1 ;
        dfs ( mi + 1 , anss + 1 ) ;
    }
}
int main () {
    freopen ( "detect.in" , "r" , stdin ) ;
    freopen ( "detect.out" , "w" , stdout ) ;
    cin >> T ;
    for ( int k = 1 ; k <= T ; ++ k ) {
        cin >> num >> m >> L >>V ;
        int s = 0 ;
        ansmin = m ;
        bool fl = 1 ;
        for ( int i = 1 ; i <= num ; ++ i ) {
            cin >>d[i] >> v[i] >>aj[i] ;
            if ( aj[i] < 0 ) fl = 0 ;
        }
        for ( int i = 1 ; i <= m ; ++ i ) cin >> p[i] ;
        if ( fl ) {
            int ans = 0 ;
            for ( int i = 1 ; i <= num ; ++ i ) {
                if ( d[i] > p[m] ) continue ;
                if ( v[i] > V ) ++ ans ;
                else if ( v[i] <= V && aj[i] == 0 ) continue ;
                else {
                    int d1 = ( V *V- v[i] *v[i] ) / ( 2 * aj[i] )  + 1 + d[i] ;
                    if ( d1 <= p[m] ) ++ans ;
                }
            }
            if ( ans == 0 ) cout << ans << " " << m << endl ;
            else cout << ans << " " << m-1 << endl ;
        }
        else {
            for ( int i = 1 ; i <= num ; ++ i ) {
                if ( d[i] > p[m] ) continue ;
                int d2 ;
                if ( (v[i] <= V && aj[i] <= 0) ) {
                    continue ;
                }
                if ( v[i] > V ) {
                    int findmind = findmin ( d[i] ) ;
                    if (aj[i] >=0 ) {
                        ++ s ;
                        a[s][0] = findmind ;
                        a[s][1] = m ;
                    }
                    else {
                        d2 = ( V *V- v[i] *v[i] ) / ( 2 * aj[i] ) ;
                        if ( d2 * ( -1 * 2 * aj[i] ) + V * V == v[i] * v[i] ) -- d2 ;
                        d2 += d[i] ;
                        if ( d2 >= p[m]){
                            ++ s ;
                            a[s][0] = findmind ;
                            a[s][1] = m ;
                        }
                            else {
                            int findmaxd2 = findmax (d2 ) ;
                            if ( findmaxd2 < findmind )continue;
                            ++ s ;
                            a[s][0] = findmind ;
                            a[s][1] = findmaxd2 ;
                        }
                    }
                }
                else {
                    if ( aj[i] <= 0 ) continue ;
                    int d1 = ( V *V- v[i] *v[i] ) / ( 2 * aj[i] )  + 1 + d[i] ;
                    if ( d1 > p[m] ) continue ;
                    ++ s ;
                    a[s][0] = findmin ( d1 ) ;
                    a[s][1] = m ;
                }
            }
            n = s ;
            dfs ( 1 , 0 ) ;
            cout << n << " " << m - ansmin << endl;
        }
    }
    return 0 ;
}
