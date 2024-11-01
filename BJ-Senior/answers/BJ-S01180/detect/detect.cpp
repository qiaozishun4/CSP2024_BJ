#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int t,n,m,L,V,d[N],v[N],a[N],p[N];
struct node
{
    int l,r;
}sig[N];
bool cmp(node x,node y)
{
    if(x.r==y.r) return x.l<y.l;
    return x.r<y.r;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&n,&m,&L,&V);
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
        for(int i=1;i<=m;i++)
            scanf("%d",&p[i]);
        int ans=0,len=0,dlt=0;
        for(int i=1;i<=n;i++)
        {
            int cnt;
            if(a[i]==0)
            {
                cnt=lower_bound(p+1,p+1+m,d[i])-p;
                if(v[i]>V&&m-cnt+1>0)
                {
                    ans++;
                    sig[++len].l=cnt,sig[len].r=m;
                }
                continue;
            }
            if(v[i]<=V&&a[i]<0) continue;
            int x=(V*V-v[i]*v[i])/(2*a[i]);
            if(a[i]>0)
            {
                if(v[i]<=V) cnt=upper_bound(p+1,p+1+m,x+d[i])-p;
                else cnt=lower_bound(p+1,p+1+m,d[i])-p;
                if(m-cnt+1>0)
                {
                    ans++;
                    sig[++len].l=cnt,sig[len].r=m;
                }
            }
            else
            {
                if(abs(V*V-v[i]*v[i])%abs(2*a[i])==0) cnt=lower_bound(p+1,p+1+m,x+d[i])-p;
                else cnt=upper_bound(p+1,p+1+m,x+d[i])-p;
                cnt--;
                int le=lower_bound(p+1,p+1+m,d[i])-p;
                if(cnt>=le)
                {
                    ans++;
                    sig[++len].l=le,sig[len].r=cnt;
                }
            }
        }
        sort(sig+1,sig+1+len,cmp);
        for(int i=1;i<=len;i++)
        {
            int en=sig[i].r;
            dlt++;
            int j=i+1;
            for(;j<=len;j++)
                if(sig[j].l>en)
                    break;
            i=j-1;

        }
        printf("%d %d\n",ans,m-dlt);
    }
    return 0;
}