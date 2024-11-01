#include<bits/stdc++.h>
using namespace std;
int a[15] = {0, 6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main()
{
    freopen("stick.in", "r", stdin);
    freopen("stick.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        if(n < 2)
        {
            printf("-1\n");
            continue;
        }
        if(n == 2)printf("1\n");
        if(n == 3)printf("7\n");
        if(n == 4)printf("4\n");
        if(n == 6)printf("6\n");
        if(n == 7)printf("8\n");
        else if(n % 7 == 0)
        {
            for(int i = 1;i <= n / 7;i++)
            {
                printf("8");
            }
            printf("\n");
        }
        else if(n % 7 == 1)
        {
            printf("1");
            for(int i = 1;i <= n / 7;i++)
            {
                printf("8");
            }
            printf("0\n");
        }
    }
    return 0;
}
