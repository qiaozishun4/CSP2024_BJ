#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 100050
#define EPS (ld)(1e-9)
#define ld long double
#define ll long long
using namespace std;
int n,m,p;
ll L,V,d[MAXN],v[MAXN],a[MAXN],b[MAXN];
ld l[MAXN];
// car i f[i]~g[i]

struct node{
    int l,r;
}c[MAXN];

bool cmp(node nodea,node nodeb)
{
    return (nodea.r<nodeb.r);
}

void check(ld xl,ld xr)
{
    int pos1=lower_bound(b+1,b+m+1,xl)-b;
    int pos2=upper_bound(b+1,b+m+1,xr)-b -1;
    if (pos1<=pos2)
    {
        c[++p]=(node){pos1,pos2};
    }
}

void solve()
{
    p=0;
    cin>>n>>m>>L>>V;
    for (int i=1;i<=n;i++)
    {
        cin>>d[i]>>v[i]>>a[i];

        if (a[i]>=0)
        {
            l[i]=L-d[i];
            continue;
        }

        ld k1=-2.0*a[i]*(L-d[i]);
        ld k2=(ld)v[i]*v[i];
        //cout<<k1<<" "<<k2<<endl;
        if (k1<=k2) l[i]=L-d[i];
        else l[i]=(ld)-k2*0.5/(ld)a[i];

        //cout<<g[i]<<endl;
    }
    for (int i=1;i<=m;i++) cin>>b[i];

    for (int i=1;i<=n;i++)
    {
        if (a[i]>0)
        {
            if (v[i]>V) //always chaosu
            {
                check(d[i],L);
                continue;
            }
            ld x=(ld)(V*V-v[i]*v[i])/((ld)2.0*a[i]);
            if (x>L-d[i]) continue; //never chaosu

            check((ld)d[i]+x+EPS,L);
        }
        else if (a[i]==0)
        {
            if (v[i]>V) //always chaosu
            {
                check(d[i],L);
            }
        }
        else
        {
            if (v[i]<=V) continue; //never chaosu
            ld x=(ld)(V*V-v[i]*v[i])/((ld)2.0*a[i]);

            if (x<=l[i]) check(d[i],(ld)d[i]+x-EPS);
            else check(d[i],d[i]+l[i]); //contains always chaosu
        }
    }

    sort(c+1,c+p+1,cmp);
    int ma=0,cnt=0;
    for (int i=1;i<=p;i++)
    {
        //cout<<c[i].l<<" "<<c[i].r<<endl;
        if (c[i].l<=ma) continue;
        else
        {
            cnt++;
            ma=max(ma,c[i].r);
        }
    }
    cout<<p<<" "<<m-cnt<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    int T;
    cin>>T;
    while (T--) solve();

    fclose(stdin);
    fclose(stdout);
    return 0;
}
