#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define double long double
using namespace std;
int t,n,m,l,lim;
int d[100010],v[100010],a[100010],p[100010];
const double eps=1e-6;
struct seg{
    int l,r;
}b[100010];
bool cmp(const seg &x,const seg &y){
    return x.r<y.r;
}
long long fl(double x)
{
    if(x-(long long)x<eps)return (long long)x-1;
    else return (long long)x;
}
long long ce(double x)
{
    if((long long)x+1-x<eps)return (long long)x+2;
    else return (long long)x+1;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&n,&m,&l,&lim);
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
        for(int i=1;i<=m;i++)scanf("%d",&p[i]);
        for(int i=1;i<=n;i++)
        {
            if(a[i]>0)
            {
                if(v[i]>lim)
                {
                    b[i].l=d[i];
                    b[i].r=l;
                }
                else
                {
                    double tt=(lim-v[i])*1.0/a[i];
                    b[i].l=min((long long)l+1,ce(d[i]+v[i]*tt+0.5*a[i]*tt*tt));
                    b[i].r=l;
                    //zuo kai you bi
                }
            }
            else if(a[i]==0)
            {
                if(v[i]>lim)
                {
                    b[i].l=d[i];
                    b[i].r=l;
                }
                else
                {
                    b[i].l=1;
                    b[i].r=0;
                }
            }
            else if(v[i]>lim)
            {
                double tt=(lim-v[i])*1.0/a[i];
                b[i].l=d[i];
                b[i].r=min((long long)l,fl(d[i]+v[i]*tt+0.5*a[i]*tt*tt));
                //zuo bi you kai
            }
            else
            {
                b[i].l=1;
                b[i].r=0;
            }
        }
        //cout<<n-ccc<<endl;
        sort(b+1,b+n+1,cmp);
        int now=0,cnt=0,ans=0;
        p[0]=-1;
        for(int i=1;i<=n;i++)
        {
            if(p[now]>=b[i].l)
            {
                //cout<<i<<" "<<p[now]<<endl;
                cnt++;
                continue;
            }
            int nnow=now;
            while(nnow<m&&p[nnow+1]<=b[i].r)nnow++;
            if(p[nnow]<b[i].l)continue;
            now=nnow,ans++,cnt++;
            //cout<<i<<" "<<p[now]<<endl;
        }
        printf("%d %d\n",cnt,m-ans);
    }
    return 0;
}