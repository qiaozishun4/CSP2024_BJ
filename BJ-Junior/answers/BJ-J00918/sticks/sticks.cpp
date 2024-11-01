#include<cstdio>
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
        if(n==1) printf("-1\n");
        else if(n==2) printf("1\n");
        else if(n==3) printf("7\n");
        else if(n==4) printf("4\n");
        else if(n==5) printf("2\n");
        else if(n==6) printf("6\n");
        else if(n==7) printf("8\n");
        else if(n==8) printf("10\n");
        else if(n==9) printf("18\n");
        else if(n==10) printf("22\n");
        else if(n==11) printf("20\n");
        else if(n==12) printf("28\n");
        else if(n==13) printf("68\n");
        else if(n==14) printf("88\n");
        else
        {
            if(n%7==0)
            {
                printf("888");
                int k=n/7-3;
                for(int j=1;j<=k;j++) printf("8");
                puts("");
            }
            if(n%7==1)
            {
                printf("108");
                int k=n/7-2;
                for(int j=1;j<=k;j++) printf("8");
                puts("");
            }
            if(n%7==2)
            {
                printf("188");
                int k=n/7-2;
                for(int j=1;j<=k;j++) printf("8");
                puts("");
            }
            if(n%7==3)
            {
                printf("200");
                int k=n/7-2;
                for(int j=1;j<=k;j++) printf("8");
                puts("");
            }
            if(n%7==4)
            {
                printf("208");
                int k=n/7-2;
                for(int j=1;j<=k;j++) printf("8");
                puts("");
            }
            if(n%7==5)
            {
                printf("288");
                int k=n/7-2;
                for(int j=1;j<=k;j++) printf("8");
                puts("");
            }
            if(n%7==6)
            {
                printf("688");
                int k=n/7-2;
                for(int j=1;j<=k;j++) printf("8");
                puts("");
            }
        }
    }
    return 0;
}