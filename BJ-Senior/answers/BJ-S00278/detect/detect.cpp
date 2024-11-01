#include<bits/stdc++.h>
using namespace std;
int d[100005],a[100005],v[100005];
int dis[100005];
int l[100005],r[100005],xs;
bool x[25],vis[100005];
int n,m,L,V;
int ans=1e9;
void dfs(int now)
{
    if(now==m+1)
    {
        for(int i=1;i<=n;i++)
        {
            bool op=0;
            if(!vis[i])op=1;
            else
            {
                for(int j=1;j<=m;j++)
                {
                    if(x[j]&&l[i]<=dis[j]&&r[i]>=dis[j])
                    {
                        op=1;
                        break;
                    }
                }
            }
            if(!op)
            {
                return;
            }
        }
        ans=min(ans,xs);
        return;
    }
    xs++;
    x[now]=1;
    dfs(now+1);
    xs--;
    x[now]=0;
    dfs(now+1);
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&n,&m,&L,&V);
        int cnt=0,maxn=0;
        int op=0;
        for(int i=1;i<=n;i++)
        {
            vis[i]=0;
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
            if(a[i]<0)op=1;
            if(a[i]==0)
            {
                r[i]=L+1;
                if(v[i]>V)
                {
                    l[i]=d[i];
                }else l[i]=L+1;
                continue;
            }
            int minn=(V*V-v[i]*v[i])/(2*a[i])+1,min1=(V*V-v[i]*v[i]+2*a[i]-1)/(2*a[i])-1;
            minn+=d[i];min1+=d[i];
            if(minn<=L&&a[i]>0)
            {
                minn=max(minn,d[i]);
                maxn=max(maxn,minn);
                l[i]=minn;
                r[i]=L+1;
            }
            else if(minn>=d[i]&&a[i]<0)
            {
                min1=min(min1,L);
                l[i]=d[i];r[i]=min1;
            }else{l[i]=L+1;r[i]=L+1;}
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&dis[i]);
            if(op)
            {
                for(int j=1;j<=n;j++)
                {
                    if(l[j]<=dis[i]&&r[j]>=dis[i])
                    {
                        vis[j]=1;
                        //printf("%d %d %d\n",dis[i],l[j],r[j]);
                    }
                }
            }
        }
        if(!op)
        {
            for(int i=1;i<=n;i++)
            {
                if(l[i]<=dis[m])cnt++;
            }
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                if(vis[i])cnt++;
                if(l[i]==L+1&&r[i]==L+1)
                {
                    l[i]=1;
                }
            }
        }
        printf("%d ",cnt);
        if(!op)
        {
            if(cnt==0)printf("%d\n",m);
            else printf("%d\n",m-1);
            continue;
        }
        else if(n<=20&&m<=20)
        {
            ans=1e9;
            dfs(1);
            printf("%d\n",m-ans);
        }
        else
        {
            printf("0\n");
        }
    }
}
