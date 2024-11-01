#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int d[N],v[N],a[N],p[N];
int n,m,l,vv;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        bool f=0;
        int ans=0,cnt=0;
        cin>>n>>m>>l>>vv;//车辆数量、测速仪数量、主干道长度、道路限速
        for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
        //d驶入位置 v初速度 a加速度
        for(int i=1;i<=m;i++)cin>>p[i];
        for(int i=1;i<=n;i++)
        {
            int x=1;
            for(int j=1;j<=m;j++)
            {
                if(d[i]<p[j]) 
                {
                    x=j;
                    break;
                }
            }
            if(d[i]>p[m]) continue;
            if(a[i]==0)
            {
                if(v[i]>a[i])
                {
                    if(p[m]>=d[i])ans++,f=1;
                }
            }
            if(a[i]>0)
            {
                if((1LL*v[i]*v[i]+1LL*2*a[i]*p[m])*
                (1LL*v[i]*v[i]+1LL*2*a[i]*p[m])>
                1LL*vv*(1LL*v[i]*v[i]+1LL*2*a[i]*p[m])
                &&p[m]>=d[i])
                {
                    ans++,f=1;
                } 
            }
        }
        cout<<ans<<" "<<(f?max(cnt,1):cnt)<<"\n";
    }
    return 0;
}
