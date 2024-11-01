#include<cstdio>
#include<algorithm>
const int N=100010;
int a[N];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    std::sort(a+1,a+n+1);
    int ans=n;
    for(int i=n,j=n-1;i>=1;--i)
    {
        while(j>=1&&a[j]>=a[i]) --j;
        if(j>=1) --ans,--j;
    }
    printf("%d\n",ans);
    return 0;
}
