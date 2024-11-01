#include<bits/stdc++.h>
using namespace std;
#define LL long long
inline LL read()
{
    char ch=getchar();
    LL s=0,w=1;
    while(ch<'0'||ch>'9')
    {
        w=-w;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        s=(s<<3)+(s<<1)+(ch^48);
        ch=getchar();
    }
    return w*s;
}
inline void write(LL n)
{
    if(n<0)putchar('-'),n=-n;
    if(n>9)write(n/10);
    putchar(n%10+'0');
}
struct car
{
    LL d,v,a;
    long double s,e;
    bool cs;
}cars[100005];
LL p[100005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    //don't forgot to open the freopen before ending the match ! ! ! !

    LL t,n,m,l,v,i,j,ans;
    bool flagz=0;
    t=read();
    while(t--)
    {
        ans=flagz=0;
        n=read(),m=read(),l=read(),v=read();
        for(i=1;i<=n;i++)
        {
            cars[i].d=read();
            cars[i].v=read();
            cars[i].a=read();
            if(cars[i].a<0)flagz=1;
            if(cars[i].a>0)
            {
                cars[i].s=cars[i].d+(v*v-cars[i].v*cars[i].v)*0.5/cars[i].a;
                cars[i].e=l;
                cars[i].cs=1;
            }
            else if(cars[i].a<0)
            {
                if(cars[i].v>v)
                {
                    cars[i].s=cars[i].d;
                    cars[i].e=cars[i].d+(v*v-cars[i].v*cars[i].v)*0.5/cars[i].a;
                    cars[i].cs=1;
                }
                else cars[i].s=cars[i].e=l+1,cars[i].cs=0;
            }
            else
            {
                if(cars[i].v>v)
                {
                    cars[i].s=cars[i].d,cars[i].e=l+1;
                    cars[i].cs=1;
                }
                else cars[i].s=cars[i].e=l+1,cars[i].cs=0;
                //cout<<cars[i].s<<" "<<cars[i].e<<endl;
            }
        }
        for(i=1;i<=m;i++)p[i]=read();
        sort(p+1,p+m+1);
        if(flagz==0)
        {
            for(i=1;i<=n;i++)
            {
                if(cars[i].cs&&cars[i].s<=p[m]&&p[m]<=cars[i].e)
                    ans++;
            }
        }
        else
        {
            for(i=1;i<=n;i++)
            {
                LL temp=upper_bound(p+1,p+n+1,cars[i].s)-p;
                if(p[temp]>=cars[i].s&&p[temp]<=cars[i].e)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<" "<<m-1<<'\n';
    }
    return 0;
}
