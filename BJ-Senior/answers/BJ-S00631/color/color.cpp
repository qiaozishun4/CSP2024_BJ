#include<bits/stdc++.h>
using namespace std ;
int T ;
int n , a[ 100010 ] , ans ;
int c[ 100010 ] ;
inline void dfs( int i ){
    if( i == n + 1 ){
        int res = 0 ;
        for( int j = 1 ; j <= n ; j++ ){
            int pos = -1 ;
            for( int k = j - 1 ; k >= 1 ; k-- ){
                if( c[ j ] == c[ k ] ){
                    pos = k ;
                    break ;
                }
            }
            if( pos != -1 && a[ j ] == a[ pos ] ){
                res += a[ j ] ;
            }
        }
        ans = max( res , ans ) ;
        return;
    }
    c[ i ] = 0 ;
    dfs( i + 1 ) ;
    c[ i ] = 1 ;
    dfs( i + 1 ) ;
}
int main(){
    freopen( "color.in" , "r" , stdin ) ;
    freopen( "color.out" , "w" , stdout ) ;
    scanf( "%d" , &T ) ;
    for( ; T-- ; ){
        scanf( "%d" , &n ) ;
        for( int i = 1 ; i <= n ; i++ ){
            scanf( "%d" , &a[ i ] ) ;
        }
        memset( c , 0 , sizeof( c ) ) ;
        ans = 0 ;
        dfs( 1 ) ;
        printf( "%d\n" , ans ) ;
    }
    return 0 ;
}