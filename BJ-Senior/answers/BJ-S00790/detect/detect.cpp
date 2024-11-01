#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll T,n,m,L,V,ans1=0,ans2=0;

struct car
{
    ll d,v,a;
}c[100005];
struct cesuyi
{
    ll p;
    bool flag=0;
}y[100005];

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--)
    {
        ans1=ans2=0;
        cin>>n>>m>>L>>V;
        for(ll i=1;i<=n;i++)
        {
            cin>>c[i].d>>c[i].v>>c[i].a;
        }
        for(ll i=1;i<=m;i++)
        {
            cin>>y[i].p;
        }
        for(int i=1;i<=n;i++)
        {
            if(c[i].a==0)
            {
                if(c[i].v>V)
                {
                    for(int j=m;j>=1;j--)
                        if(y[j].p>=c[i].d)
                        {
                            ans1++;
                            y[j].flag=1;
                            break;
                        }
                }
            }
            else if(c[i].a>0)
            {
                if(c[i].v>V)
                {
                    for(int j=m;j>=1;j--)
                        if(y[j].p>=c[i].d)
                        {
                            ans1++;
                            y[j].flag=1;
                            break;
                        }
                }
                else if(c[i].v==V)
                {
                    for(int j=m;j>=1;j--)
                        if(y[j].p>c[i].d)
                        {
                            ans1++;
                            y[j].flag=1;
                            break;
                        }
                }
                else
                {
                    ll mind=((V*V)-(c[i].v*c[i].v))/(2*c[i].a);
                    for(int j=m;j>=1;j--)
                        if(y[j].p>c[i].d+mind)
                        {
                            ans1++;
                            y[j].flag=1;
                            break;
                        }
                }
            }
            else
            {
                if(c[i].v>V)
                {
                    ll mind=((V*V)-(c[i].v*c[i].v))/(2*c[i].a);
                    for(int j=m;j>=1;j--)
                        if(y[j].p<c[i].d+mind&&y[j].p>=c[i].d)
                        {
                            ans1++;
                            y[j].flag=1;
                            break;
                        }
                }
            }
        }
        for(int i=1;i<=m;i++)if(y[i].flag==0)ans2++;
        cout<<ans1<<" "<<ans2<<"\n";
        for(int i=1;i<=m;i++)y[i].flag=0;
    }
    return 0;
}
