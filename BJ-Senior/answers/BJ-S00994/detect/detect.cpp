#include <bits/stdc++.h>
using namespace std;

int T, n, m, L, V, d[100010], v[100010], a[100010], p[100010];
int flag[100010], flagi = 1;
bool flagm;
int cnt, ans, osi, osc;
double os[2][100010];
bool osf[100010];

void awa_input()
{
    scanf( "%d%d%d%d", &n ,&m, &L, &V);
    for( int i = 1; i <= n; ++ i)
    {
        scanf( "%d%d%d", &d[i], &v[i], &a[i]);
    }
    for( int i = 1; i <= m; ++ i)
    {
        scanf( "%d", &p[i]);
        flag[i] = false;
    }
    sort( p + 1, p + m + 1);
}
int awa_find_P( int d)
{
    for( int i = 1; i <= m; ++ i)
    {
        if( p[i] >= d)
        {
            return i;
        }
    }
    return -1;
}
void awa_solve()
{
    for( int i = 1; i <= n; ++ i)
    {
        int dis, v1;
        if( a[i] <= 0)
        {
            int q = awa_find_P(d[i]);
            if( q == -1)
            {
                continue;
            }
            dis = p[q] - d[i];
            v1 = v[i]*v[i] + 2 * a[i] * dis;
            if( v1 > V*V)
            {
                ++ cnt;
                flag[q] = true;
            }
        }
        else
        {
            if( p[m] >= d[i])
            {
                dis = p[m] - d[i];
                v1 = v[i]*v[i] + 2 * a[i] * dis;
                if( v1 > V*V)
                {
                    ++ cnt;
                    flag[m] = true;
                }
            }
        }
    }
}

void awa_output()
{
    for( int i = 1; i <= m; ++ i)
    {
        ans += flag[i];
    }
    ans = m - ans;
    printf( "%d %d\n", cnt, ans);
}

int main()
{
    freopen( "detect.in", "r", stdin);
    freopen( "detect.out", "w", stdout);

    scanf( "%d", &T);
    for( int k = 1; k <= T; ++ k)
    {
        cnt = 0;
        ans = 0;
        awa_input();
        awa_solve();
        awa_output();
    }


    return 0;
}
