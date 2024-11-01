
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int t;
int ans1,ans2;
int n,m,len,vmax;
int ch[maxn];
int l[maxn],r[maxn];
struct node{int l,r;}u[maxn];
int d[maxn],v[maxn],a[maxn],p[maxn];
int read()
{
    char c=getchar();
    int f=1,k=0;
    while(c<'0' || c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0' && c<='9')
    {
        k=k*10+(c-48);
        c=getchar();
    }
    return k*f;
}
bool cmp(node a,node b)
{
    return a.r<b.r;
}
signed main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    t=read();
    while(t--)
    {
        ans1=0;
        ans2=0;
        n=read();
        m=read();
        len=read();
        vmax=read();
        for(int i=1;i<=n;i++)
        {
            d[i]=read();
            v[i]=read();
            a[i]=read();
            l[i]=0;
            r[i]=0;
        }
        for(int i=1;i<=m;i++)
            p[i]=read();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(d[i]>p[j]) continue;
                int s1=sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]));
                //cout<<s1<<" ";
                if(s1>vmax || ((s1==vmax && s1*s1!=v[i]*v[i]+2*a[i]*(p[j]-d[i]))))
                {
                    if(!l[i]) l[i]=j;
                    r[i]=j;
                }
            }
            //cout<<"\n";
        }
        for(int i=1;i<=n;i++)
            if(l[i])
            {
                ans1++;
                u[ans1].l=l[i];
                u[ans1].r=r[i];
                //cout<<l[i]<<" "<<r[i]<<" "<<i<<"\n";
            }
        sort(u+1,u+ans1+1,cmp);
        for(int i=1;i<=ans1;i++)
        {
            bool fl=false;
            for(int j=1;j<=ans2;j++)
            {
                if(ch[j]<=u[i].r && ch[j]>=u[i].l)
                    fl=true;
            }
            if(!fl)
            {
                ans2++;
                ch[ans2]=u[i].r;
                //cout<<ch[ans2]<<" ";
            }
        }
        cout<<ans1<<" "<<n-ans2<<"\n";
    }
    return 0;
}

