#include<bits/stdc++.h>
using namespace std;
long long t,n,a[200010],sum,c[1000010];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
        for(int i = 1;i <= n;i++)
        {
            if(c[a[i]]) sum += a[i];
            c[a[i]] += 1;
        }
        printf("%lld\n",sum);
        sum = 0;
        memset(c,0,sizeof(c));
    }
    return 0;
}
