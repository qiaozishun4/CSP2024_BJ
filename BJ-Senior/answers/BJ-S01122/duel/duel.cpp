#include <bits/stdc++.h>
using namespace std ;

const int N = 1e5 +5 ;
int a[N] , n ;
int main () {
    freopen ( "duel.in" , "r" , stdin ) ;
    freopen ( "duel.out" , "w" , stdout ) ;
    cin >>n ;
    int ans = n ;
    for (int i = 1 ; i <= n ; ++i ) {
        cin >>a[i] ;
    }
    if ( n <= 1 ) {
        cout << n ;
    }
    else {
        sort ( a + 1 , a + n +1) ;
        int l = 1 , r = 2 ;
        while ( r <= n ) {
            if ( a[l] < a[r] ) {
                ++l ;
                -- ans ;
            }
            ++r;
        }
        cout <<ans << endl;
    }
    return 0 ;
}
