#include<bits/stdc++.h>
using namespace std;
long long d[100005],v[100005],a[100005],p[100005];
struct node
{
    long long l,r;
}e[100005];
long double t_ago(long long v,long long a,long long t)
{
    return v*t+0.5*a*t*t;
}
long double t_now(long long v,long long a,long long t)
{
    if(v*v+2*a*t<=0)
    {
        return 0;
    }
    return sqrt((long double)v*v+2*a*t);
}
bool cmp(node x,node y)
{
    return x.r<y.r;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    long long T;
    cin>>T;
    while(T--)
    {
        long long i,j,n,m,k,x,y,s=0,l,r,V,o=0;
        cin>>n>>m>>l>>V;
        for(i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        for(i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        sort(p+1,p+m+1);
        for(i=1;i<=n;i++)
        {
            if(a[i]>0)
            {
                if(d[i]>p[m])
                {
                    continue;
                }
                double la=t_now(v[i],a[i],p[m]-d[i]);
                if(la<=V)
                {
                    continue;
                }
                s++;
                long long L;
                l=1;
                r=m;
                L=1;
                while(l<=r)
                {
                    long long mid=l+r>>1;
                    if(p[mid]>=d[i])
                    {
                        L=mid;
                        r=mid-1;
                    }
                    else
                    {
                        l=mid+1;
                    }
                }
                l=L;
                r=m;
                long long R=m;
                while(l<=r)
                {
                    long long mid=l+r>>1;
                    if(t_now(v[i],a[i],p[mid]-d[i])>V)
                    {
                        R=mid;
                        r=mid-1;
                    }
                    else
                    {
                        l=mid+1;
                    }
                }
                e[++o].l=R;
                e[o].r=n;
            }
            if(a[i]==0)
            {
                long long la=v[i];
                if(la<=V||d[i]>p[m])
                {
                    continue;
                }
                s++;
                long long L;
                l=1;
                r=m;
                L=1;
                while(l<=r)
                {
                    long long mid=l+r>>1;
                    if(p[mid]>=d[i])
                    {
                        L=mid;
                        r=mid-1;
                    }
                    else
                    {
                        l=mid+1;
                    }
                }
                e[++o].l=L;
                e[o].r=m;
            }
            if(a[i]<0)
            {
                if(d[i]>p[m])
                {
                    continue;
                }
                if(v[i]<=V)
                {
                    continue;
                }
                long long L,R;
                l=1;
                r=m;
                L=m;
                while(l<=r)
                {
                    long long mid=l+r>>1;
                    if(p[mid]>=d[i])
                    {
                        L=mid;
                        r=mid-1;
                    }
                    else
                    {
                        l=mid+1;
                    }
                }
                double la=t_now(v[i],a[i],p[L]-d[i]);
                if(la<=V)
                {
                    continue;
                }
                l=1;
                r=m;
                R=1;
                while(l<=r)
                {
                    long long mid=l+r>>1;
                    if(t_now(v[i],a[i],p[mid]-d[i])>V)
                    {
                        R=mid;
                        l=mid+1;
                    }
                    else
                    {
                        r=mid-1;
                    }
                }
                e[++o].l=L;
                e[o].r=R;
            }
            // cout<<e[o].l<<" "<<e[o].r<<"\n";
        }
        s=0;
        cout<<o<<" ";
        sort(e+1,e+o+1,cmp);
        r=0;
        for(i=1;i<=o;i++)
        {
            if(e[i].l>r)
            {
                s++;
                r=e[i].r;
            }
        }
        cout<<m-s<<"\n";
    }
    return 0;
}