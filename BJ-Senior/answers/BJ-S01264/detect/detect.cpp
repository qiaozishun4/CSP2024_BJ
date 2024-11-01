#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
long long d[100005],v[100005],a[100005],p[100005];
bool ned[100005];
int tree[100005];
long long n,m,L,V,ans=0;
void add(int i)
{
    int j=i;
    while(j<=m)
    {
        tree[j]+=1;
        j+=lowbit(j);
    }
}
int sum(int i)
{
    int cnt=0,j=i;
    while(j>0)
    {
        cnt+=tree[j];
        j-=lowbit(j);
    }
    return cnt;
}
bool que(int l,int r)
{
    int cnt=sum(r)-sum(l-1);
    if(cnt>0) return 1;
    return 0;
}
int run(int l,int r,long long num)
{
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(num==p[mid]) return mid;
    if(num>p[mid]) return run(mid+1,r,num);
    else return run(l,mid,num);
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>L>>V;
        ans=0;
        for(int i=1;i<=m;i++) ned[i]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&p[i]);
        }
        for(int i=1;i<=n;i++)
        {

            long long fir=(V*V)-(v[i]*v[i]);
            long long sec=2*a[i];
            long long zui=0;
            if(a[i]>0)
            {
                zui=d[i]+(fir/sec);
                bool yu=0;
                if(fir%sec!=0)
                {
                    yu=1;
                }
                if(zui>L)
                {
                    continue;
                }
                int where=run(1,m,zui);
                if(zui>p[where])
                if(zui>L)
                {
                    continue;
                }
                if(zui==p[where] && yu==1)
                if(zui>L)
                {
                    continue;
                }
                ans++;
                if(!que(where,m))
                {
                    ned[where]=1;
                    add(where);
                }
            }
            else if((a[i]<0 && v[i]<V))
            {
                zui=d[i]+(fir/sec);
                bool yu=0;
                if(fir%(-sec)!=0)
                {
                    yu=1;
                }
                if(zui>L)
                if(zui>L)
                {
                    continue;
                }
                int where=run(1,m,zui);
                if(zui>p[where])
                if(zui>L)
                {
                    continue;
                }
                ans++;
                if(!que(where,m))
                {
                    ned[where]=1;
                    add(where);
                }
            }
            else if(a[i]<=0)
            {
                zui=0;
                if(v[i]>=V)
                {
                    zui=d[i];
                    int where=run(1,m,zui);
                    if(zui>p[where])
                    if(zui>L)
                    {
                        continue;
                    }
                    ans++;
                    if(!que(where,m))
                    {
                        ned[where]=1;
                        add(where);
                    }
                }
            }
        }
        int cnt=0;
        for(int i=0;i<=m;i++)
        {
            if(ned[i]) cnt++;
        }
        cout<<ans<<' '<<m-cnt<<'\n';
    }
}
