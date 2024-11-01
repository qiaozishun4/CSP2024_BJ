#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int N=1e5;
int T,n,m,L,V,d[N+5],v[N+5],a[N+5],p[N+5],buk[N+5],f1,f2,f3,res,ans;
vector<int> vec;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&n,&m,&L,&V);
        f1=f2=f3=1;res=ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
            if(a[i]!=0) f1=0;
            if(a[i]<=0) f2=0;
            if(a[i]>=0) f3=0;
        }
        for(int i=1;i<=m;i++)
            scanf("%d",&p[i]);
        if(f1)
        {
            for(int i=1;i<=n;i++)
                if(v[i]>V) res++;
            if(res==0) ans=m;
            else ans=m-1;
            printf("%d %d\n",res,ans);
        }
        else if(f2)
        {
            for(int i=1;i<=n;i++)
                if(p[m]>d[i]&&floor((V*V-v[i]*v[i])/(2*1.0*a[i]))<p[m]-d[i])
                    res++;
            if(res==0) ans=m;
            else ans=m-1;
            printf("%d %d\n",res,ans);
        }
        else if(f3)
        {
            for(int i=1;i<=n;i++)
            {
                int now=lower_bound(p+1,p+m+1,d[i])-p;
                if(now==m+1) continue;
                if(ceil((V*V-v[i]*v[i])/(2*1.0*a[i]))>p[now]-d[i])
                {
                    res++;buk[now]=1;
                    int xx=lower_bound(vec.begin(),vec.end(),now)-vec.begin();
                    if(xx==0) vec.push_back(now);
                }
            }
            for(int i=1;i<=m;i++)
                if(buk[i]==1)
                    ans++;
            printf("%d %d\n",res,m-ans);
            vec.clear();
        }
    }
    return 0;
}
