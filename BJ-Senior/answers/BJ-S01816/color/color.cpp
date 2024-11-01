#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n,a[200005];
long long ans;
void dfs(int step,int lr,int lb,long long sum)
{
    if (step > n)
    {
        ans = max(ans,sum);
        return ;
    }
    if (a[lr] == a[step]) dfs(step + 1,step,lb,sum + a[step] * 1ll);
    else dfs(step + 1,step,lb,sum);
    if (a[lb] == a[step]) dfs(step + 1,lr,step,sum + a[step] * 1ll);
    else dfs(step + 1,lr,step,sum);
}
void solve()
{
    scanf("%d",&n);
    ans = -1;
    for (int i = 1;i <= n;i++) scanf("%d",a + i);
    dfs(1,0,0,0ll);
    printf("%d\n",ans);
}

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}
