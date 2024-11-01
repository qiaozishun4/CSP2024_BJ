#include <bits/stdc++.h>
using namespace std;
int t,n,yushu,shang;
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        yushu=n%7;
        shang=n/7;
        if(yushu==0)
        {
            if(shang==0)
            {
                printf("-1\n");
                continue;
            }
            for(int i = 1;i <= shang;++i)
            {
                printf("%d",8);
            }
            printf("\n");
            continue;
        }
        else if(yushu==1)
        {
            if(shang==0)
            {
                printf("-1\n");
                continue;
            }
            printf("10");
            for(int i = 1;i < shang;++i)
            {
                printf("8");
            }
            printf("\n");
        }
        else if(yushu==2)
        {
            printf("1");
            for(int i = 1;i <= shang;++i)
            {
                printf("8");
            }
            printf("\n");
        }//
        else if(yushu==3)
        {
            if(shang==0)
            {
                printf("7\n");
                continue;
            }
            printf("22");
            for(int i = 1;i < shang;++i)
            {
                printf("8");
            }
            printf("\n");
        }
        else if(yushu==4)
        {
            if(shang==0)
            {
                printf("4\n");
            }
            printf("20");
            for(int i = 1;i < shang;++i)
            {
                printf("8");
            }
            printf("\n");
        }
        else if(yushu==5)
        {
            printf("2");
            for(int i = 1;i <= shang;++i)
            {
                printf("8");
            }
            printf("\n");
        }
        else
        {
            printf("6");
            for(int i = 1;i <= shang;++i)
            {
                printf("8");
            }
            printf("\n");
        }
    }
    return 0;
}
/*
{6,2,5,4,6,3,7
 0 1 2 4 6 7 8

1  2 3 4 5 6 6 7
-1 1 7 4 2 0 6 8

25

26
2888

11
48/
*/
