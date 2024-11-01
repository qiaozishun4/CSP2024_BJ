// 16:28 AC detect3
// 16:49 AC detect4
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>

#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
const int NR = 1e5 + 5;
int n, m, l, V;
int p[NR];
bool flag[NR];
int a[NR], v[NR], d[NR];
pair<int, int> ans[NR];int cnt = 0;
// 当一辆车的初速度为 v0 、加速度 a!=0,做匀加速运动,则当它的位移为 s 时,
// 这辆车的瞬时速度为
// sqrt(v0 ^ 2 + 2 * a * s)
bool check1(int d, int v, int a, int mid) // 车辆在摄像头p[mid]时是否超速
{
    if(p[mid] < d) return false;
    long double vs = v * v + 2 * a * (p[mid] - d);
    return vs > V*V;
}
struct sst
{
    int l, r;
    bool operator < (const sst &b) const
    {
        return r < b.l;
    }
};
bool operator == (sst a, sst b){return (!(a < b)) && (!(b < a));}
multiset<sst> st;
void solve()
{
    st.clear();
    cnt = 0;
    cin >> n >> m >> l >> V;
//cout << "m = " << m << endl;
    for(int i = 1; i <= n; i++) flag[i] = false;
    for(int i = 1; i <= n; i++) cin >> d[i] >> v[i] >> a[i];
    for(int i = 1; i <= m; i++) cin >> p[i];

    int ans1 = 0;
    int mx1 = 0, mx = 0;
    for(int i = 1; i <= n; i++)
    {
        if(d[i] > p[m]) continue;
        if(a[i] == 0 && v[i] > V) mx1 = max(mx1, int(lower_bound(p + 1, p + m + 1, d[i]) - (p))), ans1++;
        else if(a[i] < 0) // 减速运动：找到最远的记录超速的摄像头 (d[i] ~ pos)
        {
            int pos1 = lower_bound(p + 1, p + m + 1, d[i]) - (p);
            int l = pos1, r = m + 1;
            while(l + 1 < r)
            {
                int mid = l + r >> 1;
                if(check1(d[i], v[i], a[i], mid)) l = mid;
                else r = mid;
            }
            if(pos1 <= l && check1(d[i], v[i], a[i], l) && 1 <= pos1 && l <= m) ans[++cnt] = {pos1, l}, ans1++;
//printf("a<0: i = %d, [%d, %d), check1(..., l) = %d, check1(..., r) = %d :: [%d, %d]\n", i, l, r, check1(d[i], v[i], a[i], l), check1(d[i], v[i], a[i], r), pos1, l);
        }
        else if(a[i] > 0) // 加速运动：找到最近的记录超速的摄像头 (pos ~ m)
        {
            int l = 1, r = m;
            while(l <= r)
            {
                int mid = l + r >> 1;
                if(check1(d[i], v[i], a[i], mid)) r = mid - 1;
                else l = mid + 1;
            }
            if(check1(d[i], v[i], a[i], l) && l <= m) mx = max(mx, l), ans1++;
//printf("a>0: i = %d, [%d, %d], check1(..., l) = %d, check1(..., r) = %d\n", i, l, r, check1(d[i], v[i], a[i], l), check1(d[i], v[i], a[i], r));
        }
    }
    //for(int i = 1; i <= cnt; i++) printf("{%d, %d}\n", ans[i].fi, ans[i].se);
    //if(mx != 0) printf("{%d, %d}\n", mx, p[m]);
    //if(mx1) printf("{%d, %d}\n", mx1, p[m]);
    if(mx != 0) ans[++cnt] = {mx, p[m]};
    if(mx1) ans[++cnt] = {mx1, p[m]};
//printf("ans[] = \n");
//for(int i = 1; i <= cnt; i++) printf("{%d, %d}\n", ans[i].fi, ans[i].se);

    for(int i = 1; i <= cnt; i++)
    {
        st.insert({ans[i].fi, ans[i].se});
    }

//printf("set<sst> st = \n");
//for(auto i : st) cout << i.l << " " << i.r << endl;
    int ret = 0;
    //for(int i = 1; i <= m; i++)

    for(int i = 1; i <= m; i++)
    {
//        printf("------------------\ni = %d\n", i);
        if(st.count({i, i}) > 1)
        {
            st.erase({i, i});
            st.insert({i, i});
        }

/*    for(int p = 1; p <= m; p++)
            printf("st.count({%d, %d}) = %d\n", p, p, st.count({p, p}));
printf("set<sst> st = %d\n", st.size());
for(auto i : st) cout << i.l << " " << i.r << endl;*/
    }
//cout << st.size() << endl;
    cout << ans1 << " " << m - st.size() << endl;
//puts("=========================================");
}
int main()
{
    //freopen("//home//csps//detect2.in", "r", stdin);
    //freopen("//home//csps//detect.out", "w", stdout);

    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    //int tx[15]{0, 1, 1, 2, 2, 3, 5, 7, 7};
    //cout << lower_bound(tx + 1, tx + 8 + 1, 2) - (tx) << endl;
    //cout << upper_bound(tx + 1, tx + 8 + 1, 2) - (tx) << endl;
    /*st.insert({1,2});
    st.insert({3,8});
    st.insert({3,3});
    st.insert({2,5});
    st.insert({5,7});
    st.insert({1,7});
    st.insert({9,10});
    st.insert({7,10});
    st.insert({1,10});
    st.insert({6,9});
    printf("set<sst> st = %d\n", st.size());
for(auto i : st) cout << i.l << " " << i.r << " " << (i == sst{2, 2}) << endl;;
    cout << st.count({2, 2}) << endl;
    printf("set<sst> st = %d\n", st.size());
for(auto i : st) cout << i.l << " " << i.r << " " << (i == sst{2, 2}) << endl;;
puts("=========================================");
*/
    int t;
    cin >> t;
    //solve();
    while(t--) solve();
    return 0;
}
/*
ans[] = 2 5 9
{1, 2}  q
{9, 10}q
{7, 10}q
{3, 8} q
{3, 3} ?????
{2, 5}
{5, 7}
{1, 10}
{1, 7}
{6, 9}
*/
