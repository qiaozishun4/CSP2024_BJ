#include<bits/stdc++.h>
using namespace std;
int T;
int n,cnt;
int f[100001];
int val[10]={6,2,5,5,4,5,6,3,7,6};
int ans[22]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688,888};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(n==1)
        {
            printf("-1\n");
            continue;
        }
        cnt=n/7;
        if(n%7!=0)
        {
            n=n%21;
            if(n>7&&n<14)
            {
                cnt--;
            }
            else if(n>14&&n<21)
            {
                cnt-=2;
            }
            if(n)printf("%d",ans[n]);
            for(int i=1;i<=cnt;i++)
                printf("8");
            printf("\n");
        }
        else
        {
            for(int i=1;i<=cnt;i++)
                printf("8");
            printf("\n");
        }
    }
    return 0;
}
