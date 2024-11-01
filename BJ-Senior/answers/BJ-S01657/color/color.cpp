#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int sz = 300000;
#define lf (x<<1)
#define rt (x<<1|1)
#define mid ((l+r)>>1)
int pos[200001],t[800001];
int x[200001],a[200001],lst[1000001],val[800001];
vector<int> v[800001];
inline void init(int x,int l,int r)
{
    if(l == r) {pos[l] = x; return;}
    v[x].push_back(lf); v[x].push_back(rt);
    v[lf+sz].push_back(x+sz); v[rt+sz].push_back(x+sz);
    init(lf,l,mid); init(rt,mid+1,r);
}
inline void addedge(int x,int l,int r,int p,int ll,int rr)
{
    if(ll <= l && r <= rr)
    {
        v[p].push_back(x);
        v[x+sz].push_back(p);
        return;
    }
    if(ll <= mid) addedge(lf,l,mid,p,ll,rr);
    if(rr > mid) addedge(rt,mid+1,r,p,ll,rr);
}
int c[800001];
long long sum1,sum2;
bool ok;
inline void check(int x)
{
    // cout << x << endl;
    for(int i = 0;i < v[x].size();i++)
    {
        // if(!ok) return;
        if(!c[v[x][i]])
        {
            if(c[x] == 1)
            {
                sum2 += val[v[x][i]];
                c[v[x][i]] = 2;
                check(v[x][i]);
            }
            else
            {
                sum1 += val[v[x][i]];
                c[v[x][i]] = 1;
                check(v[x][i]);
            }
        }
        else if(c[v[x][i]] == c[x]) ok = 0;
    }
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t; scanf("%d",&t);
    while(t--)
    {
        int tnp,n = 0; scanf("%d",&tnp);
        for(int i = 1;i <= tnp;i++) scanf("%d",&x[i]);
        // remove conbo
        bool conbo = 0;
        long long ans = 0;
        for(int i = 1;i <= tnp;i++)
        {
            if(x[i] != a[n])
            {
                conbo = 0;
                a[++n] = x[i];
            }
            else
            {
                ans += x[i];
                conbo = 1;
            }
        }
        // build graph
        memset(lst,0,sizeof(lst));
        memset(val,0,sizeof(val));
        for(int i = 1;i <= 800000;i++) v[i].clear(); // very slow!!!
        // init(1,1,20000); for(int i = 1;i <= 20000;i++) v[pos[i]].push_back(pos[i]+sz);
        for(int i = 1;i <= n;i++)
        {
            if(lst[a[i]] && lst[a[i]] < i-3)
            {
                for(int j = lst[a[i]]+2;j < i-1;j++)
                {
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
            if(lst[a[i]])
            {
                // cout << i << endl;
                val[i] = a[i];
            }
            lst[a[i]] = i;
        }
        // calc
        memset(c,0,sizeof(c));
        for(int i = 1;i <= n;i++)
        {

            if(!c[pos[i]])
            {
                // cout << i << endl;
                // for(int j = 1;j <= n;j++) cout << c[j] << " "; cout << endl;
                sum1 = val[i]; sum2 = 0; ok = 1;
                c[i] = 1;
                // cout << sum1 << " " << sum2 << endl;
                check(i);
                if(ok)
                {
                    // cout << sum1 << " " << sum2 << endl;
                    ans += max(sum1,sum2);
                }
            }
        }
        printf("%lld\n",ans);
        // break;
    }
    return 0;
}
