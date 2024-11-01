#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5,M=1e6+5;
int t,n,m,L,V,ans1=0,ans2=0;
struct node
{
    double d,v,a;
}c[N];
struct fast
{
    double l,r;
}sum[N];
int p[N],s[M];
double solve(double v1,double v0,double a)
{
    double ans=(v1*v1-v0*v0)/(2.0*a);
    return ans;
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
        bool flag=0;
        int f=1e9+7;
        ans1=ans2=0;
        for(int i=1;i<=100000;i++) sum[i].l=sum[i].r=0;
        memset(s,0,sizeof(s));
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++) cin>>c[i].d>>c[i].v>>c[i].a;
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
            s[p[i]]=1;
        }
        for(int i=1;i<=n;i++)
        {
            if(c[i].a!=0) flag=1;
        }
        if(flag==0)
        {
            for(int i=1;i<=n;i++)
            {
                if(c[i].v>V)
                {
                    sum[i].l=c[i].d;
                    sum[i].r=L;
                }
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=sum[i].l;j<=sum[i].r;j++)
                {
                    if(s[j]==1)
                    {
                        ans1++;
                        break;
                    }
                }
            }
            if(ans1==0) m++;
            cout<<ans1<<" "<<m-1<<"\n";
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(c[i].a==0)
            {
                if(c[i].v>V)
                {
                    sum[i].l=c[i].d;
                    sum[i].r=L;
                }
            }
            else if(c[i].a>0)
            {
                if(c[i].v>V)
                {
                    sum[i].l=c[i].d;
                    sum[i].r=L;
                }
                else
                {
                    double k=solve(V,c[i].v,c[i].a);
                    if(c[i].d+k<L)
                    {
                        sum[i].l=floor(c[i].d+k+1.0);
                        sum[i].r=L;
                    }
                }
            }
            else if(c[i].a<0)
            {
                if(c[i].v>V)
                {
                    double k=solve(V,c[i].v,c[i].a);
                    if(c[i].d+k>L)
                    {
                        sum[i].l=c[i].d;
                        sum[i].r=L;
                    }
                    else
                    {
                        sum[i].l=c[i].d;
                        sum[i].r=ceil(c[i].d+k-1.0);
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=sum[i].l;j<=sum[i].r;j++)
            {
                if(s[j]==1)
                {
                    ans1++;
                    break;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=sum[i].r;j>=sum[i].l;j--)
            {
                if(s[j]==1)
                {
                    f=min(f,j);
                    break;
                }
            }
        }
        for(int i=1;i<f;i++)
        {
            if(s[i]==1) ans2++;
        }
        cout<<ans1<<" "<<ans2<<"\n";
    }
    return 0;
}
