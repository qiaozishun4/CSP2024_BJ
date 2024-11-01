#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,L,V;
int now,ans,cnt,flag,fl;
int d[100010],v[100010],a[100010];
int st[100010],ed[100010];
int p[100010],sum[1000010];
int f[100010],over[100010];
bool check()
{
    for(int i=1;i<=n;i++)
    {
        if(over[i])
        {
            fl=0;
            for(int j=1;j<=m;j++)
            {
                if(p[j]>=st[i]&&p[j]<=ed[i]&&!f[j])
                {
                    fl=1;
                    break;
                }
            }
            if(!fl)
            {
                return false;
            }
        }
    }
    return true;
}
int dfs(int i,int del)
{
    f[i]=1;
    if(!check())
    {
        f[i]=0;
        return del-1;
    }
    int b=0;
    for(int j=1;j<=m;j++)
    {
        if(!f[j])
        {
            b=max(b,dfs(j,del+1));
        }
    }
    f[i]=0;
    return b;
}
int cal(int v,int V,int a)
{
    double e=V*V;e-=v*v;
    e/=2*a;
    if(e>int(e))
    {
        return int(e)+1;
    }
    return int(e);
}
int cal1(int v,int V,int a)
{
    double e=V*V;e-=v*v;
    e/=2*a;
    return int(e);
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        memset(sum,0,sizeof(sum));
        memset(st,0,sizeof(st));
        memset(ed,0,sizeof(ed));
        memset(over,0,sizeof(over));
        scanf("%d%d%d%d",&n,&m,&L,&V);
        flag=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
            d[i]++;
            if(a[i]==0)
            {
                if(v[i]>V)
                {
                    st[i]=d[i]-1;
                    ed[i]=L+1;
                }
            }
            else if(a[i]>0)
            {
                if(v[i]<V)
                {
                    st[i]=min(L+1,d[i]+cal1(v[i],V,a[i]));
                    ed[i]=L+1;
                }
                else if(v[i]==V)
                {
                    st[i]=d[i];
                    ed[i]=L+1;
                }
                else if(v[i]>V)
                {
                    st[i]=d[i]-1;
                    ed[i]=L+1;
                }
            }
            else
            {
                if(v[i]>V)
                {
                    st[i]=d[i]-1;
                    ed[i]=min(L+1,d[i]+cal(v[i],V,a[i])-1);
                }
            }
            if(a[i]<0)
            {
                flag=0;
            }
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&p[i]);
            p[i]++;
        }
        now=1;
        for(int i=1;i<=L+1;i++)
        {
            sum[i]=sum[i-1];
            if(i==p[now])
            {
                now++;
                sum[i]++;
            }
        }
        ans=0;cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(sum[ed[i]]-sum[st[i]]!=0)
            {
                ans++;
                over[i]=1;
            }
        }
        if(ans==0)
        {
            cnt=m;
        }
        else if(flag)
        {
            cnt=m-1;
        }
        else
        {
            cnt=dfs(0,0);
        }
        printf("%d %d\n",ans,cnt);
    }
    return 0;
}
