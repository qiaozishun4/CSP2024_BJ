#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int M=1e6+5;
int lst[N],nw[M];
long long a[N],dp[N],mx[N],q[N];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    int n;
    while(t--)
    {
        memset(nw,0,sizeof(nw));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++)
        {
            if(nw[a[i]])lst[i]=nw[a[i]];
            else lst[i]=0;
            nw[a[i]]=i;
        }
        q[0]=0;
        for(int i=1;i<=n;i++)
        {
            q[i]=q[i-1];
            if(i>1&&a[i]==a[i-1])q[i]+=a[i];
        }
        dp[0]=0;
        mx[0]=0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=0;
            if(lst[i])
            {
                if(lst[i]==i-1)dp[i]=mx[i-1]+a[i];
                else dp[i]=mx[lst[i]+1]+q[i-1]-q[lst[i]]+a[i];
            }
            mx[i]=max(mx[i-1],dp[i]);
        }
        printf("%lld\n",mx[n]);
    }
    return 0;
}
