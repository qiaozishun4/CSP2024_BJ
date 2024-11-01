#include <bits/stdc++.h>
using namespace std;

int n, r[100010], b[100010], ans = 0;
int att;

void awa_input()
{
    scanf( "%d", &n);
    for( int i = 1; i <= n; ++ i)
    {
        scanf( "%d", &r[i]);
    }
}

void awa_sort()
{
    for( int i = 1; i <= n; ++ i)
    {
        ++ b[r[i]];
    }
}
void awa_solve()
{
    awa_sort();
    for( int i = 2; i <= 100000; ++ i)
    {
        if( b[i] == 0)
        {
            continue;
        }
        att = b[i];
        for( int j = 1; j < i; ++ j)
        {
            if( b[j] <= att)
            {
                b[j] = 0;
                att -= b[j];
            }
            else
            {
                b[j] -= att;
                att = 0;
            }

            if( att == 0)
            {
                break;
            }
        }
    }
}

void awa_output()
{
    for( int i = 1; i <= 100000; ++ i)
    {
        ans += b[i];
    }
    printf( "%d\n", ans);
}

int main()
{
    freopen( "duel.in", "r", stdin);
    freopen( "duel.out", "w", stdout);

    awa_input();
    awa_solve();
    awa_output();

    return 0;
}
