#include<bits/stdc++.h>
using namespace std;
int ans[20000];
int c[20];
int x;
int dp(int m,int n)
{
    if(m==0&&n==0)return 1;
    if(m*7<n||n<2)return -1;
    if(m==1)
    {
        if(n<1||n>7)return -1;
        for(int i=0;i<=9;i++)
        {
            if(n==c[i])
            {
                ans[1]=i;
                return 1;
            }
        }
    }
    for(int i=0;i<=9;i++)
    {
        int j=dp(m-1,n-c[i]);
        if(j==1)
        {
            ans[m]=i;
            return 1;
        }
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    scanf("%d",&T);
    //printf("%d\n",T);
    c[0]=6;
    c[1]=2;
    c[2]=5;
    c[3]=0;
    c[4]=4;
    c[5]=0;
    c[6]=6;
    c[7]=3;
    c[8]=7;
    c[9]=0;
    while(T--)
    {
        //printf("t=%d\n",T);
        int n,y;
        scanf("%d",&n);
        //printf("n=%d\n",n);
        if(n>=2)
        {
            x=n/7;y=n-7*x;
            if(y)x++;
            for(int i=1;i<=9;i++)
            {
                int an;
                if(c[i])an=dp(x-1,n-c[i]);
                if(an==1)
                {
                    ans[x]=i;
                    break;
                }
            }
            for(int i=x;i>=1;i--)
            {
                printf("%d",ans[i]);
            }
        }
        else printf("%d",-1);
        printf("\n");
    }
}
