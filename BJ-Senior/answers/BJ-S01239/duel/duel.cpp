#include <cstdio>
#include <algorithm>
using namespace std;

#define N (100000 + 10)

int n;
int a[N];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    sort(a + 1, a + n + 1);
    int cnt = 0;
    for (int i = 1, j = 2; i <= n; i++)
    {
        while (j <= n && a[j] == a[i])
            j++;
        if (j > n)
            break;
        j++;
        cnt++;
    }

    printf("%d\n", n - cnt);

    fclose(stdin);
    fclose(stdout);

    return 0;
}