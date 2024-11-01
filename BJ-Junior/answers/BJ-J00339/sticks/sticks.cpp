#include<bits/stdc++.h>
using namespace std;
int mg[10]={-1,-1,1,7,4,2,6,8};
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
        if(n<=7)
        {
            printf("%d\n",mg[n]);
            continue;
        }
        int mod=n%7;
        if(mod==1){printf("10");n-=8;}
        if(mod==2){printf("1");n-=2;}
        if(mod==3){printf("22");n-=10;}
        if(mod==4){printf("20");n-=11;}
        if(mod==5){printf("2");n-=5;}
        if(mod==6){printf("6");n-=6;}
        while(n)
        {
            printf("8");
            n-=7;
        }
        printf("\n");
    }
    return 0;
}
