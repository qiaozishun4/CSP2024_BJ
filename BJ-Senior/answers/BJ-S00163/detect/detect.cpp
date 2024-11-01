#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int t,n,m;
double L,V,d[100005],v[100005],a[100005],p[100005];
struct Need
{
    double l,r;
}ne[100005];
int cnt;
bool cmp(Need a,Need b)
{
    return a.r==b.r?a.l<b.l:a.r<b.r;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++)
            cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++)
            cin>>p[i];
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                if(v[i]<=V)
                    continue;
                cnt++;
                ne[cnt].l=lower_bound(p+1,p+m+1,d[i])-p;
                ne[cnt].r=m;
                if(ne[cnt].l>ne[cnt].r)
                    cnt--;
            }
            else if(a[i]<0)
            {
                if(v[i]<=V)
                    continue;
                double pos=d[i]+(V*V-v[i]*v[i])/2/a[i];
                if(p[1]<=pos)
                {
                    cnt++;
                    ne[cnt].l=lower_bound(p+1,p+m+1,d[i])-p;
                    ne[cnt].r=lower_bound(p+1,p+m+1,pos)-p-1;
                    if(ne[cnt].l>ne[cnt].r)
                        cnt--;
                }
            }
            else
            {
                if(v[i]>V)
                {
                    cnt++;
                    ne[cnt].l=lower_bound(p+1,p+m+1,d[i])-p;
                    ne[cnt].r=m;
                    if(ne[cnt].l>ne[cnt].r)
                        cnt--;
                    continue;
                }
                double pos=d[i]+(V*V-v[i]*v[i])/2/a[i];
                cnt++;
                ne[cnt].l=upper_bound(p+1,p+m+1,pos)-p;
                ne[cnt].r=m;
                if(ne[cnt].l>ne[cnt].r)
                    cnt--;
            }
        }
        sort(ne+1,ne+cnt+1,cmp);
        int ans=0,last=-1;
        for(int i=1;i<=cnt;i++)
        {
            if(ne[i].l<=last&&last<=ne[i].r)
                continue;
            last=ne[i].r;
            ans++;
        }
        cout<<cnt<<" "<<m-ans<<endl;
    }
    return 0;
}
