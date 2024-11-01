#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100005
struct range
{
    int *l,*r;
};
int d[MAXN],v[MAXN],a[MAXN],p[MAXN];
range c[MAXN];
int* f(int *l,int *r,double x)
{
    while(l<r-1)
    {
        int *mid=l+(r-l)/2;
        if(x>=*mid)
            l=mid;
        else r=mid;
    }
    return l;
}
bool comp(range x,range y)
{
    return x.l<y.l;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T,n,m,L,V,cn;
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>L>>V;
        for(int i=0;i<n;i++)
            cin>>d[i]>>v[i]>>a[i];
        for(int i=0;i<m;i++)
            cin>>p[i];
        sort(p,p+m);
        cn=0;
        for(int i=0;i<n;i++)
        {
            double l=d[i]-1,r=L;
            if(a[i]==0)
            {
                if(v[i]<=V)l=L;
            }
            if(a[i]>0)
            {
                double x=((double)V*V-(double)v[i]*v[i])/a[i]/2;
                l=max(l,x);
            }
            if(a[i]<0)
            {
                double x=double((double)V*V-(double)v[i]*v[i])/a[i]/2;
                r=min(r,d[i]+x-(x==int(x)));
            }
            c[cn].l=f(p,p+m,l)+1;
            c[cn].r=f(p,p+m,r)+1;
            if(c[cn].l<c[cn].r)cn++;
        }
        cout<<cn<<' ';
        sort(c,c+cn,comp);
        int *r=0,pn=0;
        for(int i=0;i<cn;i++)
        {
            if(c[i].l<r)r=min(r,c[i].r);
            else
            {
                pn++;
                r=c[i].r;
            }
        }
        cout<<m-pn<<"\n";
    }
    return 0;
}

