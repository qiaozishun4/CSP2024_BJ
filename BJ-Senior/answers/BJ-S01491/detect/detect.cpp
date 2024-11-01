#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
typedef long long ll;
int L,V,n,m;
int T;
int d[maxn],v[maxn],a[maxn],p[maxn];
int l1,r1;
struct point {
    int xx,yy;//[xx,yy];
};
ll ans1,ans2;
queue<point> q[1000005];//car
int t[1000005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        ans1=ans2=0;
        //printf("****\n");
        scanf("%d%d%d%d",&n,&m,&L,&V);
        for(int i=1;i<=n;++i)
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
        for(int i=1;i<=m;++i)
        {
            scanf("%d",&p[i]);
            ++t[p[i]];
        }
        int flag=-1;

        for(int i=0;i<=L;++i)
        {
            if(t[i]>0)
                flag=i;
            t[i]=flag;
        }

        for(int i=1;i<=n;++i)
        {
            if(a[i]>0)
            {
                if(v[i]>V)
                    l1=d[i];
                else
                    l1=(V*V-v[i]*v[i])/(2*a[i])+1+d[i];
                r1=L;

                if(l1>L)
                {
                    continue;
                }
                //printf("i=%d,l1=%d,r1=%d\n",i,l1,r1);
                if(t[r1]<l1)
                    continue;
                point r={l1,r1};
                q[r1].push(r);
            }
            if(a[i]==0)
            {
                if(v[i]<=V)
                    continue;
                l1=d[i];
                r1=L;
                //printf("i=%d,l1=%d,r1=%d\n",i,l1,r1);
                if(t[r1]<l1)
                    continue;
                point r={l1,r1};
                q[r1].push(r);
            }
            if(a[i]<0)
            {
                if(v[i]<=V)
                    continue;
                r1=(V*V-v[i]*v[i])/(2*a[i])+(bool)((V*V-v[i]*v[i])%(2*a[i]))+d[i]-1;
                r1=min(L,r1);
                l1=d[i];
                //printf("i=%d,l1=%d,r1=%d\n",i,l1,r1);
                if(t[r1]<l1)
                    continue;
                point r={l1,r1};
                q[r1].push(r);
            }
        }
        flag=-1;
        for(int i=0;i<=L;++i)
        {
            if(q[i].empty())
                continue;
            if(flag==-1)
            {
                flag=t[i];
                ++ans2;
            }
            while(!q[i].empty())
            {

                if(flag<q[i].front().xx)
                {
                    ++ans2;
                    flag=t[i];
                }
                ++ans1;
                q[i].pop();
            }
        }
        printf("%lld %lld\n",ans1,(ll)m-ans2);
        //
        for(int i=0;i<=L;++i)
        {
            while(!q[i].empty())
                q[i].pop();
            t[i]=0;
        }

    }
    return 0;
}
