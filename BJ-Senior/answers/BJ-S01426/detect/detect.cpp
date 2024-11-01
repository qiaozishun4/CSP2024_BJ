#include<bits/stdc++.h>
#define _for(i,a,b) for(int i=a;i<=b;i++)
#define _for1(i,a,b) for(int i=a;i>=b;i--)
#define ms(a,b) memset(a,b,sizeof a)
#define int long long
using namespace std;
const int maxn=1e5+5;
const long double eps=1e-4;
int n,m,L,V,p[maxn];
int l[maxn],r[maxn];
struct car
{
    int d,v,a;
}c[maxn];
struct L
{
    int l,r;
    bool operator < (const L & x)
    {
        return x.l>l;
    }
}len[maxn];
int ans=0;
void s2()
{
    int res=0;
    sort(len+1,len+n+1);
 //   _for(i,1,n) cout<<len[i].l<<' '<<len[i].r<<endl;
    _for(i,1,n)
    {
        if(len[i].l==0) continue;
        res++;
        int temp=len[i].r;
        int j;
        for(j=i;len[j].l<=temp&&temp<=len[j].r;j++) ;
        i=j;
    }
    cout<<m-res<<endl;
}
void solve()
{
    cin>>n>>m>>L>>V;
    _for(i,1,n)
        cin>>c[i].d>>c[i].v>>c[i].a;
    _for(i,1,m) cin>>p[i];
    sort(p+1,p+m+1);
    long double rt;
    _for(i,1,n)
    {
        if(c[i].d>p[m])
        {
            len[i].l=len[i].r=-1;
            continue;
        }
        if(c[i].a==0)
        {
            if(c[i].v>V)
                len[i].l=lower_bound(p+1,p+m+1,c[i].d)-p,len[i].r=m;
            else len[i].l=len[i].r=-1;
        }
        if(c[i].a>0)
        {
            rt=(long double)(V*V-c[i].v*c[i].v)/(long double)(c[i].a*2);
      //      cout<<rt<<endl;
            long double t=c[i].d;
            if((long double)(rt+t)>(long double)(L+eps)) len[i].r=len[i].l=-1;
            else
            {
                len[i].l=lower_bound(p+1,p+m+1,(long double)(rt+t))-p,len[i].r=m;
                if((long double)(rt+t)>=(long double)p[m]-eps) len[i].r=len[i].l=-1;
                else if((long double)p[len[i].l]-(long double)(rt+t)<=eps) len[i].l++;
            }
        }
        if(c[i].a<0)
        {
            rt=(long double)(V*V-c[i].v*c[i].v)/(long double)(c[i].a*2);
 //           rt=(long double)(V+c[i].v)/(long double)(c[i].a);
//            rt=rt/(long double)(2);
 //           rt=rt*(long double)(V-c[i].v);
    //        cout<<rt<<endl;
            long double t=c[i].d;
            if(rt+t>=(long double)(p[m]-eps)||rt<eps) len[i].r=len[i].l=-1;
            else
            {
                len[i].r=lower_bound(p+1,p+m+1,(long double)(rt+t))-p,len[i].l=lower_bound(p+1,p+m+1,c[i].d)-p;
                if((long double)(rt+t)>=(long double)p[m]-eps) len[i].r=len[i].l=-1;
                else if((long double)p[len[i].r]-(long double)(rt+t)<=eps) len[i].r--;
                else if((long double)(rt+t)<=(long double)p[len[i].l]+eps) len[i].r=len[i].l=-1;
            }
        }
    }
 //   _for(i,1,n) cout<<len[i].l<<" "<<len[i].r<<endl;
    ans=0;
    _for(i,1,n)
    {
        if(len[i].l!=-1)
        {
            ans++;

        }
        else len[i].l=len[i].r=0;
    }

    cout<<ans<<" ";
    s2();
}
signed main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}
