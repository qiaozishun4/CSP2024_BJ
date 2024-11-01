#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector <int> enterRoad[100005], exitRoad[100005], onRoad;
int T, n, m, l, r, mid, ret, ans1, ans2, p[100005];
long long L, V;
bool vis[100005];

struct Car
{
    long long d, v, a;
    int lp, rp;
};
Car c[100005];

inline bool isCarOnRoad(int id, int pos)
{
    // -v0*v0 / 2a >= s
    // 2a < 0  so  -v0*v0 <= s*2a
    return (pos >= c[id].d) && (c[id].a >= 0 || (-1 * c[id].v * c[id].v) <= (pos - c[id].d) * 2 * c[id].a);
}
inline bool isCarTooFast(int id, int pos)
{
    // sqrt(v0*v0 + 2*a*s) > V
    return isCarOnRoad(id, pos)
        && (c[id].v * c[id].v + 2 * c[id].a * (pos - c[id].d)) > V * V;
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    scanf("%d", &T);
    for(int tt = 1; tt <= T; tt++)
    {
        scanf("%d%d%lld%lld", &n, &m, &L, &V);

        ans1 = ans2 = 0;
        onRoad.clear();
        for(int i = 1; i <= m; i++)
        {
            enterRoad[i].clear();
            exitRoad[i].clear();
        }
        for(int i = 1; i <= n; i++)  vis[i] = false;

        for(int i = 1; i <= n; i++)
        {
            scanf("%lld%lld%lld", &c[i].d, &c[i].v, &c[i].a);
            c[i].lp = m, c[i].rp = -1;
        }
        for(int i = 1; i <= m; i++)
        {
            scanf("%d", &p[i]);
        }/*
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                printf("%d %d | %d %d\n", i, p[j], isCarOnRoad(i, p[j]), isCarTooFast(i, p[j]));
            }*/
        for(int i = 1; i <= n; i++)
        {
            l = 1, r = m;
            while(l <= r)
            {
                mid = (l + r) / 2;
                if(p[mid] >= c[i].d)
                {
                    c[i].lp = mid;
                    r = mid - 1;
                }
                else  l = mid + 1;
            }

            if(c[i].a >= 0 && isCarTooFast(i, p[m]))
            {
                l = c[i].lp, r = m, c[i].rp = m;
                while(l <= r)
                {
                    mid = (l + r) / 2;
                    if(isCarTooFast(i, p[mid]))
                    {
                        c[i].lp = mid;
                        r = mid - 1;
                    }
                    else  l = mid + 1;
                }
            }
            else if(c[i].a < 0 && isCarTooFast(i, p[c[i].lp]))
            {
                l = c[i].lp, r = m;
                while(l <= r)
                {
                    mid = (l + r) / 2;
                    if(isCarTooFast(i, p[mid]))
                    {
                        c[i].rp = mid;
                        l = mid + 1;
                    }
                    else  r = mid - 1;
                }
            }
        }
        for(int i = 1; i <= n; i++)
        {
            //printf("%d: %d %d\n", i, c[i].lp, c[i].rp);
            if(c[i].rp == -1)  continue;
            ans1++;
            enterRoad[c[i].lp].push_back(i);
            exitRoad[c[i].rp].push_back(i);
        }
        for(int i = 1; i <= m; i++)
        {
            for(int j = 0; j < enterRoad[i].size(); j++)
            {
                //printf("enter %d\n", enterRoad[i][j]);
                onRoad.push_back(enterRoad[i][j]);
            }
            for(int j = 0; j < exitRoad[i].size(); j++)
            {
                if(vis[exitRoad[i][j]])  continue;
                ans2++;
                //printf("exit %d\n", exitRoad[i][j]);
                for(int kk = 0; kk < onRoad.size(); kk++)
                {
                    //printf("kick %d\n", onRoad[kk]);
                    vis[onRoad[kk]] = true;
                }
                onRoad.clear();
            }
        }
        printf("%d %d\n", ans1, m - ans2);
    }
    return 0;
}
