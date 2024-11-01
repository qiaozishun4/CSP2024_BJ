#include <bits/stdc++.h>
using namespace std;
int n,T;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(n == 1) {printf("-1\n");continue;}
        if(n == 2) {printf("1\n");continue;}
        if(n == 3) {printf("7\n");continue;}
        if(n == 4) {printf("4\n");continue;}
        if(n == 5) {printf("2\n");continue;}
        if(n == 6) {printf("6\n");continue;}
        if(n == 7) {printf("8\n");continue;}
        if(n == 8) {printf("10\n");continue;}
        if(n == 9) {printf("18\n");continue;}
        if(n == 10) {printf("22\n");continue;}
        if(n == 11) {printf("20\n");continue;}
        if(n == 12) {printf("28\n");continue;}
        if(n == 13) {printf("68\n");continue;}
        if(n == 14) {printf("88\n");continue;}
        if(n%7 == 0)
        {
            while(n)
            {
                printf("8");
                n-=7;
            }
            printf("\n");
            continue;
        }
        if(n%7 == 1)
        {
            n-=8;
            printf("10");
            while(n){printf("8");n-=7;}
            printf("\n");
            continue;
        }
        int num8 = 0;
        while(n>2*7)
        {
            n-=7;
            num8++;
        }
        if(n == 8) {printf("10");}
        if(n == 9) {printf("18");}
        if(n == 10) {printf("22");}
        if(n == 11) {printf("20");}
        if(n == 12) {printf("28");}
        if(n == 13) {printf("68");}
        for(int i = 1;i<=num8;i++) printf("8");
        printf("\n");
    }
    return 0;
}
