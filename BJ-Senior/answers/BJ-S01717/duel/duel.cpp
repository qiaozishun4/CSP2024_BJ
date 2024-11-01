#include <bits/stdc++.h>
using namespace std ;
const int N = 1e5 + 10 ;
int n ;
int main ( ) {
    freopen ( "duel.in" , "r" , stdin ) ;
    freopen ( "duel.out" , "w" , stdout ) ;
	scanf ( "%d" , &n ) ;
	int a [ n ] , jiyi [ n ] ;
	int maxn = 0 , cnt = 0 , sum = 0 ;
	for ( int i = 0 ; i < n ; ++i ) {
		scanf ( "%d" , & a [ i ] ) ;
		jiyi [ i ] = 0 ;
		maxn = max ( a [ i ] , maxn ) ;
		if ( a [ i ] == 2 )
            ++cnt ;
        else if ( a [ i ] == 1 )
            ++sum ;
	}
    int ans = 0 ;
    sort ( a , a + n ) ;
    for ( int i = 0 ; i < n ; ++i ) {
        for ( int j = i + 1 ; j < n ; ++j ) {
            if ( a [ j ] == a [ i ] )
                continue ;
            if ( a [ j ] > a [ i ] && jiyi [ j ] == 0 ) {
                a [ i ] = 0 ;
                jiyi [ j ] = 1 ;
                ++ans ;
                break ;
            }
        }
    }
    ans = n - ans ;
    printf ( "%d" , ans ) ;
	return 0 ;
}