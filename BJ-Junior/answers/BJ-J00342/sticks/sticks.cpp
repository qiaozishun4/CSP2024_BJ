#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e7 + 10;

int dig[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

bool Check(int pos, int x)
{
    int ans = 0;
    while (x)
    {
        ans += dig[x % 10];
        x /= 10;
    }
    return (ans == pos);
}

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int tst = 1; tst <= T; tst++)
    {
        int n;
        scanf("%d", &n);
        if (n == 1)
        {
            printf("-1\n");
            continue;
        }
        if (!(n % 7))
        {
            if (n <= 49)
            {
                int x = n / 7;
                for (int i = 1; i <= x; i++)
                    printf("8");
                printf("\n");
            }
            else printf("-1\n");
            continue;
        }
        if (!((n - 1) % 7))
        {
            if (n <= 43)
            {
                printf("10");
                int x = (n - 1) / 7 - 1;
                for (int i = 1; i <= x; i++)
                    printf("8");
                printf("\n");
            }
            else printf("-1\n");
            continue;
        }
        int ans = 0;
        bool f = false;
        for (int i = 1; i <= N; i++)
            if (Check(n, i))
            {
                f = true;
                ans = i;
                break;
            }
        if (f) printf("%d\n", ans);
        else printf("-1\n");
    }
    return 0;
}
