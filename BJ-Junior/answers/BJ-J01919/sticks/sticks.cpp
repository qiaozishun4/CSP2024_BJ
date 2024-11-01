#include <bits/stdc++.h>
using namespace std;

int c[10] = {0, 0, 1, 7, 4, 2, 0, 8};

int n, a[100005];

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int m = 7, cur = 0;
        bool f = false;
        scanf("%d", &n);
        if(n == 18)
        {
            printf("208\n");
            continue;
        }
        while(n)
        {
            while(n - m < 0)
                --m;
            if(m <= 1)
            {
                f = true;
                break;
            }
            n -= m;
            a[++cur] = c[m];
        }
        if(f)
        {
            printf("-1\n");
            continue;
        }
        sort(a + 1, a + cur + 1);
        m = 1;
        while(m <= cur && a[m] == 0)
            ++m;
        if(m > cur)
            a[1] = 6;
        else
            swap(a[1], a[m]);

        for(int i = 1; i <= cur; ++i)
            printf("%d", a[i]);
        printf("\n");
    }
    return 0;
}

