#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
long long T,n,a[200004],ans;
bool c[200004];
void dfs(long long p,long long cnt)
{
    if(cnt+(n-p)<ans)
        return ;
    if(p>n)
    {
        ans=max(ans,cnt);
        return ;
    }
    c[p]=false;
    bool flag=false;
    for(int i=p-1;i>=1;--i)
        if(c[i]==c[p] && a[i]==a[p])
        {
            dfs(p+1,cnt+a[p]);
            break;
        }
    if(!flag)
        dfs(p+1,cnt);
    flag=false;
    c[p]=true;
    for(int i=p-1;i>=1;--i)
        if(c[i]==c[p] && a[i]==a[p])
        {
            dfs(p+1,cnt+a[p]);
            break;
        }
    if(!flag)
        dfs(p+1,cnt);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%lld",&a[i]);
            c[i]=false;
        }
        ans=0;
        dfs(1,0);
        printf("%lld\n",ans);
    }
    return 0;
}