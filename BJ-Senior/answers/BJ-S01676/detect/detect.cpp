#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,V;
int ans;
int d[100005],v[100005],a[100005],p[100005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    bool flag,flag2;
    int maxxp;
    scanf("%d",&t);
    for(int o=1;o<=t;o++)
    {
        scanf("%d%d%d%d",&n,&m,&l,&V);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
        }
        maxxp=-1;
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&p[i]);
            maxxp=max(maxxp,p[i]);
        }
        flag=1;
        for(int i=1;i<=n;i++) if(a[i]!=0) flag=0;
        if(flag)
        {
            ans=0;
            for(int i=1;i<=n;i++) if(v[i]>V&&d[i]<=maxxp) ans++;
            if(ans==0) m++;
            cout<<ans<<' '<<m-1<<endl;
        }
        flag2=1;
        for(int i=1;i<=n;i++) if(a[i]<=0) flag2=0;
        if(flag2)
        {
            ans=0;
            for(int i=1;i<=n;i++) if(d[i]<=maxxp&&(v[i]*v[i]+2*a[i]*(maxxp-d[i])>V*V)) ans++;
            if(ans==0) m++;
            cout<<ans<<' '<<m-1<<endl;
        }
    }
    return 0;
}
