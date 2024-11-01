#include <bits/stdc++.h>
#define int long long
using namespace std;
int read ()
{
    int ret = 0, f = 1;
    char c = getchar ();
    while (! (c >= '0' && c <= '9')) 
    {
        if (c == '-') f = -1;
        c = getchar (); 
    }
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar ();
    }
    return f * ret;
}
const int N = 1e5 + 5;
int n, a[N], ans;
signed main ()
{
    freopen ("duel.in", "r", stdin);
    freopen ("duel.out", "w", stdout);
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    sort (a + 1, a + n + 1);
    int lst = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] != a[i - 1])
        {
            ans ++;
            lst = i;
        }
        else 
        {
            if (ans + 1 < lst)
            {
                ans ++;
            }
        }
    }
    cout << n - ans;
    return 0;
}