#include<bits/stdc++.h>
using namespace std;
int n,T;
int a[1005];
int l0,l1;
long long ans;
long long tans;
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {

        tans=0;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
            scanf("%d",&a[i]);
        for(int k=0;k<(1<<n);++k)
        {
            ans=0;
            l0=l1=-1;
            for(int i=0;i<n;++i)
            {
                if(k&(1<<i))
                {
                    if(l1!=-1)
                    {
                        if(a[l1]==a[i])
                            ans+=a[i];
                    }
                    l1=i;
                }
                else
                {
                    if(l0!=-1)
                    {
                        if(a[l0]==a[i])
                            ans+=a[i];
                    }
                    l0=i;
                }
            }
            tans=max(tans,ans);
        }
        printf("%lld\n",tans);
    }
    return 0;
}
