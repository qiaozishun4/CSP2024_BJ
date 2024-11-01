#include <cstdio>
#include <cstring>

using namespace std;

const int NR = 1e5 + 10;
int d[NR], v[NR], a[NR], p[NR];

bool flag[NR];

int cal_temp(int x)
{
    if (x % 2 == 0) return x / 2;
    return x / 2 + 1;
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);


    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(flag, 0, sizeof(flag));
        int n, m, l, vm, ans = 0, cnt = 0;
        scanf("%d%d%d%d", &n, &m, &l, &vm);
        for (int i = 1; i <= n; i++)
            scanf("%d%d%d", d + i, v + i, a + i);
        for (int i = 1; i <= m; i++)
            scanf("%d", p + i);

        
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0) 
            {
                if (v[i] > vm) 
                {
                    for (int j = 1; j <= m; j++)
                    {
                        if (p[j] >= d[i] && p[j] <= l)
                        {
                            flag[p[j]] = true;
                            cnt++;
                        }
                    }
                }
            }
            else if (a[i] < 0)
            {
                if (v[i] > vm)
                {
                    int s = v[i] + a[i] * vm / 2 + d[i];
                    if (s > l) continue;
                    for (int j = d[i]; j <= s; j++)
                    {
                        if (p[j] >= d[i] && p[j] <= s)
                        {
                            flag[p[j]] = true;
                            cnt++;
                        }
                    }
                    //printf("%d : %d %d %d %d %d\n", i, d[i], v[i], a[i], s, cnt);
                }
            }
            else if (a[i] > 0)
            {
                int s = v[i] + cal_temp(a[i] * vm) + d[i];
                if (s > l) continue;
                for (int j = 1; j <= m; j++)
                {
                    if (p[j] >= s && p[j] <= l)
                    {
                        flag[p[j]] = true;
                        cnt++;
                    }
                }
                //printf("%d : %d %d %d %d %d\n", i, d[i], v[i], a[i], s, cnt);
            }
        }
        for (int i = 1; i <= m; i++)
        {
            if (flag[p[i]] == true)
            {
                ans++;
                //printf("%d ", p[i]);
            }
        }
        printf("%d %d\n", cnt, ans);
    }

    return 0;
}