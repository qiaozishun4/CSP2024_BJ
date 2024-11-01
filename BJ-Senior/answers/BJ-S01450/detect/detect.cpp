#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,L,V,d[maxn],v[maxn],a[maxn],p[maxn];
int sum[maxn],W[maxn],cnt[maxn];
bool vis[maxn];
struct Q
{
    int p,l,r;
};
vector<Q> q;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&n,&m,&L,&V);
        for(int i=0;i<=L+2;++i)sum[i]=W[i]=cnt[i]=vis[i]=0;
        for(int i=1;i<=n;++i)scanf("%d%d%d",&d[i],&v[i],&a[i]);
        for(int i=1;i<=m;++i)
        {
            scanf("%d",&p[i]);
            W[p[i]]++;
        }
        for(int i=1;i<=L+4;++i)sum[i]=sum[i-1]+W[i-1];
        int ans=0;
        q.clear();
        for(int i=1;i<=n;++i)
        {
            if(v[i]<=V&&a[i]<=0)continue;
            if(v[i]>V&&a[i]>=0)
            {
                int tmp=sum[L+1]-sum[d[i]];
                if(tmp>0)
                {
                    ans++;
                    int f=lower_bound(p+1,p+m+1,d[i])-p;
                    q.push_back({i,f,m});
                }
                continue;
            }
            if(v[i]>V&&a[i]<0)
            {
                double t=((double)V-v[i])/a[i];
                double dis=v[i]*t+0.5*a[i]*t*t;
                int R=d[i]+dis;
                if(R>L)R=L;
                int tmp=sum[R+1]-sum[d[i]];
                if(tmp>0)
                {
                    ans++;
                    int f=lower_bound(p+1,p+m+1,d[i])-p;
                    int j=lower_bound(p+1,p+m+1,R)-p-1;
                    q.push_back({i,f,j});
                }
                continue;
            }
            if(v[i]<=V&&a[i]>0)
            {
                double t=((double)V-v[i])/a[i];
                double dis=v[i]*t+0.5*a[i]*t*t;
                int R=d[i]+dis+1;
                if(R>L)continue;
                int tmp=sum[L+1]-sum[R];
                if(tmp>0)
                {
                    ans++;
                    int f=lower_bound(p+1,p+m+1,R)-p;
                    q.push_back({i,f,m});
                }
                continue;
            }
        }
        int e=0,k=0;
        for(int i=1;i<=m;++i)
        {
            for(int j=0;j<q.size();++j)
            {
                if(q[j].l<=i&&i<=q[j].r)cnt[i]++;
            }
        }
        while(e<q.size())
        {
            int x=0,y=0;
            for(int i=1;i<=m;++i)if(cnt[i]>x)x=cnt[i],y=i;
            cnt[y]=0;
            for(int j=0;j<q.size();++j)
            {
                if(q[j].l<=y&&y<=q[j].r&&!vis[q[j].p])vis[q[j].p]=1,e++;
            }
            ++k;
            for(int i=1;i<=m;++i)cnt[i]=0;
            for(int i=1;i<=m;++i)
            {
                for(int j=0;j<q.size();++j)
                {
                    if(q[j].l<=i&&i<=q[j].r&&!vis[q[j].p])cnt[i]++;
                }
            }
        }
        printf("%d %d\n",ans,m-k);
    }
    return 0;
}
