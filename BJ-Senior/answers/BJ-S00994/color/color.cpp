#include <bits/stdc++.h>
using namespace std;

int T, n ,a[200010];
bool f[200010];
int ans, tmp;

void DFS( int x)
{
    if( x == n)
    {
        tmp = 0;
        for( int i = 1; i <= n; ++ i)
        {
            for( int j = i - 1; j >= 1; -- j)
            {
                if( f[i] == f[j])
                {
                    if( a[i] == a[j])
                    {
                        tmp += a[i];
                        ans = max( ans, tmp);
                    }
                    break;
                }
            }
        }
        return;
    }
    f[x] = 0;
    DFS( x + 1);
    f[x] = 1;
    DFS( x + 1);
}

int main()
{
    freopen( "color.in", "r", stdin);
    freopen( "color.out", "w", stdout);

    scanf( "%d", &T);
    while( T -- )
    {
        scanf( "%d", &n);
        for( int i = 1; i <= n; ++ i)
        {
            scanf( "%d", &a[i]);
        }

        ans = 0;
        DFS(1);

        printf( "%d\n", ans);
    }

    return 0;
}
