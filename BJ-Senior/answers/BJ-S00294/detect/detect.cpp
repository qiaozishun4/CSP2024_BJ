# include <bits/stdc++.h>

using namespace std ;

const double eps = 1e-8 ;
int n , m , dm , vm ;
int p[100005] ;
int d[100005] , a[100005] , v[100005] ;
int nxtr[1000005] , nxtl[1000005] ;
int findr( int x )
{
    if ( x > dm ) return dm + 1 ;
    if ( x < 0 ) return nxtr[1] ;
    return nxtr[x] ;
}
int findl( int x )
{
    if ( x < 0 ) return 0 ;
    if ( x > dm ) return nxtl[dm] ;
    return nxtl[x] ;
}
int findr( double x )
{
    return findr( ( int ) ceil( x ) ) ;
}
int findl( double x )
{
    return findl( ( int ) floor( x ) ) ;
}
int nl[100005] , nr[100005] ;
bool cmp( pair< int , int > x , pair< int , int > y )
{
    if ( x.first != y.first ) return x.first < y.first ;
    return x.second > y.second ;
}
void solve()
{
    scanf("%d%d%d%d" , &n , &m , &dm , &vm) ;
    dm++ ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        scanf("%d%d%d" , d + i , v + i , a + i) ;
        d[i] ++ ;
    }
    for ( int i = 0 ; i <= dm + 1 ; i++ ) nxtl[i] = nxtr[i] = 0 ;
    nxtr[dm + 1] = dm + 1 ;
    for ( int i = 1 ; i <= m ; i++ ) scanf("%d" , p + i) , p[i] ++ , nxtl[p[i]] = nxtr[p[i]] =i ;
    for ( int i = 1 ; i <= dm + 1 ; i++ )
        if ( ! nxtl[i] ) nxtl[i] = nxtl[i - 1] ;
    for ( int i = dm ; i >= 0 ; i-- )
        if ( ! nxtr[i] ) nxtr[i] = nxtr[i + 1] ;
    int cc = 0 ;
    vector < pair< int , int > > sg ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        int l = 0 , r = 0 ;
        if ( a[i] > 0 )
        {
            if ( v[i] > vm ) l = findr( d[i] ) , r = findl( dm ) ;
            else l = findr( d[i] + 1.0 * ( vm * vm - v[i] * v[i] ) / ( 2 * a[i] ) + eps ) , r = findl( dm ) ;
        }
        else if ( a[i] < 0 )
        {
            if ( v[i] <= vm ) l = 1 , r = 0 ;
            else l = findr( d[i] ) , r = findl( d[i] + 1.0 * ( v[i] * v[i] - vm * vm ) / ( -2 * a[i] ) - eps    ) ;
        }
        else
        {
            if (  v[i] <= vm ) l = 1 , r = 0 ;
            else l = findr( d[i] ) , r = findl( dm ) ;
        }
        if ( l <= r ) sg.push_back( { l , r } ) ;
        // printf("now:%d [%d,%d]\n" , i , l , r) ;
    }
    printf("%d " , sg.size()) ;
    sort( sg.begin() , sg.end() , cmp ) ;
    for ( auto t : sg )
    {
        // printf("ins:[%d,%d]\n" , t.first , t.second) ;
        // for ( int i = 1 ; i <= cc ; i++ ) printf("[%d,%d]\n" , nl[i] , nr[i]) ;
        while ( cc && nr[cc] >= t.second ) cc-- ;
        cc++ ;
        nl[cc] = t.first , nr[cc] = t.second ;
    }
    int ans = 0 ;
    for ( int i = 1 ; i <= cc ; i++ )
    {
        // printf("now:%d %d %d\n" , i, nl[i] , nr[i]) ;
        ans++ ;
        int j = i ;
        while ( j < cc && nl[j + 1] <= nr[i] ) j++ ;
        i = j ;
    } 
    printf("%d\n" , m - ans) ;
}

int main()
{
    freopen("detect.in" , "r" , stdin) ;
    freopen("detect.out" , "w" , stdout) ;
    int t ;
    scanf("%d" , &t) ;
    while ( t -- ) solve() ;
    return 0 ;
}