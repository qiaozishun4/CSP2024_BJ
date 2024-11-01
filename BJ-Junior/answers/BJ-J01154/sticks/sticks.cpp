#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int t, n;

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    scanf("%d", &t);
    while (t--)
    {
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
        if (n % 7 == 0)
        {
            for (int i = 1; i <= n / 7; i++)
                printf("8");
            printf("\n");
            continue;
        }
        if (n % 7 == 1)
        {
            printf("10");
            n -= 8;
            for (int i = 1; i <= n / 7; i++)
                printf("8");
            printf("\n");
            continue;
        }
        if (n % 7 == 2)
        {
            printf("1");
            n -= 2;
            for (int i = 1; i <= n / 7; i++)
                printf("8");
            printf("\n");
            continue;
        }
        if (n % 7 == 3)
        {
            printf("22");
            n -= 10;
            for (int i = 1; i <= n / 7; i++)
                printf("8");
            printf("\n");
            continue;
        }
        if (n % 7 == 4)
        {
            printf("20");
            n -= 11;
            for (int i = 1; i <= n / 7; i++)
                printf("8");
            printf("\n");
            continue;
        }
        if (n % 7 == 5)
        {
            printf("2");
            n -= 5;
            for (int i = 1; i <= n / 7; i++)
                printf("8");
            printf("\n");
            continue;
        }
        if (n % 7 == 6)
        {
            printf("6");
            n -= 6;
            for (int i = 1; i <= n / 7; i++)
                printf("8");
            printf("\n");
            continue;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
0: 6
1: 2
2: 5
3: 5
4: 4
5: 5
6: 6
7: 3
8: 7
9: 6
*/
