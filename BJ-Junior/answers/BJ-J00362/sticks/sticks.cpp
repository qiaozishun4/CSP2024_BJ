#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long T,n,ans;
long long a[15]={6,2,5,5,4,5,6,3,7,6};
void dfs(long long p,long long sum,long long num)
{
    if(sum==0)
    {
        ans=min(ans,num);
        return ;
    }
    if(sum==1 || num>ans)
        return ;
    for(long long i=0;i<10;++i)
    {
        if(p==1 && i==0)
            continue;
        if(sum>=a[i])
            dfs(p+1,sum-a[i],num*10+i);
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        if(n%7==0)
        {
            for(int i=1;i<=n/7;++i)
                printf("8");
            printf("\n");
            continue;
        }
        if(n%7==1)
        {
            printf("10");
            for(int i=1;i<n/7;++i)
                printf("8");
            printf("\n");
            continue;
        }
        ans=1e9;
        dfs(1,n,0);
        if(ans==1e9)
            printf("-1\n");
        else
            printf("%lld\n",ans);
    }
    return 0;
}