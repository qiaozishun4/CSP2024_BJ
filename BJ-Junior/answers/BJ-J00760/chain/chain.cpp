#include<bits/stdc++.h>
using namespace std ;
int T ;
int n , k , q ;
int l[ 100010 ] , s[ 100010 ][ 3 ] ;
int main(){
    freopen( "chain.in" , "r" , stdin ) ;
    freopen( "chain.out" , "w" , stdout ) ;
    scanf( "%d" , &T ) ;
    while( T-- ){
        scanf( "%d%d%d" , &n , &k , &q ) ;
        for( int i = 1 ; i <= n ; i++ ){
            scanf( "%d" , &l[ i ] ) ;
            for( int j = 1 ; j <= l[ i ] ; j++ ){
                int x ;
                scanf( "%d" , &x ) ;
                if( j == 1 ){
                    s[ i ][ 1 ] = x ;
                }
                if( j == l[ i ] ){
                    s[ i ][ 2 ] = x ;
                }
            }
        }
        for( ; q-- ; ){
            int r , c ;
            scanf( "%d%d" , &r , &c ) ;
            if( r > 1 ){
                printf( "0\n" ) ;
            }
            else{
                bool f = 0 ;
                for( int i = 1 ; i <= n ; i++ ){
                    if( s[ i ][ 1 ] == 1 && s[ i ][ 2 ] == c && l[ i ] == k ){
                        printf( "1\n" ) ;
                        f = 1 ;
                    }
                }
                if( !f ){
                    printf( "0\n" ) ;
                }
            }
        }
    }
    return 0 ;
}