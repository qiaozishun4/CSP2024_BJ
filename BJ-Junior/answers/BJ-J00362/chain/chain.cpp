#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long T,n,k,q,r,c,l[1003],s[1003][2003];
bool ans;
void dfs(long long x,long long f)
{
    if(ans)
        return ;
    if(x>r && f==c)
    {
        ans=true;
        return ;
    }
    for(int i=1;i<=l[x];++i)
        if(s[x][i]==f)
            for(int j=2;j<=k && i+j-1<=n;++j)
                dfs(x+1,s[x][i+j-1]);
}
int main()
{
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&n,&k,&q);
        for(int i=1;i<=n;++i)
        {
            scanf("%lld",&l[i]);
            for(int j=1;j<=l[i];++j)
                scanf("%lld",&s[i][j]);
        }
        while(q--)
        {
            ans=false;
            scanf("%lld%lld",&r,&c);
            dfs(1,1);
            if(ans)
                printf("1\n");
            else
                printf("0\n");
        }
    }
    return 0;
}