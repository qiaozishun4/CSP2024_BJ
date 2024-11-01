#include<bits/stdc++.h>
using namespace std ;
int T , n , m , k , sx , sy , sd , ans ;
char s[ 1010 ][ 1010 ] ;
bool b[ 1010 ][ 1010 ] ;
int main(){
    freopen( "explore.in" , "r" , stdin ) ;
    freopen( "explore.out" , "w" , stdout ) ;
    scanf( "%d" , &T ) ;
    while( T-- ){
        scanf( "%d%d%d" , &n , &m , &k ) ;
        scanf( "%d%d%d" , &sx , &sy , &sd ) ;
        ans = 1 ;
        memset( b , 0 , sizeof( b ) ) ;
        b[ sx ][ sy ] = 1 ;
        for( int i = 1 ; i <= n ; i++ ){
            scanf( "%s" , s[ i ] + 1 ) ;
        }
        for( int i = 1 ; i <= k ; i++ ){
            int x = sx , y = sy ;
            if( sd == 0 ){
                y++ ;
            }
            else if( sd == 1 ){
                x++ ;
            }
            else if( sd == 2 ){
                y-- ;
            }
            else{
                x-- ;
            }
            if( x >= 1 && x <= n && y >= 1 && y <= m && s[ x ][ y ] == '.' ){
                sx = x , sy = y ;
                if( !b[ x ][ y ] ){
                    b[ x ][ y ] = 1 ;
                    ans++ ;
                }
            }
            else{
                sd = ( sd + 1 ) % 4 ;
            }
        }
        printf( "%d\n" , ans ) ;
    }
    return 0 ;
}