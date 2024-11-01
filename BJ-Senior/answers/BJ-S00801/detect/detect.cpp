#include <iostream>
#include <algorithm>
using namespace std;
int T, n, m, L, V, d[100010], v[100010], a[100010], p[100010], ans1, ans2;
int ednum[100010];
struct crs
{
    int st, ed;
}carr[100010];
int cnt;
int fin_fir_big(double num, int tp, int l, int r)//tp=0: > tp=1: >=
{
    if(l == r)
        return l;
    int mid = (l + r) >> 1;
    if(tp == 0)
    {
        if((double)p[mid] > num)
            return fin_fir_big(num, tp, l, mid);
        else
            return fin_fir_big(num, tp, mid + 1, r);
    }
    else
    {
        if((double)p[mid] >= num)
            return fin_fir_big(num, tp, l, mid);
        else
            return fin_fir_big(num, tp, mid + 1, r);
    }
}
int fin_las_sma(double num, int tp, int l, int r)//tp=0: < tp=1: <=
{
    if(l == r)
        return l;
    int mid = (l + r + 1) >> 1;
    if(tp == 0)
    {
        if((double)p[mid] >= num)
            return fin_las_sma(num, tp, l, mid - 1);
        else
            return fin_las_sma(num, tp, mid, r);
    }
    else
    {
        if((double)p[mid] > num)
            return fin_las_sma(num, tp, l, mid - 1);
        else
            return fin_las_sma(num, tp, mid, r);
    }
}
bool cmp(crs ta, crs tb)
{
    if(ta.st != tb.st)
        return ta.st < tb.st;
    return ta.ed < tb.ed;
}
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int i;
    cin >> T;
    while(T--)
    {
        ans1 = 0;
        ans2 = 0;
        cnt = 0;
        cin >> n >> m >> L >> V;
        for(i = 1; i <= n; i++)
            cin >> d[i] >> v[i] >> a[i];
        for(i = 1; i <= m; i++)
            cin >> p[i];
        for(i = 1; i <= n; i++)
        p[m + 1] = 1e9;
        p[0] = 0;
        for(i = 1; i <= n; i++)
        {
            if(a[i] == 0)
            {
                if(v[i] > V)
                {
                    if(d[i] > p[m])
                        continue;
                    int st = fin_fir_big(d[i], 1, 1, m + 1);
                    cnt++;
                    ans1++;
                    //cout << i << " " << st << " " << m << endl;
                    carr[cnt].st = st;
                    carr[cnt].ed = m;
                }
            }
            else if(a[i] > 0)
            {
                int st, ed;
                if(v[i] >= V)
                    st = fin_fir_big(d[i], (v[i] > V ? 1 : 0), 1, m + 1);
                else
                {
                    double whe = (V * V - v[i] * v[i]);
                    whe /= (2.0 * a[i]);
                    st = fin_fir_big((double)(d[i]) + whe, 0, 1, m + 1);
                }
                if(st <= m)
                {
                    ans1++;
                    //cout << i << " " << st << " " << m << endl;
                    cnt++;
                    carr[cnt].st = st;
                    carr[cnt].ed = m;
                }
            }
            else
            {
                int st, ed;
                if(v[i] <= V || p[m] < d[i])
                    continue;
                st = fin_fir_big(d[i], 1, 1, m + 1);
                double whe = (V * V - v[i] * v[i]);
                whe /= (2.0 * a[i]);
                ed = fin_las_sma((double)(d[i]) + whe, 0, 0, m + 1);
                if(ed < st)
                    continue;
                ans1++;
                //cout << i << " " << st << " " << ed << endl;
                cnt++;
                carr[cnt].st = st;
                carr[cnt].ed = ed;
            }
        }
        cout << ans1 << " ";
        sort(carr + 1, carr + 1 + cnt, cmp);
        int now = 1;
        for(i = 1; i <= cnt; i++)
            ednum[carr[i].ed]++;
        for(i = 1; i <= m; i++)
        {
            if(ednum[i] > 0)
            {
                ans2++;
                while(carr[now].st <= i && now <= cnt)
                {
                    ednum[carr[now].ed]--;
                    now++;
                }
            }
            if(now > cnt)
                break;
        }
        cout << m - ans2 << endl;
    }
    // Wow!
    return 0;
}