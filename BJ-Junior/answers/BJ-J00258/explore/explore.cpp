#include <bits/stdc++.h>

using namespace std ;

char a[1e+3][1e+3] ;
bool soe[1e+3][1e+3] ;

void meterlo ()
{

}

int main ()
{
    freopen("explore.in", "r", stdin) ;
    freopen("explore.out", "w", stdout) ;
    int n ;
    cin >> n ;

    while (n--)
    {
        int ans = 0, n, m, k, x, y, d ;
        memset(soe, 0, sizeof(soe)) ;
        memset(a, '\0', sizeof(a)) ;
        cin >> n >> m >> k >> x >> y >> d ;

        soe[x][y] = 1 ;

        for (int i = 1 ; i <= n ; i++)
            for (int j = 1 ; j <= m ; j++)
                cin >> a[i][j] ;
        while (k--)
            movelo(x, y, d) ;
        for (int i = 1 ; i <= n ; i++)
            for (int j = 1 ; j <= m ; j++)
                if (soe[i][j])
                    ans++ ;
        cout << ans << endl ;
    }

    return 0 ;
}
