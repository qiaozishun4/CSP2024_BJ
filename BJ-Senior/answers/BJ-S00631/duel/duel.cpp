#include<bits/stdc++.h>
using namespace std ;
int n , r[ 100010 ] , ans , q[ 100010 ] , front = 1 , rear = 0 ;
int main(){
    freopen( "duel.in" , "r" , stdin ) ;
    freopen( "duel.out" , "w" , stdout ) ;
    scanf( "%d" , &n ) ;
    for( int i = 1 ; i <= n ; i++ ){
        scanf( "%d" , &r[ i ] ) ;
    }
    sort( r + 1 , r + n + 1 ) ;
    for( int i = 2 ; i <= n ; i++ ){
        q[ ++rear ] = r[ i - 1 ] ;
        if( q[ front ] < r[ i ] ){
            front++ ;
        }
    }
    printf( "%d" , rear - front + 1 + 1 ) ;
    return 0 ;
}