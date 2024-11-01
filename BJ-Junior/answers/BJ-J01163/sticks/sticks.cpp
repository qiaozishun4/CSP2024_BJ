#include<bits/stdc++.h>
using namespace std;
int need[]={6,2,5,5,4,5,6,3,7,6};
int cntneed(int n)
{
    int ret=0;
    while(n)
    {
        int x=n%10;
        ret+=need[x];
        n/=10;
    }
    return ret;
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int wei=ceil(1.0*n/2),maxn=1;
        while(wei--)maxn*=10;
        bool flag=1;
        for(int i=0;i<=maxn;i++)
        {
            if(cntneed(i)==n)
            {
                printf("%d\n",i);
                flag=0;
                break;
            }
        }
        if(flag)printf("%d\n",-1);
    }
    return 0;
}
