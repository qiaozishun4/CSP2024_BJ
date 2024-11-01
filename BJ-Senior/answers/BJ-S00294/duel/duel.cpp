# include <bits/stdc++.h>

using namespace std ;

int n ;
int r[100005] ;
bool st[100005] ;
int np[100005] ;
int main()
{
    freopen("duel.in" , "r" , stdin) ;
    freopen("duel.out" , "w" , stdout) ;
    scanf("%d" , &n) ;
    for( int i = 1 ; i <= n ; i++ ) scanf("%d" , r + i) ;
    sort( r + 1 , r + n + 1 ) ;
    int cc = 0 , pos = 0 ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        while ( pos < n && r[pos + 1] < r[i] ) pos++ ;
        np[i] = pos ;
    }
    for ( int i = n - 1 ; i >= 1 ; i-- ) np[i] = min( np[i + 1] - 1 , np[i] ) ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        if ( np[i] >= 1 ) st[np[i]] = true ;
    }
    int ans = 0 ;
    for ( int i =1 ; i <= n ; i++ )
        if ( ! st[i] ) ans++ ;
    printf("%d\n" , ans) ;
    return 0 ; 
}