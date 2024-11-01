#include<bits/stdc++.h>
using namespace std;
struct node
{
    double d,v,add;
}p[100005];
double q[100005];
struct segm
{
    int l,r;
}qq[100005];
bool cmp(segm x,segm y)
{
    if(x.l!=y.l)
        return x.l<y.l;
    return x.r<y.r;
}
priority_queue<int,vector<int>,greater<int> > pq;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T,n,m,L,v,ans,l,r,mid,nn,no;
    double stop;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&n,&m,&L,&v);
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf%lf",&p[i].d,&p[i].v,&p[i].add);
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%lf",&q[i]);
        }
        ans=nn=0;
        for(int i=1;i<=n;i++)
        {
            if(p[i].add==0)
            {
                if(p[i].v>v)
                {
                    ans++;
                    l=1,r=m;
                    while(l<=r)
                    {
                        mid=(l+r)>>1;
                        if(q[mid]>=p[i].d)
                            r=mid-1;
                        else
                            l=mid+1;
                    }
                    qq[++nn].l=l;
                    qq[nn].r=m;
                }
            }
            if(p[i].add>0)
            {
                if(sqrt(p[i].v*p[i].v+2*p[i].add*(q[n]-p[i].d))>v)
                {
                    ans++;
                    l=1,r=m;
                    while(l<=r)
                    {
                        mid=(l+r)>>1;
                        if(sqrt(p[i].v*p[i].v+2*p[i].add*(q[mid]-p[i].d))>v)
                            r=mid-1;
                        else
                            l=mid+1;
                    }
                    qq[++nn].l=l;
                    qq[nn].r=m;
                }
            }
            if(p[i].add<0)
            {
                l=1,r=m;
                while(l<=r)
                {
                    mid=(l+r)>>1;
                    if(q[mid]>=p[i].d)
                        r=mid-1;
                    else
                        l=mid+1;
                }
                if(sqrt(p[i].v*p[i].v+2*p[i].add*(q[l]-p[i].d))>v)
                {
                    ans++;
                    qq[++nn].l=l;
                    stop=-p[i].v*p[i].v/2/p[i].add+p[i].d;
                    r=m;
                    while(l<=r)
                    {
                        mid=(l+r)>>1;
                        if(sqrt(p[i].v*p[i].v+2*p[i].add*(q[mid]-p[i].d))<=v||q[mid]>stop)
                            r=mid-1;
                        else
                            l=mid+1;
                    }
                    qq[nn].r=l-1;
                    if(T==14&&i==3)
                    {
//                        printf("%lf\n",stop);
//                        printf("%lf %lf %lf\n",p[i].d,p[i].v,p[i].add);
//                        printf("%d %d\n",qq[nn].l,qq[nn].r);
                    }
                }
            }
        }
        printf("%d ",ans);
        sort(qq+1,qq+nn+1,cmp);
//        if(T==14)
//        {
//            for(int i=1;i<=nn;i++)
//            {
//                printf("%d %d\n",qq[i].l,qq[i].r);
//           }
//        }
        ans=0;
        no=1;
        qq[nn+1].l=1e9;
        while(no<nn+1)
        {
            pq.push(qq[no].r);
            while(qq[no+1].l<=pq.top())
            {
                pq.push(qq[++no].r);
            }
            ans++;
            no++;
            while(!pq.empty())
            {
                pq.pop();
            }
        }
        printf("%d\n",n-ans);
    }
    return 0;
}
