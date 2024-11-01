#include<bits/stdc++.h>
using namespace std;
int main ()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    scanf("%d",&T);
    int n;
    while(T--)
    {
        scanf("%d",&n);
        if(n == 1)
        {
            printf("-1\n");
            continue;
        }
        int k = n / 7;
        if(n % 7 == 1)
        {
            k--;
            printf("10");
        }
        else if(n % 7 == 2)
        {
            printf("1");
        }
        else if(n % 7 == 3)
        {
            if(k >= 2)
            {
                k -= 2;
                printf("200");
            }
            else if(k == 1)
            {
                k--;
                printf("22");
            }
            else
            {
                printf("7");
            }
        }
        else if(n % 7 == 4)
        {
            if(k >= 1)
            {
                k--;
                printf("20");
            }
            else
            {
                printf("4");
            }
        }
        else if(n % 7 == 5)
        {
            printf("2");
        }
        else if(n % 7 == 6)
        {
            printf("6");
        }
        while(k--) printf("8");
        printf("\n");
    }
    return 0;
}
