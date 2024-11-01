#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 5008
#define rep(i,a,b) for(register int i(a);i<(b);++i)
#define sq(x) (1.0*(x)*(x))
using namespace std;
int d[N],v[N],a[N],p[N],cnt[N],tot,n,m;
int T,l;
double f,s;
struct Counter
{
    bool h[N][N]={};
    int g[N]={},q[N]={};
    inline void increase(int k,int l,int r)
    {
        tot+=l<r;
        rep(i,l,r) h[k][i]=true;
        g[k]+=r-l;
    }
    inline int count()
    {
        int ans(0);
        rep(i,0,1<<m)
        {
            bool suc(true);
            memcpy(q,g,n<<2);
            rep(j,0,m)
            {
                if(i&(1<<j))
                {
                    rep(k,0,n)
                    {
                        if(h[k][j])
                        {
                            --q[k];
                            if(!q[k])
                            {
                                suc=false;
                                break;
                            }
                        }
                    }
                    if(!suc) break;
                }
            }
            if(suc) ans=max(ans,__builtin_popcount(i));
        }
        return ans;
    }
};
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        Counter *cnt=new Counter;
        tot=0;
        scanf("%d%d%d%lf",&n,&m,&l,&f);
        rep(i,0,n)
        {
            scanf("%d%d%d\n",d+i,v+i,a+i);
        }
        rep(i,0,m)
        {
            scanf("%d",p+i);
        }
        rep(i,0,n)
        {
            if(a[i])
            {
                s=(sq(f)-sq(v[i]))/2.0/a[i]+d[i];
                if(a[i]>0) cnt->increase(i,upper_bound(p,p+m,s)-p,m);
                else cnt->increase(i,lower_bound(p,p+m,d[i])-p,lower_bound(p,p+m,s)-p);
            }
            else if(v[i]>f)
            {
                cnt->increase(i,lower_bound(p,p+m,d[i])-p,m);
            }
            else continue;
        }
        printf("%d %d\n",tot,cnt->count());
    }
    return 0;
}
