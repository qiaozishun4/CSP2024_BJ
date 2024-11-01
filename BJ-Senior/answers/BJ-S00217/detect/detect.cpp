#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int d[100010],s[100010],a[100010];
struct node
{
    int l,r;
    bool f;
}cg[100010];
bool cmp(node x,node y)
{
    return x.l<y.l;
}
int gt[100010];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m,lg,v;
        cin >> n >> m >> lg >> v;
        for(int i=1; i<=n; i++)
        {
            cin >> d[i] >> s[i] >> a[i];
            if(s[i]>v)
            {
                cg[i].l=d[i];
                if(a[i]>=0)
                    cg[i].r=lg;
                else
                {
                    a[i]=-a[i];
                    cg[i].r=cg[i].l+(s[i]-v-1)/a[i];
                    cg[i].r=min(cg[i].r,lg);
                }
            }
            else
            {
                if(a[i]<=0)
                {
                    cg[i].l=-1;
                    cg[i].r=-1;
                }
                else
                {
                    cg[i].l=d[i]+(v-s[i])/a[i]+1;
                    if(cg[i].l>lg)
                    {
                        cg[i].l=-1;
                        cg[i].r=-1;
                    }
                    else cg[i].r=lg;
                }
            }
        }
        for(int i=1; i<=m; i++)
            cin >> gt[i];
        sort(gt+1,gt+m+1);
        int cp=0;
        for(int i=1; i<=n; i++)
        {
            int p=upper_bound(gt+1,gt+m+1,cg[i].r)-gt;
            if(p==1 || gt[p-1]<cg[i].l) cg[i].f=0;
            else
            {
                cg[i].f=1;
                cp++;
            }
        }
        cout << cp << ' ';
        sort(cg+1,cg+n+1,cmp);
        int md=-1,cs=0;
        for(int i=1; i<=n; i++)
        {
            if(!cg[i].f) continue;
            int p=upper_bound(gt+1,gt+m+1,cg[i].r)-gt;
            if(md>cg[i].r)
            {
                md=gt[p-1];
                continue;
            }
            if(md>=cg[i].l) continue;
            md=gt[p-1];
            cs++;
        }
        cout << n-cs << endl;
    }
    return 0;
}