#include <bits/stdc++.h>
using namespace std;

inline int read()
{
    register int x = 0, f = 1;
    register char c = getchar();
    while(c > '9' || c < '0')
    {
        if(c == '-')f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}

//14:37过掉

int t[100010], a[100010];

signed main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n = read();
    for(int i = 1;i <= n;i++)
    {
        a[i] = read();
        t[a[i]]++;
    }
    int ans = 0;
    for(int i = 1;i <= n;i++)ans = max(ans, t[a[i]]);
    cout << ans;
    return 0;
}