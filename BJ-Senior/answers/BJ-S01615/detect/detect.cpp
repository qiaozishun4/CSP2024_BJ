#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define int long long
// #define double long double
const int N = 1e5 + 5;
const double eps = 1e-8;

int t,n,m,cnt,len,ans1,ans2;
double l[N],r[N],p[N],v;

struct node
{
    double s,t;
} b[N];

bool cmp(node a,node b)
{
    if(a.t != b.t) return a.t < b.t;
    else return a.s < b.s;
}

signed main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> t;
    while(t--)
    {
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        memset(p,0,sizeof(p));
        memset(b,0,sizeof(b));
        ans1 = ans2 = cnt = 0;
        cin >> n >> m >> len >> v;
        v += 0.000001;
        for(int i=1;i<=n;i++)
        {
            int d,v0,a;
            cin >> d >> v0 >> a;
            double t,l0,r0;
            if(v0 > v)
            {
                if(a >= 0)
                {
                    l0 = d * 1.0;
                    r0 = 2e9;
                }
                else
                {
                    t = (v - v0) * 1.0 / a;
                    l0 = d * 1.0;
                    r0 = v0 * 1.0 * t + 0.5 * a * t * t + d;
                }
            }
            else
            {
                if(a <= 0)
                {
                    l0 = 2e9;
                    r0 = 2e9;
                }
                else
                {
                    t = (v - v0) * 1.0 / a;
                    l0 = v0 * 1.0 * t + 0.5 * a * t * t + d;
                    r0 = 2e9;
                }
            }
            l[i] = l0;
            r[i] = r0;
            // cout << l0 << " " << r0 << endl;
        }
        /*
        for(int i=1;i<=n;i++)
            cout << l[i] << " " << r[i] << endl;
        cout << endl;
        */
        for(int i=1;i<=m;i++)
            cin >> p[i];
        for(int i=1;i<=n;i++)
        {
            int lpos = lower_bound(p+1,p+m+1,l[i]) - p;
            int rpos = upper_bound(p+1,p+m+1,r[i]) - p - 1;
            // cout << lpos << " " << rpos << endl;
            if(lpos == m + 1 || lpos > rpos) ans1++;
            else
            {
                cnt++;
                b[cnt].s = lpos;
                b[cnt].t = rpos;
            }
        }
        sort(b+1,b+cnt+1,cmp);
        /*
        for(int i=1;i<=cnt;i++)
            cout << b[i].s << " " << b[i].t << endl;
        cout << "***" << endl;
        */
        double lst = -1;
        for(int i=1;i<=cnt;i++)
        {
            if(b[i].s - lst > eps)
            {
                ans2++;
                lst = b[i].t;
                // cout << b[i].s << " " << b[i].t << endl;
            }
        }
        cout << n - ans1 << " " << m - ans2 << endl;
        // cout << "--------------------" << endl;
    }
    return 0;
}
