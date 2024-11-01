#include <bits/stdc++.h>
using namespace std;

int n, t;

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d", &t);
    for(int i = 0;i<t;i++)
    {
        scanf("%d", &n);
        if(n % 7 == 0)
        {
            int ns = n/7;
            for(int i = 0;i<ns;i++)
            {
                printf("8");
            }
            printf("\n");
        }
        else if(n % 7 == 1)
        {
            int Es = n/7-1;
            printf("27");
            for(int i = 0;i<Es;i++)
            {
                printf("8");
            }
            printf("\n");
        }
        else
            printf("-1\n");
    }
    return 0;
}
