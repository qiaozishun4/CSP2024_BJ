#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int n,m,L,V;
long long d[100010],v[100010],a[100010];
int p[100010];
int s[1000010];
int up[100010];
struct A
{
    int b,e;
};
A down[100010];
bool cmp(A x,A y)
{
    return x.e<y.e;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        memset(up,0,sizeof(up));
        memset(s,0,sizeof(s));
        memset(p,0,sizeof(p));
        memset(d,0,sizeof(d));
        memset(v,0,sizeof(v));
        memset(a,0,sizeof(a));
        scanf("%d%d%d%d",&n,&m,&L,&V);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&p[i]);
            s[p[i]]++;
        }
        sort(p+1,p+m+1);
        for(int i=1;i<=L;i++)
        {
            s[i]+=s[i-1];
        }
        int upsz=0,dwsz=0,cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(d[i]>p[m])continue;
            if(a[i]>0)
            {
                long long lst=0;
                if(v[i]>V)lst=d[i];
                else
                {
                    double t=1.0*(V-v[i])/a[i];
                    lst=d[i]+floor(1.0*v[i]*t+0.5*a[i]*t*t+1e-6)+1;

                }
                if(lst>p[m])continue;
                up[++upsz]=lst;
                cnt++;
            }
            else if(a[i]==0)
            {
                if(v[i]<=V)continue;
                up[++upsz]=d[i];
                cnt++;
            }
            else
            {
                if(v[i]<=V)continue;
                double t=1.0*(v[i]-V)/(-a[i]);
                long long lst=d[i]+ceil(1.0*v[i]*t+0.5*a[i]*t*t-1e-6)-1;
                if(lst>L)lst=L;
                if(s[lst]-s[d[i]-1]==0)continue;
                down[++dwsz].b=d[i];
                down[dwsz].e=lst;
                cnt++;
            }
        }
        //for(int i=1;i<=upsz;i++)cout<<up[i]<<' ';
        //cout<<endl;
        //for(int i=1;i<=dwsz;i++)cout<<down[i].b<<' '<<down[i].e<<endl;
        cout<<cnt<<" ";
        sort(down+1,down+dwsz+1,cmp);
        int last=0,ans=0;
        for(int i=1;i<=dwsz;i++)
        {
            if(last<down[i].b)
            {
                ans++;
                int pos=upper_bound(p+1,p+m+1,down[i].e)-p-1;
                last=p[pos];
                //cout<<p[pos]<<endl;
            }
        }
        for(int i=1;i<=upsz;i++)
        {
            if(up[i]>last)
            {
                ans++;
                break;
            }
        }
        cout<<m-ans<<endl;
        for(int i=1;i<=dwsz;i++)
        {
            down[i].b=0;
            down[i].e=0;
        }
    }
}