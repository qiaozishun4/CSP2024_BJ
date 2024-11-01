#include<bits/stdc++.h>
using namespace std;
int t,N,n,m,M;
double l,v,P[100005],p[100005];
double eps = 1e-8;
struct car
{
    double d,v,a;
}a[100005];
int calc(int x)
{
    int res = 0;
    while(x)
    {
        if(x & 1)   res ++;
        x >>= 1;
    }
    return res;
}
int check()
{
    int sum = 0;
    for(int i=1;i<=N;i++)
    {
        double d = a[i].d,curv = a[i].v;
        for(int j=1;j<=m;j++)
        {
            if(d > p[j])    continue;
            if(p[j] != d)
                curv = sqrt(a[i].v*a[i].v + 2.0 * a[i].a * (p[j] - d));
            if(curv > v)
            {
                sum ++;
                break;
            }
            if(j == m)  break;
            curv = sqrt(a[i].v*a[i].v + 2.0 * a[i].a * (p[j+1] - d));
            d = p[j+1];
        }
    }
    return sum;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> t;
    while(t --)
    {
        cin >> N >> M >> l >> v;
        n = N;
        m = M;
        int A = 1;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i].d >> a[i].v >> a[i].a;
            if(a[i].a)  A = 0;
        }
        for(int i=1;i<=m;i++)
        {
            cin >> P[i];
            p[i] = P[i];
        }
            int ok = check();
            cout << ok << ' ';
            int ans = 0;
            for(int i=0;i<(1<<M);i++)
            {
                m = 0;
                for(int i=1;i<=M;i++)   p[i] = 0;
                int curans = calc(i),id = 1,X = i;
                while(X)
                {
                    if(X & 1)   p[++ m] = P[id];
                    id ++;
                    X >>= 1;
                }
                if(check() != ok)   continue;
                ans = max(ans,M - curans);
            }
            cout << ans << '\n';
        /*
        if(A)
        {
            for(int i=1;i<=n;i++)
            {

            }
        }
        */
    }
    return 0;
}
