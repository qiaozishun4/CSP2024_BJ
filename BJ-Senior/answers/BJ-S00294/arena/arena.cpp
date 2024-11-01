# include <bits/stdc++.h>

using namespace std ;

int n , m ;
int a[100005] , cp[100005] ;
int c[100005] ;
int nd ;
int idx ;
int ch[400005][2] , v[400005] , d[400005] ;
int k ;
int f[400005] , t[400005] , fa[400005] ;
int pv[400005] , gt[400005] ;
int lt[400005] , rt[400005] ;
typedef long long ll ;
ll s[400005] ;
int id[400005] ;

int main()
{
    freopen("arena.in" , "r" , stdin) ;
    freopen("arena.out" , "w" , stdout) ;
    scanf("%d%d" , &n , &m) ;
    for ( int i = 1 ; i <= n ; i++ ) scanf("%d" , cp + i) ;
    for ( int i = 1 ; i <= m ; i++ ) scanf("%d" , c + i) ;
    for ( k = 0 ; ; k++ )
        if ( ( 1 << k ) >= n ) break ;
    nd = ( 1 << k ) ;
    int lst = 0 ;
    idx = ( 1 << k ) ;
    for ( int i = 1 ; i <= k ; i++ )
    {
        for ( int j = lst + 1 ; j <= lst + ( 1 << ( k - i + 1 ) ) ; j += 2 )
        {
            idx++ ;
            ch[idx][0] = j , ch[idx][1] = j + 1 ;
            fa[j] = fa[j + 1] = idx ;
            v[idx] = i ;
            scanf("%1d" , &d[idx]) ;
            pv[ch[idx][d[idx]]] = i ;
            // printf("tree:%d %d %d %d\n" , idx , j , j + 1 , v[idx]) ;
        }
        lst += ( 1 << ( k - i + 1 ) ) ;
    }
    lt[1] = 1 ;
    for ( int i = 1 ; i <= k ; i++ )
        for ( int j = ( 1 << ( i - 1 ) ) + 1 ; j <= ( 1 << i ) ; j++ ) lt[j] = 1 + ( 1 << ( i - 1 ) ) ;
    for ( int i = idx - 1 ; i >= 1 ; i-- ) pv[i] = max( pv[i] , pv[fa[i]] ) ;
    int T ;
    scanf("%d" , &T) ;
    while ( T -- )
    {
        int rd[5] ;
        for ( int i = 0 ; i < 4 ; i++ ) scanf("%d" , rd + i) ;
        for ( int i = 1 ; i <= n ; i++ ) a[i] = ( cp[i] ^ rd[i % 4] ) , id[i] = i ;
        for ( int i = ( 1 << k ) + 1 ; i <= idx ; i++ )
        {
            if ( a[id[ch[i][d[i]]]] >= v[i] ) id[i] = id[ch[i][d[i]]] ;
            else id[i] = id[ch[i][1 - d[i]]] ;
            // printf("id[%d] %d\n" , i , id[i]) ;
        }
        ll res = 0 ;
        for ( int i = 1 ; i <= m ; i++ )
        {
            int x = 1 ;
            for ( int j = 0 ; j <= k ; j++ )
            {
                if ( c[i] == ( 1 << j ) ) res ^= 1ll * i * id[x] ;
                x = fa[x] ;
            }
        }
        printf("%lld\n" , res) ;
        // for ( int i = 1 ; i <= idx ; i++ )f[i] = t[i] ;
        // for ( int i = 1 ; i <= n ; i++ ) a[i] = ( cp[i] ^ rd[i % 4] ) , f[i] = a[i] , t[i] = i ;
        // for ( int i = 0 ; i <= n ; i++ ) s[i] = 0 ;
        // for ( int i = 1 ; i <= idx ; i++ ) gt[i] = ( 1 << k ) + 1 ;
        // for ( int i = ( 1 << k ) + 1 ; i <= idx ; i++ )
        // {
        //     if ( d[i] == 0 && t[ch[i][0]] )
        //     {
        //         if ( f[ch[i][0]] >= v[i] ) f[i] = f[ch[i][0]] , t[i] = t[ch[i][0]] ;
        //         else if ( t[ch[i][1]] ) f[i] = f[ch[i][1]] , t[i] = max( t[ch[i][0]] , t[ch[i][1]] ) ;
        //     }
        //     if ( d[i] == 1 && t[ch[i][1]] )
        //     {
        //         if ( f[ch[i][1]] >= v[i] ) f[i] = f[ch[i][1]] , t[i] = t[ch[i][1]] ;
        //         else if ( t[ch[i][0]] ) f[i] = f[ch[i][0]] , t[i] = max( t[ch[i][0]] , t[ch[i][1]] ) ; 
        //     }
        // }
        // for ( int i = 1 ; i <= idx - 1 ; i++ ) 
        //     if ( i == ch[fa[i]][d[fa[i]]] && f[i] >= v[fa[i]] )
        //     {
        //         gt[ch[fa[i]][1 - d[fa[i]]]] = t[i] ;
        //     }
        // for ( int i = idx - 1 ; i >= 1 ; i-- ) gt[i] = min( gt[i] , gt[fa[i]] ) ;
        // for ( int i = 1 ; i <= ( 1 << k ) ; i++ )
        // {
        //     rt[i] = gt[i] - 1 ;
        //     if ( i <= n && a[i] < pv[i] ) rt[i] = min( rt[i] , i - 1 ) ;
        //     if ( lt[i] > rt[i] ) continue ;
        //     // printf("now:%d %d %d %d %d\n" , i , pv[i] , a[i] , lt[i] , rt[i]) ;
        //     s[lt[i]] += i ;
        //     if ( rt[i] + 1 <= n ) 
        //         s[rt[i] + 1] -= i ;
        // }
        // // puts("now:") ;
        // for ( int i = 1 ; i <= n ; i++ ) s[i] += s[i - 1] ;
        // ll res = 0 ;
        // for ( int i = 1 ; i <= m ; i++) 
        // {
        //     res ^= ( s[c[i]] * i ) ;
        //     // printf("%lld\n" , s[c[i]]) ;
        // }
        // printf("%lld\n" , res) ;
    }
    return 0 ;
}