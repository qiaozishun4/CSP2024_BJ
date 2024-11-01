#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int N = 100005;
const int LR = 1000005;
int d[N], v[N], a[N], p[N], mp[LR];
bool vis[N];
// I love OI. I love my life. I am the happiest person in the world.
// I won't regret. I have enjoyed the journey.
// AFOed.
struct car{
    int id;
    int l, r;
}c[N];
bool cmp(car x, car y)
{
    if(x.l != y.l) return x.l < y.l;
    else return x.r > y.r;
}
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    scanf("%d", &T);
    //T=2;
    while(T--)
    {
        int n, m, L, vm;
        scanf("%d%d%d%d", &n, &m, &L, &vm);
        memset(d,0,sizeof(d));
        memset(v,0,sizeof(v));
        memset(a,0,sizeof(a));
        memset(p,0,sizeof(p));
        memset(vis,0,sizeof(vis));
        memset(mp,0,sizeof(mp));
        for(int i = 1;i <= n;i++)
        {
            scanf("%d%d%d", &d[i], &v[i], &a[i]);
            c[i] = {0,0,0};
        }
        for(int i = 1;i <= m;i++)
        {
            scanf("%d", &p[i]);
        }
        sort(p+1,p+m+1);
        int cur = 1;
        for(int i = 1;i <= L+1;i++)
        {
            mp[i] = cur;
            if(i == p[cur])cur++;
        }
        //cout << mp[74776] << "awa\n";
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            if(a[i] == 0)
            {
                if(v[i]>vm)
                {
                    c[i] = {i, mp[d[i]], mp[L]};
                    if(c[i].r > m) c[i].r = m;
                    if(c[i].l > m || c[i].l > c[i].r) vis[i] = 0;
                    else {vis[i] = 1;ans++;}
                }
                else vis[i] = 0;
                //cout << d[i] << " " << L << ": ";
            }
            else if(a[i] > 0)
            {
                if(v[i] > vm) {
                    c[i] = {i, mp[d[i]], m};
                    if(c[i].l > m || c[i].l > c[i].r) vis[i] = 0;
                    else{vis[i] = 1;ans++;}
                }
                else if(v[i] == vm) {
                    c[i] = {i, mp[d[i]+1], m};
                    if(c[i].l > m || c[i].l > c[i].r) vis[i] = 0;
                    else{vis[i] = 1;ans++;}
                }
                else{
                    double s = 1.*((vm*vm)-v[i]*v[i])/(2.*a[i]);
                    s=max(s,0.0);
                    if(d[i]+s <= L)
                    {
                        int st = mp[d[i]+(int)ceil(s)];
                        //cout << p[mp[st]] << "\n";
                        c[i] = {i, st, mp[L]};
                        if(p[c[i].l] == d[i]+s) c[i].l++;
                        if(c[i].r > m) c[i].r = m;
                        if(c[i].l > m || c[i].l > c[i].r) vis[i] = 0;
                        else{vis[i] = 1;ans++;}
                    }
                    else vis[i] = 0;
                }

                //cout << d[i]+s << " " << L << ": ";
            }
            else{
                double s = 1.*((vm*vm)-v[i]*v[i])/(2.*a[i]);
                if(v[i]>vm)
                {
                    c[i] = {i, mp[d[i]], mp[min(d[i]+(int)ceil(s), L+1)]-1};
                    if(c[i].l > m || c[i].l > c[i].r) vis[i] = 0;
                    else{vis[i] = 1;ans++;}

                }
                else vis[i] = 0;
                //cout << d[i] << " " << d[i]+s << ": ";
            }

            //if(vis[i]&&c[i].r!=m) cout << i << "\n";
                //printf("%d %d\n", c[i].l, c[i].r);
        }
        sort(c+1, c+n+1, cmp);
        int lf = 0, rt = 0;
        int cnt = 0;
        for(int i = 1;i <= n;i++)
        {
            if(!vis[c[i].id]) continue;
            if(lf<=c[i].r&&rt>=c[i].l)
            {
                lf=max(lf, c[i].l);
                rt=min(rt, c[i].r);
            }
            else
            {
                lf = c[i].l, rt = c[i].r;
                cnt++;
                //cout << n << " " << c[i].id << " " << rt << "~\n";
            }
        }
        printf("%d %d\n", ans, m-cnt);
    }
    return 0;
}
