#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct car
{
    int wz1,wz2;
}d[100005];
bool cmp(car x,car y)
{
    return x.wz1<y.wz1;
}
int e[100005],p[100005],cw[1000005];
double v[100005],a[100005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t2,n,m,len,lim,t,w,s,s2,x,i,j;
    scanf("%d",&t2);
    while(t2--)
    {
        s=s2=0;
        scanf("%d%d%d%d",&n,&m,&len,&lim);
        for(i=1;i<=n;i++)
            scanf("%d%lf%lf",e+i,v+i,a+i);
        for(i=1;i<=m;i++)
        {
            scanf("%d",p+i);
            if(i>1)
                for(j=p[i-1];j<p[i];j++)
                    cw[j]=p[i-1];
        }
        for(i=0;i<p[1];i++)
            cw[i]=-1;
        for(i=p[m];i<=len;i++)
            cw[i]=p[m];
        for(i=1;i<=n;i++)
        {
            d[i].wz1=-1;
            if(a[i]>0)
            {
                if(v[i]>lim)
                {
                    if(p[m]<e[i])
                        continue;
                    else
                        d[i].wz1=e[i],d[i].wz2=len,s2++;
                }
                else
                {
                    if(e[i]+floor((lim*lim-v[i]*v[i])/(2*a[i]))+1>p[m])continue;
                    d[i].wz1=e[i]+floor((lim*lim-v[i]*v[i])/(2*a[i]))+1;
                    d[i].wz2=len,s2++;
                }
            }
            if(a[i]==0)
                if(v[i]>lim&&p[m]>=e[i])
                    d[i].wz1=e[i],d[i].wz2=len,s2++;
            if(a[i]<0)
                if(v[i]>lim)
                {
                    x=min(len,int(e[i]+ceil((v[i]*v[i]-lim*lim)/(-2*a[i])-1)));
                    if(cw[x]<e[i])continue;
                    d[i].wz1=e[i],s2++;
                    d[i].wz2=x;
                }
        }
        sort(d+1,d+n+1,cmp);
        t=0,w=len;
        for(i=1;i<=n;i++)
        {
            if(d[i].wz1==-1)continue;
            if(cw[min(w,d[i].wz2)]>=max(t,d[i].wz1))
            {
                t=max(t,d[i].wz1);
                w=min(w,d[i].wz2);
            }
            else
            {
                s++;
                t=d[i].wz1,w=d[i].wz2;
            }
        }
        cout<<s2<<" ";
        if(s2==0)
            cout<<m<<endl;
        else
            cout<<m-s-1<<endl;
    }
    return 0;
}