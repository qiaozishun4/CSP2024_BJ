#include<bits/stdc++.h>
using namespace std ;
int T , n , c[ 50010 ] , a[ 50010 ] , l ;
const int d[ 15 ] = { 6 , 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6 } ;
inline void dfs( int sum , int pos ){
    if( sum == 0 ){
        bool f = 1 ;
        if( pos > l && l != 0 ){
            f = 0 ;
        }
        for( int i = 1 ; i < pos && f ; i++ ){
            if( a[ i ] > c[ i ] ){
                f = 0 ;
            }
        }
        if( pos < l ){
            f = 1 ;
        }
        if( f ){
            memset( c , 0 , sizeof( c ) ) ;
            for( int i = 1 ; i < pos ; i++ ){
                c[ i ] = a[ i ] ;
            }
            l = pos - 1 ;
        }
        return;
    }
    if( sum < 0 ){
        return;
    }
    for( int i = 0 + ( pos == 1 ); i <= 9 ; i++ ){
        if( l == 0 || pos + 1 + ( ( sum - d[ i ] ) / 8 ) + ( ( sum - d[ i ] ) % 8 != 0 ) < l ){
            a[ pos ] = i ;
            dfs( sum - d[ i ] , pos + 1 ) ;
        }
    }
}
int main(){
    freopen( "sticks.in" , "r" , stdin ) ;
    freopen( "sticks.out" , "w" , stdout ) ;
    scanf( "%d" , &T ) ;
    while( T-- ){
        scanf( "%d" , &n ) ;
        if( n == 1 ){
            printf( "-1\n" ) ;
            continue ;
        }
        if( n % 7 == 0 ){
            for( ; n > 0 ; n -= 7 ){
                printf( "8" ) ;
            }
            printf( "\n" ) ;
            continue ;
        }
        if( n % 7 == 1 ){
            for( ; n > 8 ; n -= 7 ){
                printf( "8" ) ;
            }
            printf( "01\n" ) ;
            continue ;
        }
        l = 0 ;
        memset( c , 127 , sizeof( c ) ) ;
        dfs( n , 1 ) ;
        if( l != 0 ){
            for( int i = 1 ; i <= l ; i++ ){
                printf( "%d" , c[ i ] ) ;
            }
            printf( "\n" ) ;
        }
        else{
            printf( "-1\n" ) ;
        }
    }
    return 0 ;
}