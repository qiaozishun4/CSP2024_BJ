#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
long long n,cnt,a[100005],b[100005],c[100005],maxn,p,ans=0;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
        ++b[a[i]];
        maxn=max(maxn,a[i]);
    }
    for(long long i=1;i<=maxn;++i)
    {
        while(b[i]>0)
        {
            a[++cnt]=i;
            --b[i];
        }
    }
    for(int i=1;i<=n;++i)
    {
        p=lower_bound(c+1,c+ans+1,a[i])-c;
        if(p-1>=1 && p-1<=ans && c[p-1]<a[i])
        {
            c[p-1]=a[i];
        }
        else
        {
            c[++ans]=a[i];
        }
    }
    printf("%lld\n",ans);
    return 0;
}