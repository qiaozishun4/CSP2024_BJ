#include <cstdio>

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n / 7 - 1; ++i)
    {
        printf("8");
    }
    printf("%d", 8);
return 0;
}
