#include<bits/stdc++.h>
using namespace std ;
int T ;
int n , m , L , V ,d[ 100010 ] , v[ 100010 ] , a[ 100010 ] , p[ 100010 ] ;
int ans1 , ans2 , c[ 100010 ] , mv[ 100010 ] , lv[ 100010 ] ;
bool b[ 100010 ] ;
inline void dfs( int i , int cnt ){
    if( i == m + 1 ){
        bool f = 0 ;
        int res = 0 ;
        memset( b , 0 , sizeof( b ) ) ;
        for( int j = 1 ; j <= m ; j++ ){
            if( !c[ j ] ){
                continue ;
            }
            for( int k = 1 ; k <= n ; k++ ){
                if( !b[ k ] && mv[ k ] <= p[ j ] && p[ j ] < lv[ k ] ){
                    res++ ;
                    b[ k ] = 1 ;
                }
            }
        }
        if( res >= ans1 ){
            ans2 = min( ans2 , cnt ) ;
        }
        return;
    }
    c[ i ] = 0 ;
    dfs( i + 1 , cnt + 1 ) ;
    c[ i ] = 1 ;
    dfs( i + 1 , cnt ) ;
}
int main(){
    freopen( "detect.in" , "r" , stdin ) ;
    freopen( "detect.out" , "w" , stdout ) ;
    scanf( "%d" , &T ) ;
    for( ; T-- ; ){
        scanf( "%d%d%d%d" , &n , &m , &L , &V ) ;
        ans1 = 0 , ans2 = 1e9 ;
        bool f = 1 ;
        for( int i = 1 ; i <= n ; i++ ){
            scanf( "%d%d%d" , &d[ i ] , &v[ i ] , &a[ i ] ) ;
            d[ i ]++ ;
            if( a[ i ] != 0 ){
                f = 0 ;
            }
        }
        for( int i = 1 ; i <= m ; i++ ){
            scanf( "%d" , &p[ i ] ) ;
            p[ i ]++ ;
        }
        sort( p + 1 , p + m + 1 ) ;
        if( f ){
            for( int i = 1 ; i <= n ; i++ ){
                if( v[ i ] > V && d[ i ] <= p[ m ] ){
                    ans1++ ;
                }
            }
            ans2 = m - 1 ;
            if( ans1 == 0 ){
                ans2++ ;
            }
            printf( "%d %d\n" , ans1 , ans2 ) ;
            continue ;
        }
        memset( c , 0 , sizeof( c ) ) ;
        for( int i = 1 ; i <= n ; i++ ){
            if( a[ i ] == 0 ){
                if( v[ i ] > V ){
                    mv[ i ] = d[ i ] ;
                    lv[ i ] = L + 1 ;
                    ans1++ ;
                }
                else{
                    mv[ i ] = L + 1 ;
                    lv[ i ] = L + 1 ;
                }
            }
            else if( a[ i ] < 0 ){
                if( v[ i ] > V ){
                    mv[ i ] = d[ i ] ;
                    lv[ i ] = d[ i ] - 1 + int( ceil( ( V * V - v[ i ] * v[ i ] ) * 1.0 / ( 2 * a[ i ] ) ) ) ;
                    ans1++ ;
                }
                else{
                    mv[ i ] = L + 1 ;
                    lv[ i ] = L + 1 ;
                }
            }
            else{
                if( v[ i ] <= V ){
                    mv[ i ] = d[ i ] - 1 + int( ceil( ( V * V - v[ i ] * v[ i ] ) * 1.0 / ( 2 * a[ i ] ) ) ) ;
                    lv[ i ] = L + 1 ;
                    ans1++ ;
                }
                else{
                    mv[ i ] = d[ i ] ;
                    lv[ i ] = L + 1 ;
                    ans1++ ;
                }
            }
        }
        dfs( 1 , 0 ) ;
        printf( "%d %d\n" , ans1 , ans2 ) ;
    }
    return 0 ;
}