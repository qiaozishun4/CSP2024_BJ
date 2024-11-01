#include<iostream>
#include<cstring>
using namespace std;
#define maxn (int)2e5
#define maxa (int)1e6
long long t,n;
long long a[maxn+10],sum[maxn+10],f[maxn+10],lst[maxa+10];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        memset(lst,0,sizeof lst);
        memset(f,0,sizeof f);
        memset(sum,0,sizeof sum);
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            f[i]=f[i-1];
            if(lst[a[i]])f[i]=max(f[i],f[lst[a[i]]+1]+a[i]+sum[i-1]-sum[lst[a[i]]+1]);
            ans=max(ans,f[i]);
            lst[a[i]]=i;
            sum[i]=sum[i-1]+(a[i]==a[i-1])*a[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
