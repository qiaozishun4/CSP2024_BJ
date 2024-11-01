#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;

int t,n;
int f[100];
int d[8]={0,0,1,7,4,2,0,8};

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&t);
    for(int i=0;i<=50;i++)
        f[i]=1e9;
    f[0]=-1;
    f[1]=-1;
    f[2]=1;
    f[3]=7;
    f[4]=4;
    f[5]=2;
    f[6]=6;
    f[7]=8;
    for(int i=2;i<=50;i++)
    {
        for(int j=2;j<=7;j++)
        {
            if(i+j<50)
                f[i+j]=min(f[i+j],f[i]*10+d[j]);
        }
    }
    while(t--)
    {
        scanf("%d",&n);
        if(n<=30)
        {
            printf("%d\n",f[n]);
        }
        else
        {
            int cnt=0;
            while(n>=28)
            {
                cnt++;
                n-=7;
            }
            printf("%d",f[n]);
            for(int i=1;i<=cnt;i++)
                printf("8");
        }
    }
    return 0 ;
}