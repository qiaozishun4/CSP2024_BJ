#include <bits/stdc++.h>
using namespace std ;

const int N1 = 2e4 + 5 , N2 = 2e5 + 5 ;
int a[N2] , n , ans ;
bool fl[N2] ;
int an () {
    int x = 0 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        for ( int j = i - 1 ; j >= 1 ; -- j ) {
            if ( fl[i] == fl[j] ) {
                if ( a[i] == a[j] ) x += a[i] ;
                break ;
            }
        }
    }
    return x ;
}
void dfs ( int ni ) {
    if ( ni > n ) {
        ans = max ( an() , ans ) ;
    }
    else {
        fl[ni] = 0 ;
        dfs ( ni +1 ) ;
        fl[ni] = 1 ;
        dfs ( ni + 1 ) ;
    }
}
int main () {
    freopen ( "color.in" , "r" , stdin ) ;
    freopen ( "color.out" , "w" , stdout ) ;
    int T ;
    cin >> T ;
    for ( int k = 1 ; k <= T ; ++ k ) {
        ans = 0 ;
        cin >> n ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            cin >> a[i] ;
        }
        dfs ( 1 ) ;
        cout << ans << endl ;
    }
    return 0 ;
}
