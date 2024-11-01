#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int T,n;
long long a[MAXN];
long long dfs(int pos,long long lstb,long long lstr)
{
    if(pos==n)
    {
        return max((a[pos]==lstb?a[pos]:0),(a[pos]==lstr?a[pos]:0));
    }
    long long ret1=dfs(pos+1,a[pos],lstr)+(a[pos]==lstb?a[pos]:0);
    long long ret2=dfs(pos+1,lstr,a[pos])+(a[pos]==lstr?a[pos]:0);
    return max(ret1,ret2);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
        }
        printf("%lld\n",dfs(1,0,0));
    }
    return 0;
}
