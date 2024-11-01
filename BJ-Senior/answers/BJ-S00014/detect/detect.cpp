#include <bits/stdc++.h>
#define int long long
#define double long double
#define MAXN 1000005
#define lowbit(x) ((x)&-(x))
using namespace std;
int T, n, m, L, bit[MAXN], minn[MAXN], d[MAXN], p[MAXN];
double V, v[MAXN], a[MAXN];
int query(int x)
{
    int ans = 0;
    while (x)
    {
        ans += bit[x];
        x ^= lowbit(x);
    }
    return ans;
}
void update(int x)
{
    while (x < MAXN)
    {
        bit[x]++;
        x += lowbit(x);
    }
}
bool query(int x, int y)
{
    while (x)
    {
        if (minn[x] <= y)
        {
            return true;
        }
        x ^= lowbit(x);
    }
    return false;
}
void update(int x, int y)
{
    while (x < MAXN)
    {
        minn[x] = min(minn[x], y);
        x += lowbit(x);
    }
}
struct segment
{
    int l, r;
};
vector<segment> seg, usefulseg;
bool cmplen(segment x, segment y)
{
    return x.r - x.l < y.r - y.l;
}
bool cmpl(segment x, segment y)
{
    return x.l < y.l;
}
segment mseg(int l, int r)
{
    segment ans;
    ans.l = l;
    ans.r = r;
    return ans;
}
double getspeed(int bgn, int ed, double v, double a)
{
    return sqrtl(v * v + 2 * a * (ed - bgn));
}
signed main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    scanf("%lld", &T);
    while (T--)
    {
        memset(bit, 0, sizeof(bit));
        memset(minn, 0x3f, sizeof(minn));
        seg.clear();
        usefulseg.clear();
        // memset * n;
        scanf("%lld%lld%lld%Lf", &n, &m, &L, &V);
        V += 0.000001;
        int ans1 = 0, ans = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld%Lf%Lf", &d[i], &v[i], &a[i]);
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%lld", &p[i]);
        }
        p[m + 1] = L + 1;
        sort(p + 1, p + m + 1);
        for (int i = 1; i <= n; i++)
        {
            int fir = 1, firr = m + 1;
            while (fir < firr)
            {
                int mid = (fir + firr) / 2;
                if (p[mid] >= d[i])
                {
                    firr = mid;
                }
                else
                {
                    fir = mid + 1;
                }
            }
            int lst = m;
            if (fir > lst)
            {
                continue;
            }
            if (v[i] <= V && a[i] <= 0)
            {
                continue;
            }
            if (a[i] < 0)
            {
                double speed0place = d[i] - v[i] * v[i] / 2 / a[i];
                // cout << d[i] << "  " << a[i] << " < 0      speed0place = " << speed0place << endl;
                int lstl = 0, lstr = m + 1;
                while (lstl < lstr)
                {
                    int mid = (lstl + lstr + 1) / 2;
                    if (p[mid] <= speed0place)
                    {
                        lstl = mid;
                    }
                    else
                    {
                        lstr = mid - 1;
                    }
                }
                lst = lstl;
                // cout << fir << " " << lst << endl;
            }
            if (fir > lst)
            {
                continue;
            }
            double speedfir = getspeed(d[i], p[fir], v[i], a[i]);
            double speedlst = getspeed(d[i], p[lst], v[i], a[i]);
            if (speedfir > V && speedlst > V)
            {
                // cout << i << "th car    always over speed\n";
                ans1++;
                seg.push_back(mseg(fir, lst));
            }
            else if (speedfir <= V && speedlst <= V)
            {
                // cout << i << "th car    never over speed\n";
                continue;
            }
            else if (speedfir > V && speedlst <= V)
            {
                // cout << i << "th car    over speed -> no\n";
                ans1++;
                int lst_over_speed_l = fir, lst_over_speed_r = lst;
                while (lst_over_speed_l < lst_over_speed_r)
                {
                    int mid = (lst_over_speed_l + lst_over_speed_r + 1) / 2;
                    if (getspeed(d[i], p[mid], v[i], a[i]) > V)
                    {
                        lst_over_speed_l = mid;
                    }
                    else
                    {
                        lst_over_speed_r = mid - 1;
                    }
                }
                seg.push_back(mseg(fir, lst_over_speed_l));
            }
            else
            {
                // cout << i << "th car    no -> over speed\n";
                ans1++;
                int fir_over_speed_l = fir, fir_over_speed_r = lst;
                while (fir_over_speed_l < fir_over_speed_r)
                {
                    int mid = (fir_over_speed_l + fir_over_speed_r) / 2;
                    if (getspeed(d[i], p[mid], v[i], a[i]) > V)
                    {
                        fir_over_speed_r = mid;
                    }
                    else
                    {
                        fir_over_speed_l = mid + 1;
                    }
                }
                // cout << fir_over_speed_l << " " << lst << endl;
                seg.push_back(mseg(fir_over_speed_l, lst));
            }
        }
        /*
        for (segment i : seg)
        {
            cout << "[" << i.l << "," << i.r << "]\n";
        }
        cout << "\n";
        */
        sort(seg.begin(), seg.end(), cmplen);
        for (segment i : seg)
        {
            // cout << "[" << i.l << "," << i.r << "]\n";
            if (query(m - i.l + 1, i.r + 1))
            {
                continue;
            }
            usefulseg.push_back(i);
            update(m - i.l + 1, i.r + 1);
        }
        sort(usefulseg.begin(), usefulseg.end(), cmpl);
        for (segment i : usefulseg)
        {
            // cout << "useful [" << i.l << "," << i.r << "]\n";
            if (query(i.r) - query(i.l - 1))
            {
                continue;
            }
            update(i.r);
            ans++;
        }
        printf("%lld %lld\n", ans1, m - ans);
    }
    return 0;
}
