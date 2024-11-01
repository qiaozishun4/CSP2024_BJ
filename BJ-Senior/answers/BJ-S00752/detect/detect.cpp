#include<bits/stdc++.h>
using namespace std;
int d[100005],v[100005],a[100005],nxt[1000005];
struct car
{
    int l,r;
}c[100005];
bool cmp(car x,car y)
{
    return x.r<y.r;
}
bool p[1000005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int x,ans,L,n,m,V;
        cin>>n>>m>>L>>V;
        ans=n;
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d %d",&d[i],&v[i],&a[i]);
            d[i]=L-d[i];
        }
        for(int i=0;i<=L;i++)
            p[i]=0;
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&x);
            p[L-x]=1;
        }
        int now=0;
        for(int i=0;i<=L;i++)
        {
            if(p[i]) now++;
            nxt[i]=now;
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]>0)
            {
                if(v[i]>V)
                {
                    c[i].l=nxt[d[i]];
                    c[i].r=1;
                    if(c[i].l<c[i].r)
                        ans--;
                }
                else
                {
                    long double s=d[i]+((v[i]*v[i])-(V*V))/(2.0*a[i]);
                    if(s-floor(s)<=0.00000001)
                        s-=0.01;
                    long long s2=floor(s);
                    if(s2<0) c[i].l=0;
                    else c[i].l=nxt[s2];
                    c[i].r=1;
                    if(c[i].l<c[i].r)
                        ans--;
                }
            }
            else if(a[i]==0)
            {
                if(v[i]>V)
                {
                    c[i].l=nxt[d[i]];
                    c[i].r=1;
                    if(c[i].l<c[i].r)
                        ans--;
                }
                else
                {
                    ans--;
                    c[i].l=-1,c[i].r=1000;
                }
            }
            else
            {
                if(v[i]<=V)
                {
                    ans--;
                    c[i].l=-1,c[i].r=1000;
                }
                else
                {
                    long double s=d[i]+((v[i]*v[i])-(V*V))/(2.0*a[i]);
                    long long s2=floor(s);
                    if(s2<0) c[i].r=1;
                    else c[i].r=nxt[s2]+1;
                    c[i].l=nxt[d[i]];
                    if(c[i].l<c[i].r)
                        ans--;
                }
            }
        }
        cout<<ans<<" ";
        ans=0;
        sort(c+1,c+n+1,cmp);
        int temp=0;
        for(int i=1;i<=n;i++)
        {
            if(c[i].l<c[i].r)
                continue;
            if(c[i].r>temp)
            {
                temp=c[i].l;
                ans++;
            }
            temp=min(temp,c[i].l);
        }
        cout<<m-ans<<endl;
    }
    return 0;
}
