#include<bits/stdc++.h>
using namespace std;
int a[15];
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long t,n,i;
    bool f,e;
    scanf("%d",&t);
    a[0]=6;
    a[1]=2;
    a[2]=5;
    a[3]=5;
    a[4]=4;
    a[5]=5;
    a[6]=6;
    a[7]=3;
    a[8]=7;
    a[9]=6;
    while(t--)
    {
        e=false;
        scanf("%d",&n);
        f=false;
        if(n<2)
        {
            printf("%d",-1);
            if(t!=0)printf("\n");
            continue;
        }
        long long ans=0;
        for(i=1;!f;i++)
        {
            int g=i;
            while(g!=0)
            {
                int y=g%10;
                ans+=a[y];
                g/=10;
            }
            if(ans==n)f=true;
            else ans=0;
        }
        printf("%d",i-1);
        if(t!=0)printf("\n");
    }
    return 0;
}

