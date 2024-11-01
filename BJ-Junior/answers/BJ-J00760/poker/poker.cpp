#include<bits/stdc++.h>
using namespace std ;
int n , ans ;
bool b[ 10 ][ 50 ] ;
int main(){
    freopen( "poker.in" , "r" , stdin ) ;
    freopen( "poker.out" , "w" , stdout ) ;
    scanf( "%d" , &n ) ;
    for( int i = 1 ; i <= n ; i++ ){
        char c , ch , num ;
        scanf( "%c%c%c" , &c ,  &ch , &num ) ;
        int x , y ;
        if( ch == 'D' ){
            x = 1 ;
        }
        else if( ch == 'C' ){
            x = 2 ;
        }
        else if( ch == 'H' ){
            x = 3 ;
        }
        else{
            x = 4 ;
        }
        if( num >= '2' && num <= '9' ){
            y = num - '0' ;
        }
        else if( num == 'T' ){
            y = 10 ;
        }
        else if( num == 'J' ){
            y = 11 ;
        }
        else if( num == 'Q' ){
            y = 12 ;
        }
        else if( num == 'A'){
            y = 1 ;
        }
        else{
            y = 13 ;
        }
        b[ x ][ y ] = 1 ;
    }
    for( int i = 1 ; i <= 4 ; i++ ){
        for( int j = 1 ; j <= 13 ; j++ ){
            if( !b[ i ][ j ] ){
                ans++ ;
            }
        }
    }
    printf( "%d" , ans ) ;
    return 0 ;
}