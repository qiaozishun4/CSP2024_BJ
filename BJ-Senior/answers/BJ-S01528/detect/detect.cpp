#include<bits/stdc++.h>
using namespace std;
int n,m,L,V;
struct car
{
    int d,v,a;
};
car c[100005];
int p[100005];
int road[1000006];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(c,0,sizeof(c));
        memset(p,0,sizeof(p));
        memset(road,0,sizeof(road));
        scanf("%d%d%d%d",&n,&m,&L,&V);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&c[i].d,&c[i].v,&c[i].a);
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&p[i]);
        }
        for(int i=1;i<=n;i++)
        {
            if(c[i].v>V&&c[i].a==0&&p[n]>=c[i].d)
            {
                ans++;
                //cout<<1;
            }
            else if(c[i].a>0&&p[n]>=c[i].d&&V*V<c[i].v+2*c[i].a*(p[n]-c[i].d))
                ans++;
        }
        cout<<ans<<" "<<1;
    }
    return 0;
}
//6

