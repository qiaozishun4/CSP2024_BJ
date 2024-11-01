#include <bits/stdc++.h>
using namespace std;
int n,m;
double L,V,t,d,v,b,p[100005];
struct line
{
    double l,r;
}a[100005];
bool cmp(line a,line b)
{
    if(a.r==b.r)return a.l<b.l;
    return a.r<b.r;
}
int main()
{
    freopen("detect5.in","r",stdin);
    freopen("detect5.out","w",stdout);
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> L >> V;
        int cnt=0,sum=0,sum2=0;
        for(int i=1;i<=n;i++)
        {
            cin >> d >> v >> b;
            if(b>0)
            {
                if(v>V)a[++cnt].l=d,a[cnt].r=L;
                else if((d+(V*V-v*v)/(2*b))<=L)a[++cnt].l=(d+(V*V-v*v)/(2*b)),a[cnt].r=L;
            }
            if(b<0)
            {
                if(v>V)a[++cnt].l=d,a[cnt].r=min((d+(V*V-v*v)/(2*b)),L);
            }
            if(b==0)
            {
                if(v>V)a[++cnt].l=d,a[cnt].r=L;
            }
        }
        for(int i=1;i<=m;i++)
        {
            cin >> p[i];
        }
        sort(a+1,a+cnt+1,cmp);
        sort(p+1,p+m+1);
        for(int i=cnt,j=m;j>=1&&i>=1;j--)
        {
            while(p[j]<=a[i].l&&i>=1)i--;
            while(p[j]>a[i].l&&p[j]<a[i].r&&i>=1)i--,sum++;
        }
        double past=-1;
        for(int i=1,j=1;i<=cnt;i++)
        {
            if(past<a[i].r&&past>a[i].l)continue;
            while(p[j]<a[i].r&&j<=m)j++;
            if(p[j-1]<a[i].r&&p[j-1]>a[i].l)past=p[j-1],sum2++;
        }
        cout << sum << " " << m-sum2 << endl;
    }
    return 0;
}