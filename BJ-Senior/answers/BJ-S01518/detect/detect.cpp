#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int N=1e5+5;
int d[N],v[N],a[N];
int p[N];
double K[N];
int b[N];
int l[N],r[N];
struct Node
{
    int id,x;
}seg[N<<2][2];
Node pushup(Node l,Node r)
{
    Node ans;
    if(l.x>r.x)
    {
        ans.x=l.x;
        ans.id=l.id;
    }
    else
    {
        ans.x=r.x;
        ans.id=r.id;
    }
    return ans;
}
void build(int x,int l,int r,int op)
{
    if(l==r)
    {
        seg[x][op].x=b[l];
        seg[x][op].id=l;
        return;
    }
    int mid=l+r>>1;
    build(x<<1,l,mid,op);
    build(x<<1|1,mid+1,r,op);
}
void update(int x,int l,int r,int L,int k,int op)
{
    if(l==r)
    {
        seg[x][op].x=k;
        return;
    }
    int mid=l+r>>1;
    if(L<=mid) update(x<<1,l,mid,L,k,op);
    else update(x<<1|1,mid+1,r,L,k,op);
    seg[x][op]=pushup(seg[x<<1][op],seg[x<<1|1][op]);
}
Node query(int x,int l,int r,int L,int R,int op)
{
    if(l>=L&&r<=R)
    {
        return seg[x][op];
    }
    int mid=l+r>>1;
    Node ans;
    ans.x=ans.id=0;
    if(L<=mid) ans=pushup(ans,query(x<<1,l,mid,L,R,op));
    if(R>mid) ans=pushup(ans,query(x<<1|1,mid+1,r,L,R,op));
    seg[x][op]=pushup(seg[x<<1][op],seg[x<<1|1][op]);
    return ans;
}
double f(double x0,double a,double s)
{
    return sqrt(x0*x0+2*a*s);
}
double g(double v0,double v1,double a)
{
    return (v1*v1-v0*v0)/(2*a);
}
signed main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++) cin>>p[i];
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            double x=0;
            if(a[i]==0)
            {
                K[i]=v[i];
                if(d[i]>p[m]) K[i]=LONG_LONG_MAX;
                //cout<<i<<" "<<K[2]<<endl;
                if(K[i]>V)
                {
                    ans++;
                    r[i]=m;
                    l[i]=lower_bound(p+1,p+n+1,d[i])-p;
                }
                continue;
            }
            else if(a[i]>0)
            {
                if(d[i]>p[m]) x=LONG_LONG_MAX;
                else x=f(v[i],a[i],p[m]-d[i]);
                r[i]=m;
            }
            else
            {
                int k=lower_bound(p+1,p+n+1,d[i])-p;
                if(k>m||p[k]<d[i]) x=LONG_LONG_MAX;
                else x=f(v[i],a[i],p[k]-d[i]);
                l[i]=k;
            }
            if(x>V) ans++;
            K[i]=x;
        }
        cout<<ans<<" ";
        for(int i=1;i<=n;i++)
        {
            if(K[i]>V)
            {
                double x;
                if(a[i]==0) continue;
                else if(a[i]>0)
                {
                    x=g(v[i],V,a[i]);
                    int k=upper_bound(p+1,p+n+1,x+d[i])-p;
                    //if(k>n||p[k]<=x+d[i]) k=r[i];
                    //else
                        l[i]=k;
                    //<<i<<" "<<x<<endl;
                }
                else
                {
                     x=g(v[i],V,a[i]);
                     int k=lower_bound(p+1,p+n+1,x+d[i])-p;
                     //if(k<1||p[k]<x+d[i]) k=l[i];
                     //else
                    r[i]=k-1;
                }
                //cout<<i<<" "<<x+d[i]<<endl;
            }
            //if(l[i]==0) l[i]=r[i];
            //if(r[i]==0) r[i]=l[i];
        }
        for(int i=1;i<=n;i++)
        {
            if(d[i]>p[m]) K[i]=LONG_LONG_MIN;
            if(K[i]>V)
            {
                b[l[i]]++;
                b[r[i]+1]--;
//cout<<i<<" "<<l[i]<<" "<<r[i]<<endl;
            }
            //if(K[i]<=V||f(v[i],a[i],p[r[i]]-d[i])<=V||f(v[i],a[i],p[l[i]]-d[i])<=V) K[i]=-1;
        }
        for(int i=1;i<=n;i++) b[i]=b[i]+b[i-1];
        build(1,1,n,0);
        ans=0;
        for(int i=1;i<=n;i++)
        {
            if(K[i]>V) {
            if(query(1,1,n,l[i],r[i],1).x>=1) continue;
            int k=query(1,1,n,l[i],r[i],0).id;
            //cout<<i<<" "<<query(1,1,n,l[i],r[i],0).id<<endl;
            update(1,1,n,k,1,1);
            update(1,1,n,k,0,0);
            ans++;}
        }
        for(int i=1;i<=n;i++) d[i]=v[i]=a[i]=p[i]=K[i]=b[i]=l[i]=r[i]=0;
        for(int i=1;i<=(n<<2);i++) seg[i][0].x=seg[i][0].id=seg[i][1].x=seg[i][1].id=0;
        cout<<n-ans<<endl;
    }
    return 0;
}
