#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5,M=1e6+5;
int T,n,q=0,ans=0,maxn=0,a[N],t[M],f[N],c[N];
void dfs(int now)
{
    if(now==n)
    {
        int cnt=0;
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)
        {
            bool flag=1;
            for(int j=1;j<i;j++)
            {
               if(f[j]==f[i]) flag=0;
            }
            if(flag==1) c[i]=0;
            else
            {
                for(int j=i-1;j>=1;j--)
                {
                    if(f[j]==f[i])
                    {
                        if(a[i]!=a[j]) c[i]=0;
                        else c[i]=a[i];
                        break;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++) cnt+=c[i];
        ans=max(ans,cnt);
        return;
    }
    f[now+1]=1;
    dfs(now+1);
    f[now+1]=0;
    f[now+1]=2;
    dfs(now+1);
    f[now+1]=0;
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--)
    {
        memset(t,0,sizeof(t));
        memset(f,0,sizeof(f));
        memset(c,0,sizeof(c));
        q=0;
        maxn=0;
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            maxn=max(maxn,a[i]);
            t[a[i]]++;
        }
        for(int i=1;i<=maxn;i++)
        {
            if(t[i]!=1) q=1;
        }
        if(q==0)
        {
            cout<<"0\n";
            continue;
        }
        dfs(0);
        cout<<ans<<"\n";
    }
    return 0;
}
