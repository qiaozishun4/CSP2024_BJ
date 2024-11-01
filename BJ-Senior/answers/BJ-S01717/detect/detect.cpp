#include <bits/stdc++.h>
using namespace std ;
int main ( ) {
    freopen ( "detect.in" , "r" , stdin ) ;
    freopen ( "detect.out" , "w" , stdout ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    int a [ t ] ;
    for ( int z = 0 ; z < t ; ++z ) {
        long long n ,cnt = 0 ;
        cin >> n ;
        int d [ n ] ;
        int jiyi [ n ] ;
        for ( long long i = 0 ; i < n ; ++i )
            jiyi [ i ] = 0 ;
        for ( long long i = 0 ; i < n ; ++i ) {
            scanf ( "%d" , &d [ i ] );
            if ( jiyi [ d [ i ] ] == d [ i ] )
                cnt += d [ i ] ;
            jiyi [ d [ i ] ] = d [ i ] ;
        }
        a [ z ] = cnt ;
    }
    for ( int i = 0 ; i < t ; ++i )
        printf ( "%d\n" , a [ i ] ) ;
    return 0 ;
}