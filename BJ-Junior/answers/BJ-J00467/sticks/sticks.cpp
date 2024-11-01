#include <bits/stdc++.h>
using namespace std;
int t,n,a[10] = {6,2,5,5,4,5,6,3,7,6};
int func(int x)
{
    for (int i = 0; i <= 9; i++)
        if (a[i] == x) return i;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        if (n < 2)
        {
            printf("-1");
            continue;
        }
        if (n == 6)
        {
            printf("6");
            continue;
        }
        int k = n;
        for (int i = 1; i < ceil(n / 7.0); i++)
        {
            int j = (i == 1) ? 1 : 0;
            while (a[j] < k % 7) j++;
            printf("%d", j);
            k -= a[j];
        }
        printf("%d\n", func(k));
    }
    return 0;
}
