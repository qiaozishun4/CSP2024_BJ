#include<stdio.h>
#include<string.h>
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int f=0;f<n;f++)
    {
        int k;
        scanf("%d",&k);
        if(k<=14)
        {
            if(k==1)printf("-1");
            if(k==2)printf("1");
            if(k==3)printf("7");
            if(k==4)printf("4");
            if(k==5)printf("2");
            if(k==6)printf("6");
            if(k==7)printf("8");
            if(f==n-1)continue;
            printf("\n");
            continue;
        }
        else
        {
            if(k%7==1)printf("10");
            if(k%7==2)printf("18");
            if(k%7==3)printf("22");
            if(k%7==4)printf("20");
            if(k%7==5)printf("28");
            if(k%7==6)printf("68");
            if(k%7==0)printf("8");
            for(int i=0;i<k/7-1;i++)printf("8");
            if(f==n-1)continue;
            printf("\n");
            continue;
        }
    }
    return 0;
}
