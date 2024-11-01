#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 2e5 + 5;
int t , n , a[maxn] , c[maxn] , tmp = 0 , ans = -1e9;

void dfs(int x)
{
    if (x > n)
    {
        ans = max(ans , tmp);
        return;
    }
    c[x] = 1;
    int y = 0;
    for (int i = x - 1; i >= 1; i--)
    {
        if (c[x] == c[i])
        {
            if (a[x] == a[i]) y = a[x];
            break;
        }
    }
    tmp += y;
    dfs(x + 1);
    tmp -= y;
    c[x] = 2;
    y = 0;
    for (int i = x - 1; i >= 1; i--)
    {
        if (c[x] == c[i])
        {
            if (a[x] == a[i]) y = a[x];
            break;
        }
    }
    tmp += y;
    dfs(x + 1);
    tmp -= y;
    c[x] = 0;
}

int main()
{
    freopen("color.in" , "r" , stdin);
    freopen("color.out" , "w" , stdout);
    scanf("%d" , &t);
    while (t--)
    {
        memset(c , 0 , sizeof(c));
        ans = -1e9;
        tmp = 0;
        scanf("%d" , &n);
        for (int i = 1; i <= n; i++) scanf("%d" , &a[i]);
        dfs(1);
        printf("%d\n" , ans);
    }

    return 0;
}
