#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn (int)1e5
#define maxm (int)1e5
long long t,n,m,L,V;
long long p[maxm+10],sum[maxn+10],to[maxn+10];
pair<long long,pair<long long,long long>>c[maxn+10];
pair<long long,long long>a[maxn+10];
int lowbit(int x){return x&(-x);}
void add(int x)
{
    while(x<=n)
    {
        sum[x]++;
        x+=lowbit(x);
    }
    return;
}
long long query(int x)
{
    long long cnt=0;
    while(x)
    {
        cnt+=sum[x];
        x-=lowbit(x);
    }
    return cnt;
}
int main()
{
    //freopen("detect.in","r",stdin);
    //freopen("detect.out","w",stdout);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
        for(int i=0;i<n;i++)scanf("%lld%lld%lld",&c[i].first,&c[i].second.first,&c[i].second.second);
        sort(c,c+n);
        for(int i=0;i<m;i++)scanf("%lld",&p[i]);
        long long s=0,ans1=0,ans2=m-1;
        for(int i=0;i<n;i++)
        {
            while(p[s]<c[i].first)s++;
            long long l=s,r=m-1,ans=m;
            while(l<=r)
            {
                long long mid=(l+r)/2;
                if((c[i].second.second>=0&&c[i].second.first*c[i].second.first+2*c[i].second.second*(p[mid]-c[i].first)>V*V)||(c[i].second.second<0&&c[i].second.first*c[i].second.first+2*c[i].second.second*(p[mid]-c[i].first)<=V*V))
                {
                    ans=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            if(c[i].second.second>=0)a[i]={ans+1,m};
            else a[i]={s+1,ans};
        }
        sort(a,a+n);
        memset(sum,0,sizeof sum);
        memset(to,0,sizeof to);
        s=0;
        for(int i=0;i<n;i++)
            if(a[i].first<=a[i].second)
            {
                ans1++;
                while(s<a[i].first)
                {
                    if(to[s]&&query(s)==query(to[s]-1))
                    {
                        add(s);
                        ans2--;
                    }
                    s++;
                }
                to[a[i].second]=max(to[a[i].second],a[i].first);
            }
        if(!ans1)ans2++;
        printf("%lld %lld\n",ans1,ans2);
    }
}
//CSP RP++
//Please give me 100pts on this problem.
