#include<bits/stdc++.h>
using namespace std;

void pp(int n)
{
    while(n)
    {
        printf("8");
        n-=7;
    }
    printf("\n");
}

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        if((n%7)==0)
        {
            pp(n);
        }
        else if((n%7)==1)
        {
            if(n==1)
            {
                printf("-1\n");
                continue;
            }
            printf("10");
            n-=8;
            pp(n);
        }
        else if((n%7)==2)
        {
            printf("1");
            n-=2;
            pp(n);
        }
        else if((n%7)==3)
        {
            if(n==3)
            {
                printf("7\n");
                continue;
            }
            else if(n==10)
            {
                printf("22\n");
                continue;
            }
            printf("200");
            n-=17;
            pp(n);
        }
        else if((n%7)==4)
        {
            if(n==4)
            {
                printf("4\n");
                continue;
            }
            printf("20");
            n-=11;
            pp(n);
        }
        else if((n%7)==5)
        {
            printf("2");
            n-=5;
            pp(n);
        }
        else if((n%7)==6)
        {
            printf("6");
            n-=6;
            pp(n);
        }
    }
    return 0;
}
