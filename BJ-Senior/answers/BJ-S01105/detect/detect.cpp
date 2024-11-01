#include <bits/stdc++.h>
//typedef long long double;
using namespace std;
const int N=1e5+10;
double l,v,p[N];
set<int>g[N];
int ans1,ans2,n,m,t;
struct node
{
    double d,v,a,l;
}a[N];
double countl(double x,double y)
{
    return (v*v-x*x)/(y*2);
}
void ptsa()
{
    for(int i=0;i<n;i++)
    {
        if(a[i].v>v&&a[i].d<=p[m-1])
        {
            ans1++;
        }
    }
    cout<<ans1<<' '<<m-min(ans1,1)<<"\n";
}
void ptsb()
{
    for(int i=0;i<n;i++)
    {
        if(a[i].l<p[m-1])
        {
            ans1++;
        }
    }
    cout<<ans1<<' '<<m-min(ans1,1)<<"\n";
}
int b[N];
void dfs(int k,int x)
{
    if(k==m)
    {
        int f=0;
        for(int i=0;i<n;i++)
        {
            if(g[i].empty())
            {
                continue;
            }
            for(int j=0;j<x;j++)
            {
                if(g[i].count(b[j]))
                {
                    f++;
                    break;
                }
            }
        }
        if(f==ans1)
        {
            ans2=min(x,ans2);
        }
        return;
    }
    dfs(k+1,x);
    b[x]=k;
    dfs(k+1,x+1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>l>>v;
        int checka=1,checkb=1,checkc=1;
        ans1=0;
        ans2=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i].d>>a[i].v>>a[i].a;
            if(a[i].a!=0)
            {
                if(a[i].a>0)
                {
                    if(a[i].v>=v)
                    {
                        a[i].l=a[i].d;
                    }
                    else
                    {
                        a[i].l=min(countl(a[i].v,a[i].a)+a[i].d,l+10);
                    }
                }
                else
                {
                    if(a[i].v<v)
                    {
                        a[i].l=l+10;
                    }
                    else
                    {
                        a[i].l=min(countl(a[i].v,a[i].a)+a[i].d,l+10);
                    }
                }
                checka=0;
            }
            if(a[i].a<=0)
            {
                checkb=0;
            }
            if(a[i].a>=0)
            {
                checkc=0;
            }
        }
        for(int i=0;i<m;i++)
        {
            cin>>p[i];
        }
        if(checka)
        {
            ptsa();
            continue;
        }
        if(checkb)
        {
            ptsb();
            continue;
        }
        if(checkc)
        {
            continue;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i].a>0)
                {
                    if(p[j]>a[i].l)
                    {
                        g[i].insert(j);
                    }
                }
                if(a[i].a==0)
                {
                    if(p[j]>=a[i].d&&a[i].v>v)
                    {
                        g[i].insert(j);
                    }
                }
                if(a[i].a<0)
                {
                    if(p[j]<a[i].l&&p[j]>=a[i].d)
                    {
                        g[i].insert(j);
                    }
                }
            }
            if(!g[i].empty())
            {
                ans1++;
            }
        }
        ans2=m;
        dfs(0,0);
        cout<<ans1<<' '<<m-ans2<<"\n";
    }
    return 0;
}
