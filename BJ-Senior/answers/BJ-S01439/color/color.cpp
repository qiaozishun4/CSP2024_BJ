
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
const int maxm=1e6+5;
int t,n,cnt;
int a[maxn];
int vis[maxm];
long long dp[maxn];
struct node{int l,r,p;}q[maxn];
int read()
{
    char c=getchar();
    int f=1,k=0;
    while(c<'0' || c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0' && c<='9')
    {
        k=k*10+(c-48);
        c=getchar();
    }
    return k*f;
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    t=read();
    while(t--)
    {
        cnt=0;
        long long ans=0;
        n=read();
        for(int i=1;i<=n;i++)
            vis[a[i]]=0;
        for(int i=1;i<=n;i++)
        {
            a[i]=read();
            if(vis[a[i]])
                q[++cnt].l=vis[a[i]]+1,q[cnt].r=i-1,q[cnt].p=a[i];
            vis[a[i]]=i;
        }
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            dp[i]=0;
            for(int j=1;j<i;j++)
                for(int k=1;k<=cnt;k++)
                    if(q[k].l>j && q[k].r<=i)
                        dp[i]=max(dp[i],dp[j]+q[k].p);
        }
        cout<<dp[n]<<"\n";
    }
    return 0;
}
