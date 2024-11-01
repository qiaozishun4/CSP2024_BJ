#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int a[200010];
long long s[200010];
long long f[2010][2010];
long long dp[2010];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        memset(f,0,sizeof(f));
        memset(s,0,sizeof(s));
        memset(dp,0,sizeof(dp));
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            if(a[i]==a[i-1])s[i]+=a[i];
            s[i]+=s[i-1];
        }
        dp[1]=0;
        f[1][1]=0;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                f[i][j]=max(f[i][j],dp[j]+s[i]-s[j]);
                dp[i]=max(dp[i],f[i][j]);
            }
            f[i][i]=dp[i-1];
            for(int j=2;j<i;j++)
            {
                long long t=f[i-1][j];
                if(a[i]==a[j-1])t+=a[i];
                f[i][i]=max(f[i][i],t);
            }
            dp[i]=max(dp[i],f[i][i]);
        }
        cout<<dp[n]<<endl;
    }
}