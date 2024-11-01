#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        if (n == 1)
        {
            printf("-1\n");
            continue;
        }
        if (n == 2)
        {
            printf("1\n");
            continue;
        }
        if (n == 3)
        {
            printf("7\n");
            continue;
        }
        if (n == 4)
        {
            printf("4\n");
            continue;
        }
        if (n == 5)
        {
            printf("2\n");
            continue;
        }
        if (n == 6)
        {
            printf("6\n");
            continue;
        }
        if (n == 7)
        {
            printf("8\n");
        }
        if (n % 7 == 0)
        {
            for (int i = 1; i <= n / 7; i++)
            {
                printf("8");
            }
        }
        if (n % 7 == 1)
        {
            printf("10");
            for (int i = 1; i <= n / 7 - 1; i++)
            {
                printf("8");
            }
        }
        if (n % 7 == 2)
        {
            printf("1");
            for (int i = 1; i <= n / 7; i++)
            {
                printf("8");
            }
        }
        if (n % 7 == 3)
        {
            printf("22");
            for (int i = 1; i <= n / 7 - 1; i++)
            {
                printf("8");
            }
        }
        if (n % 7 == 4)
        {
            printf("20");
            for (int i = 1; i <= n / 7 - 1; i++)
            {
                printf("8");
            }
        }
        if (n % 7 == 5)
        {
            printf("2");
            for (int i = 1; i <= n / 7; i++)
            {
                printf("8");
            }
        }
        if (n % 7 == 6)
        {
            printf("6");
            for (int i = 1; i <= n / 7; i++)
            {
                printf("8");
            }
        }
        printf("\n");
    }
    return 0;
}
