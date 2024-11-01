# include <bits/stdc++.h>

using namespace std ;

int n ;
int b[200005] , m ;
int a[200005] , nxt[200005] , p[1000005] ;
typedef long long ll ;
ll dp[200005] , maxv[200005] ;
stack < int > stk ;
void solve()
{
    scanf("%d" , &n) ;
    ll add = 0 ;
    m = 0 ;
    for ( int i = 1 ; i <= n ; i++ ) scanf("%d" , a + i) ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        b[++ m] = a[i] ;
        int j = i ;
        while ( j < n && a[j + 1] == a[j] ) j++ ;
        add += 1ll * a[i] * ( j - i ) ;
        i = j ;
    }
    // printf("add:%lld\n" , add) ;
    n = m ;
    for ( int i = 1 ; i <= n ; i++ ) a[i] = b[i] ;
    for ( int i = n ; i >= 1 ; i-- )
    {
        if ( ! p[a[i]] ) nxt[i] = n + 1 ;
        else nxt[i] = p[a[i]] ;
        p[a[i]] = i ;
    }
    for ( int i = 1 ; i <= n + 1 ; i++ ) dp[i] = maxv[i] = 0 ;
    for ( int i = n ; i >= 1 ; i-- )
    {
        if ( nxt[i] == n + 1 ) dp[i] = 0 ;
        else
        {
            if ( nxt[i] == i + 1 ) dp[i] = a[i] + maxv[i + 1] ;
            else dp[i] = a[i] + maxv[nxt[i] - 1] ;
        }
        maxv[i] = max( maxv[i + 1] , dp[i]) ;
    }
    for ( int i = 1 ; i <= n ; i++ ) p[a[i]] = 0 ;
    printf("%lld\n" , maxv[1] + add) ;
}

int main()
{
    freopen("color.in" , "r" , stdin) ;
    freopen("color.out" , "w" , stdout) ;
    int t ;
    scanf("%d" , &t) ;
    while ( t -- ) solve() ;
    return 0 ;
}