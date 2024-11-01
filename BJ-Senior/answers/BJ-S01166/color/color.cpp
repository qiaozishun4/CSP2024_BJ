#include <bits/stdc++.h>
using namespace std;
int const N=2e5+3;
typedef long long ll;
int n,a[N];
bool c[N];
ll ans=0;
inline void dfs(int step)
{
    if(step==n+1)
    {
        ll sum=0;
        int lst[2]={0,0};
        for(int i=1;i<=n;++i)
        {
            if(a[lst[c[i]]]==a[i]) sum+=a[i];
            lst[c[i]]=i;
        }
        ans=max(ans,sum);
        return ;
    }
    c[step]=1;
    dfs(step+1);
    c[step]=0;
    dfs(step+1);
}
inline void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    ans=0;
    dfs(1);
    printf("%lld\n",ans);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}