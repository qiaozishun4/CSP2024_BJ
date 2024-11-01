#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1e5 + 5;
int t , n , m , L , vmax , d[maxn] , v[maxn] , a[maxn] , p[maxn] , lf[maxn] , rt[maxn] , f[maxn] , s[maxn];

int bound(int b[] , int l , int r , int k)
{
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (b[mid] >= k) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main()
{
    freopen("detect.in" , "r" , stdin);
    freopen("detect.out" , "w" , stdout);
    scanf("%d" , &t);
    while (t--)
    {
        memset(lf , 0 , sizeof(lf));
        memset(rt , 0 , sizeof(rt));
        memset(f , 0 , sizeof(f));
        memset(s , 0 , sizeof(s));
        scanf("%d%d%d%d" , &n , &m , &L , &vmax);
        for (int i = 1; i <= n; i++) scanf("%d%d%d" , &d[i] , &v[i] , &a[i]);
        for (int i = 1; i <= m; i++) scanf("%d" , &p[i]);
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!a[i])
            {
                if (v[i] > vmax)
                {
                    if (d[i] <= p[m])
                    {
                        int tmp = bound(p , 1 , m , d[i]);
                        lf[i] = tmp;
                        rt[i] = m;
                        f[lf[i]]++;
                        f[rt[i] + 1]--;
                        cnt++;
                    }
                }
            }
            else
            {
                int x = d[i] + (vmax * vmax - v[i] * v[i]) / 2 / a[i];
                if ((vmax * vmax - v[i] * v[i]) % (2 * a[i]) != 0) x++;
                if (a[i] > 0)
                {
                    //printf("1 ");
                    if (x <= p[m])
                    {
                        //printf("2 ");
                        int tmp = bound(p , 1 , m , x);
                        if (x == p[tmp]) tmp++;
                        lf[i] = tmp;
                        rt[i] = m;
                        f[lf[i]]++;
                        f[rt[i] + 1]--;
                        cnt++;
                    }
                }
                else
                {
                    //printf("3 ");
                    int tmp = bound(p , 1 , m , d[i]);
                    if (p[tmp] < x)
                    {
                        //printf("4 ");
                        int tmp2 = bound(p , 1 , m , x);
                        tmp2--;
                        if (tmp2 == x) tmp2--;
                        if (p[m] < x) tmp2 = m;
                        lf[i] = tmp;
                        rt[i] = tmp2;
                        f[lf[i]]++;
                        f[rt[i] + 1]--;
                        cnt++;
                    }
                }
                //puts("");
            }
        }
        printf("%d " , cnt);
        //puts("");
        //for (int i = 1; i <= n; i++) printf("%d %d\n" , lf[i] , rt[i]);
        //for (int i = 1; i <= m; i++) printf("%d " , f[i]);
        //puts("");
        int ans = 0;
        while (cnt != 0)
        {
            for (int i = 1; i <= m; i++) s[i] = s[i - 1] + f[i];
            //for (int i = 1; i <= m; i++) printf("%d " , s[i]);
            //puts("");
            int mx = 0 , id = 0;
            for (int i = 1; i <= m; i++)
            {
                if (s[i] > mx)
                {
                    mx = s[i];
                    id = i;
                }
            }
            if (id == 0) break;
            //printf("%d\n" , id);
            for (int i = 1; i <= n; i++)
            {
                if (lf[i] <= id && rt[i] >= id)
                {
                    cnt--;
                    f[lf[i]]--;
                    f[rt[i] + 1]++;
                    lf[i] = 0;
                    rt[i] = 0;
                }
            }
            ans++;
            //printf("%d\n" , cnt);
            //for (int i = 1; i <= n; i++) printf("%d %d\n" , lf[i] , rt[i]);
        }
        printf("%d\n" , m - ans);
    }

    return 0;
}
