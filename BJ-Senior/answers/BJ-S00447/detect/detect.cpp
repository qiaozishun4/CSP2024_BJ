#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
struct node{
    int st,v0,a;
    double leave,fast;
    int op;
}c[100010];

struct A{
    double l,r,a;
}a[100010],b[100010],d[100010];
int p[100010];
bool cmp1(A a1,A a2)
{
    return a1.r>a2.r;
}
bool cmp(A a1,A a2)
{
    return a1.l<a2.l;
}
int q[100010];
int tong[100010];
void solve()
{
    memset(d,0,sizeof(d));
    memset(b,0,sizeof(b));
    memset(tong,0,sizeof(tong));
    memset(q,0,sizeof(q));
    memset(c,0,sizeof(c));
    memset(p,0,sizeof(p));
    memset(a,0,sizeof(a));
    int n,m,L,V,ans=0;
    cin>>n>>m>>L>>V;
    for(int i=1;i<=n;i++) cin>>c[i].st>>c[i].v0>>c[i].a;
    for(int i=1;i<=m;i++) cin>>p[i];
    sort(p+1,p+m+1);
    for(int i=1;i<=n;i++)
    {
        if(c[i].a<0)
        {
            //double t=1.0*c[i].v0/(-c[i].a);
            double s=(1.0*c[i].v0*c[i].v0);
            //(-2.0*c[i].a);
            //v=0,dis
            c[i].leave=min(c[i].st*(-2.0*c[i].a)+s,(double)L*(-2.0*c[i].a));
        }
        else if(c[i].a>0) c[i].leave=L*(2.0*c[i].a);
        else c[i].leave=L;
    }
    int tot=0;
    for(int i=1;i<=n;i++)
    {
        if(c[i].a>0)
        {
            double len=1.0*(V*V-c[i].v0*c[i].v0);
            double dis=len+c[i].st*(2.0*c[i].a);
            if(dis>=c[i].leave) continue;
            else 
            {
                a[++tot].l=dis;
                a[tot].r=c[i].leave+1e-10;
                a[tot].a=c[i].a;
            }
        }
        else if(c[i].a<0)
        {
            if(c[i].v0<=V) continue;
            double len=1.0*(V*V-c[i].v0*c[i].v0);
            //(1.0*2*c[i].a);
            double dis=-len+c[i].st*(-2.0*c[i].a);
            //cout<<len<<" "<<dis<<'\n';
            if(dis>c[i].leave) 
            {
                a[++tot].l=c[i].st*(-2.0*c[i].a)-1;
                a[tot].r=c[i].leave+1;
                a[tot].a=-c[i].a;
            }
            else 
            {
                a[++tot].l=c[i].st*(-2.0*c[i].a)-1;
                a[tot].r=dis;
                a[tot].a=-c[i].a;
            }
        }
        else
        {
            if(c[i].v0<=V) continue;
            else 
            {
                a[++tot].l=c[i].st-1;
                a[tot].r=c[i].leave+1;
                a[tot].a=0.5;
            }
        }
    }
    //sort(c+1,c+n+1);
    /*for(int i=1;i<=n;i++)
    {
        printf("%lld %lld %lld ",c[i].st,c[i].v0,c[i].a);
        printf("%.4lf %.4lf\n",c[i].fast,c[i].leave);
    }*/
    //cout<<'\n';
    
    //[l,r]
    int qwq=0;
    //for(int i=1;i<=tot;i++) printf("%.4Lf %.4Lf %.4Lf\n",a[i].l/(2*a[i].a),a[i].r/(2*a[i].a),a[i].a);
    for(int i=1;i<=tot;i++)
    {
        //int ll=upper_bound(p+1,p+m+1,double(a[i].l))-p;
        //cout<<p[ll]<<'\n';
        int l=1,r=m,now=m+2;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(a[i].l<p[mid]*2.0*a[i].a) now=mid,r=mid-1;
            else l=mid+1;
        }
        //cout<<now<<'\n';
        if(now==m+2) continue;
        if(p[now]*2.0*a[i].a<a[i].r) ans++,d[++qwq]=a[i];
    }
    cout<<ans<<' ';
    sort(d+1,d+qwq+1,cmp1);
    int top=0;
    for(int i=1;i<=tot;i++)
    {
        while(top>=0&&d[i].l>d[q[top]].l) top--;
        q[++top]=i;
    }
    int num=0;
    for(int i=1;i<=top;i++) b[++num]=d[q[i]];
    sort(b+1,b+num+1,cmp);
    int ans1=0;
    for(int i=1;i<=num;i++)
    {
        int l=1,r=m,L=m+2,R=m+2;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(b[i].r>p[mid]*2.0*b[i].a) R=mid,l=mid+1;
            else r=mid-1;
        }
        l=1,r=m;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(b[i].l<p[mid]*2.0*b[i].a) L=mid,r=mid-1;
            else l=mid+1;
        }
        bool flag=0;
        for(int j=L;j<=R;j++) if(tong[j]==1) {flag=1;break;}
        if(flag==0) tong[R]=1,ans1++;
    }
    cout<<m-ans1<<'\n';
}
signed main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--) solve();
}