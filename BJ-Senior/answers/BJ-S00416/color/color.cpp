#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, ans = 0;
int a[100], c[100], pt[100];

void dfs(int s)
{
    if (s > n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i - 1; j > 0; j--)
            {
                if (c[j] == c[i] && a[i] == a[j])
                {
                    pt[i] = a[i];
                    break;
                }
            }
        }
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += pt[i];
        }
        ans = max(ans, sum);
        return;
    }
    c[s + 1] = 0;
    dfs(s + 1);
    c[s + 1] = 1;
    dfs(s + 1);
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        ans = 0;
        memset(a, 0, sizeof(a));
        memset(c, 0, sizeof(c));
        memset(pt, 0, sizeof(pt));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        dfs(0);
        cout << ans << endl;
    }
    return 0;
}