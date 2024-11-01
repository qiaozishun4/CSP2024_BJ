#include <bits/stdc++.h>
#define DB double
using namespace std;
const int MAXN=1e6+5;
const DB EPS=1e-8;
int T,N,M,L,V;
struct Car
{
    int d,v,a;
    int l,r;
    bool operator<(const Car &j) const
    {
        return r==j.r?l<j.l:r<j.r;
    } 
}c[MAXN];
int p[MAXN];
int ans1,ans2;
DB Speed(int v0,int a,int s)
{
    return sqrt((DB)(1ll*v0*v0+2ll*a*s));
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d %d",&N,&M,&L,&V);
        ans1=ans2=0;
        for(int i=1;i<=N;i++) 
        {
            scanf("%d %d %d",&c[i].d,&c[i].v,&c[i].a);
        }
        for(int i=1;i<=M;i++) scanf("%d",&p[i]);
        for(int i=1;i<=N;i++)
        {
            int d=c[i].d,v=c[i].v,a=c[i].a;
            int ll=0,rr=0;
            if(d>p[M])
            {
                c[i].l=c[i].r=0;
                ans1++;
                continue;
            }
            int po=lower_bound(p+1,p+M+1,d)-p;
            if(a==0)
            {
                if(v<=V||d>p[M]) ll=rr=0;
                else
                {
                    ll=po,rr=M;
                }
            }
            if(a<0)
            {
                if(v<=V||d>p[M]) ll=rr=0;
                else
                {
                    int L=po,R=M;
                    while(L<=R)
                    {
                        int mid=(L+R)>>1;
                        if(Speed(v,a,p[mid]-d)>V+EPS) rr=mid,L=mid+1;
                        else R=mid-1;
                    }
                    ll=po;
                    if(rr==0) ll=0;
                }
            }
            if(a>0)
            {
                int L=po,R=M;
                while(L<=R)
                {
                    int mid=(L+R)>>1;
                    if(Speed(v,a,p[mid]-d)>V+EPS) ll=mid,R=mid-1;
                    else L=mid+1;
                }
                rr=M;
                if(ll==0) rr=0;
            }
            c[i].l=ll,c[i].r=rr;
            if(c[i].l==0&&c[i].r==0) ans1++;
           // printf("[%d %d]\n",ll,rr);
        }
        printf("%d ",N-ans1);
        sort(c+1,c+N+1);
        int RB=0;
        for(int i=1;i<=N;i++)
        {
            if(c[i].l==0||c[i].r==0) continue;
            if(RB>=c[i].l) continue;
            RB=c[i].r;
            ans2++;
        }
        printf("%d\n",M-ans2);
    }
    return 0;
}