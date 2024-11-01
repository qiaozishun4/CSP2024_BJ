#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int d[100002],v[100002],a[100002],p[100002];
struct car {int l,r;} c[100002];
bool cmp(car x,car y) {return x.r < y.r;}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t; scanf("%d",&t);
    while(t--)
    {
        int n,m,l,V; scanf("%d%d%d%d",&n,&m,&l,&V);
        for(int i = 1;i <= n;i++) scanf("%d%d%d",&d[i],&v[i],&a[i]);
        for(int i = 1;i <= m;i++) scanf("%d",&p[i]);
        int ans1 = 0;
        for(int i = 1;i <= n;i++)
        {
            if(v[i] > V && a[i] < 0)
            {
                double dis = (1.0*V*V - 1.0*v[i]*v[i]) / 2.0 / a[i];
                int pos = floor(dis-1e-8) + d[i];
                c[0].l = lower_bound(p+1,p+1+m,d[i])-p;
                c[0].r = lower_bound(p+1,p+1+m,pos)-p;
                if(c[0].r > m || p[c[0].r] > pos) c[0].r--;
                if(c[0].r >= c[0].l)
                {
                    ans1++;
                    c[ans1].l = c[0].l;
                    c[ans1].r = c[0].r;
                }
            }
            else if(v[i] > V && a[i] >= 0)
            {
                if(d[i] > p[m]) continue;
                c[++ans1].l = lower_bound(p+1,p+1+m,d[i])-p;
                c[ans1].r = m;
            }
            else if(a[i] > 0)
            {
                double dis = (1.0*V*V - 1.0*v[i]*v[i]) / 2.0 / a[i];
                int pos = ceil(dis+1e-8) + d[i];
                c[0].l = lower_bound(p+1,p+1+m,pos)-p;
                c[0].r = m;
                if(c[0].r >= c[0].l)
                {
                    ans1++;
                    c[ans1].l = c[0].l;
                    c[ans1].r = c[0].r;
                }
            }
        }
        printf("%d ",ans1);
        sort(c+1,c+1+ans1,cmp);
        int ans2 = 0,lst = 0;
        for(int i = 1;i <= ans1;i++)
        {
            if(lst >= c[i].l) continue;
            ans2++;
            lst = c[i].r;
        }
        printf("%d\n",m-ans2);
    }
    return 0;
}
