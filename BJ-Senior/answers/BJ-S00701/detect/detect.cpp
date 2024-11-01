#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
double f=0.01;
int t,n,m,l,vl,d[100005],v[100005],a[100005],p[100005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int i,j;
    cin>>t;
    while(t--)
    {
        int s=0;
        cin>>n>>m>>l>>vl;
        for(i=1;i<=n;i++)
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
        for(i=1;i<=m;i++)
            scanf("%d",&p[i]);
        for(i=1;i<=n;i++)
        {
            int x=lower_bound(p+1,p+m+1,d[i])-p;
            if(d[i]>p[m])continue;
            if(a[i]<=0)
            {
                double vt=1.0*v[i]*v[i]+2.0*a[i]*(p[x]-d[i]);
                if(vt-f>1.0*vl*vl)s++;
            }
            if(a[i]>0)
            {
                double vt=1.0*v[i]*v[i]+2.0*a[i]*(p[m]-d[i]);
                if(vt-f>1.0*vl*vl)s++;
            }
            /*for(j=x;j<=m;j++)
            {
                double vt=1.0*v[i]*v[i]+2.0*a[i]*(p[j]-d[i]);
                if(a[i]<0&&vt-f<=0)
                    break;
                if(vt-f>vl*vl)
                {
                    if(fl==0)
                        s++;
                    fl=1;
                    if(l[i]==0)l[i]=j;
                    r[i]=j;
                }
            }*/
        }
        if(s==0)cout<<s<<" "<<m<<endl;
        else cout<<s<<" "<<m-1<<endl;
    }
    return 0;
}
