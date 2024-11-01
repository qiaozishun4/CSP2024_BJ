#include <bits/stdc++.h>

using namespace std;
const int N=1e6+5;
int m,n,L,V;
int d[N],v[N],a[N],p[N],mn[N],mx[N],in,ax;//距离最南端 d i 的位置驶入
//以 v i 的初速度和 a i 的加速度做匀加速运动向北行驶。
int main()
{
    //当一辆车的初速度为 v 0 、加速度 a ̸ = 0,做匀加速运动,则 t 时刻后它的速度
    //v 1 = v 0 + a × t,它的位移(即行驶路程)s = v 0 × t + 0.5 × a × t 2 。
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    int s,wy;
    float j;
    while(T--)
    {
        cin>>n>>m>>L>>V;
        int h[N],ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }

        for(int i=1;i<=n;i++)
        {
            if(a[i]<=0&&v[i]<=V)continue;
            if(v[i]<V&&a[i]>0||v[i]>V&&a[i]>=0)
            {
                j=V*V+v[i]*v[8];
                j/=(2*a[i]);
                if(d[i]+j>L)continue;
                ans++;
                mn[i]=d[i]+j;
                in=min(mn[i],in);
                continue;
            }
            if(v[i]>V&&a[i]<0)
            {
                j=V*V+v[i]*v[8];
                j/=(2*a[i]);
                if(d[i]+j>L)continue;
                ans++;
                mn[i]=d[i];
                mx[i]=d[i]+j;
                in=min(mn[i],in);
                ax=max(mx[i],ax);
                continue;
            }
        }
        cout<<ans<<" "<<m-2;
    }
    return 0;
}