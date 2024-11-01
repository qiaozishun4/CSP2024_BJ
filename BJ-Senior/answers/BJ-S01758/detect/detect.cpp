#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int d[N],fx[N],a[N];
double sx[N];
struct node
{
    int l,r;
};
node f[N];
bool cmp(node aa,node bb)
{
    return aa.r<bb.r;
}
int m,tot;
double pw(double x){return x*x;}
int askst(double x,int op)
{
    int l=1,r=m,mid,best=m+1;
    while(l<=r)
    {
        mid=l+r>>1;
        if(!op&&sx[mid]>=x||op&&sx[mid]>x)r=mid-1,best=mid;
        else l=mid+1;
    }
    return best;
}
int asked(double x,int op)
{
    int l=1,r=m,mid,best=0;
    while(l<=r)
    {
        mid=l+r>>1;
        if(!op&&sx[mid]<=x||op&&sx[mid]<x)l=mid+1,best=mid;
        else r=mid-1;
    }
    return best;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    int n,l,v;
    double st,ed;
    int fl,fr;
    int ansa,ansb,lst;
    while(t--)
    {
        tot=0;
        ansa=ansb=0;
        lst=0;
        scanf("%d%d%d%d",&n,&m,&l,&v);
        for(int i=1;i<=n;i++)scanf("%d%d%d",&d[i],&fx[i],&a[i]);
        for(int i=1;i<=m;i++)scanf("%lf",&sx[i]);
        for(int i=1;i<=n;i++)
        {
            if(a[i]>0)
            {
                if(fx[i]>v)
                {
                    st=1.0*d[i];
                    ed=1.0*l;
                    fl=askst(st,0);
                    fr=m;
                    if(fl>fr)continue;
                    ansa++;
                    f[++tot]={fl,m};
                }
                else
                {
                    st=1.0*d[i]+(pw(1.0*v)-pw(fx[i]))/(2.0*a[i]);
                    ed=1.0*l;
                    if(st>ed)continue;
                    fl=askst(st,1);
                    fr=m;
                    if(fl>fr)continue;
                    ansa++;
                    f[++tot]={fl,m};
                }
            }
            else if(a[i]<0)
            {
                if(fx[i]>v)
                {
                    st=1.0*d[i];
                    ed=1.0*d[i]+(pw(1.0*v)-pw(fx[i]))/(2.0*a[i]);
                    fl=askst(st,0);
                    fr=asked(ed,1);
                    if(fl>fr)continue;
                    ansa++;
                    f[++tot]={fl,fr};
                }
            }
            else
            {
                if(fx[i]>v)
                {
                    st=1.0*d[i];
                    ed=1.0*l;
                    fl=askst(st,0);
                    fr=m;
                    if(fl>fr)continue;
                    ansa++;
                    f[++tot]={fl,m};
                }
            }
        }
        if(!tot)
        {
            printf("%d %d\n",ansa,m);
            continue;
        }
        sort(f+1,f+1+tot,cmp);
        lst=f[1].r;
        ansb++;
        for(int i=2;i<=tot;i++)
        {
            if(f[i].l>lst)lst=f[i].r,ansb++;
        }
        ansb=m-ansb;
        printf("%d %d\n",ansa,ansb);
    }
    return 0;
}
