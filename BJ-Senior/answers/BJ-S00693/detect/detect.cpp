#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAXN = 1e5 + 5;
LL n, m, L, V, P[MAXN], T;
struct Node
{
    LL d, v, a;
} A[MAXN];
struct Line
{
    LL l, r;
} Li[MAXN];
bool cmp(Line x, Line y) { return x.l < y.l; }
bool cmp2(Line x, Line y) { return x.r > y.r; }
void SolveA()
{
    LL cnt = 0;
    for(LL i = 1; i <= n; i ++)
        if(A[i].v > V && A[i].d <= P[m]) cnt ++;
    if(cnt == 0) printf("%lld %lld\n", cnt, m);
    else printf("%lld %lld\n", cnt, m - 1);
    return;
}
void SolveB()
{
    LL cnt = 0;
    for(LL i = 1; i <= n; i ++)
        if(A[i].d <= P[m] && A[i].v * A[i].v + 2 * A[i].a * (P[m] - A[i].d) > V * V) cnt ++;
    if(cnt == 0) printf("%lld %lld\n", cnt, m);
    else printf("%lld %lld\n", cnt, m - 1);
    return;
}
void SolveC()
{
    LL cnt = 0;
    for(LL i = 1; i <= n; i ++)
    {
        LL L = 1, R = m, pos;
        while(L <= R)
        {
            LL mid = (L + R) >> 1;
            if(P[mid] >= A[i].d)
            {
                R = mid - 1;
                pos = mid;
            }
            else L = mid + 1;
        }
        if(A[i].v * A[i].v + 2 * A[i].a * (P[pos] - A[i].d) > V * V) cnt ++;
        else continue;
        L = pos; R = m;
        LL pos2;
        while(L <= R)
        {
            LL mid = (L + R) >> 1;
            if(A[i].v * A[i].v + 2 * A[i].a * (P[mid] - A[i].d) > V * V)
            {
                L = mid + 1;
                pos2 = mid;
            }
            else R = mid - 1;
        }
        Li[cnt] = Line{pos, pos2};
    }
    printf("%lld ", cnt);
    if(cnt == 0)
    {
        printf("%lld\n", m);
        return;
    }
    sort(Li + 1, Li + cnt + 1, cmp);
    LL anss = m - 1, las = 1, minn = Li[1].r;
    for(LL i = 1; i <= cnt; i ++)
    {
        if(Li[i].l > minn)
        {
            las = i;
            minn = Li[i].r;
            anss --;
        }
        else minn = min(minn, Li[i].r);
    }
    printf("%lld\n", anss);
    return;
}
void SolveAll()
{
    LL cnt = 0, cnt2 = 0, minto = m;
    for(LL i = 1; i <= n; i ++)
    {
        if(A[i].a >= 0)
        {
            if(A[i].d <= P[m] && A[i].v * A[i].v + 2 * A[i].a * (P[m] - A[i].d) > V * V)
            {
                cnt2 ++;
                LL L = 1, R = m, pos;
                while(L <= R)
                {
                    LL mid = (L + R) >> 1;
                    if(A[i].d <= P[m] && A[i].v * A[i].v + 2 * A[i].a * (P[mid] - A[i].d) > V * V)
                    {
                        R = mid - 1;
                        pos = mid;
                    }
                    else L = mid + 1;
                }
                minto = min(minto, pos);
            }
        }
        else
        {
            LL L = 1, R = m, pos;
            while(L <= R)
            {
                LL mid = (L + R) >> 1;
                if(P[mid] >= A[i].d)
                {
                    R = mid - 1;
                    pos = mid;
                }
                else L = mid + 1;
            }
            if(A[i].v * A[i].v + 2 * A[i].a * (P[pos] - A[i].d) > V * V) cnt ++;
            else continue;
            L = pos; R = m;
            LL pos2;
            while(L <= R)
            {
                LL mid = (L + R) >> 1;
                if(A[i].v * A[i].v + 2 * A[i].a * (P[mid] - A[i].d) > V * V)
                {
                    L = mid + 1;
                    pos2 = mid;
                }
                else R = mid - 1;
            }
            Li[cnt] = Line{pos, pos2};
        }
    }
    printf("%lld ", cnt + cnt2);
    if(cnt + cnt2 == 0)
    {
        printf("%lld\n", m);
        return;
    }
    sort(Li + 1, Li + cnt + 1, cmp2);
    LL anss = m - 1, las = 1, minn = Li[1].r, maxx = Li[1].l;
    bool flag = false;
    for(LL i = 1; i <= cnt; i ++)
    {
        if(Li[i].r < maxx)
        {
            las = i;
            if(minn >= minto) flag = true;
            minn = Li[i].r;
            maxx = Li[i].l;
            anss --;
        }
        else
        {
            minn = min(minn, Li[i].r);
            maxx = max(maxx, Li[i].l);
        }
    }
    if(flag) printf("%lld\n", anss);
    else printf("%lld\n", anss - 1);
    return;
}
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%lld", &T);
    while(T --)
    {
        scanf("%lld%lld%lld%lld", &n, &m, &L, &V);
        bool flagA = true, flagB = true, flagC = true;
        for(LL i = 1; i <= n; i ++)
        {
            scanf("%lld%lld%lld", &A[i].d, &A[i].v, &A[i].a);
            if(A[i].a != 0) flagA = false;
            if(A[i].a <= 0) flagB = false;
            if(A[i].a >= 0) flagC = false;
        }
        for(LL i = 1; i <= m; i ++) scanf("%lld", &P[i]);
        sort(P + 1, P + m + 1);
        if(flagA == true)
        {
            SolveA();
            continue;
        }
        else if(flagB == true)
        {
            SolveB();
            continue;
        }
        else if(flagC == true)
        {
            SolveC();
            continue;
        }
        else SolveAll();
    }

    return 0;
}
