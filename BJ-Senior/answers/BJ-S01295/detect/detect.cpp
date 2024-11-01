#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double eps = 1e-6;
const int N = 1e5 + 5;
struct car
{
    int d; //驶入位置
    int sv; //初始速度
    int pls; //加速度
    int l, r; //超速时经过的测速仪下标区间
} a[N];
int mac[N]; //测速仪位置（保证从小到大）
bool operator< (car x, car y)
{
    return x.l < y.l;
}
int main(){
    freopen("detect.in","r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T --)
    {
        int n, m, L, V;
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i ++)
            cin >> a[i].d >> a[i].sv >> a[i].pls,
            a[i].l = a[i].r = 0;
        for (int i = 1; i <= m; i ++)
            cin >> mac[i];
        //count超速车辆数
        int ans1 = 0;
        for (int i = 1; i <= n; i ++)
        {
            if (a[i].pls < 0) //一直减速
            {
                if (a[i].sv <= V) continue;
                //速度降为0时过去的时间和路程
                double t = -a[i].sv * 1.0 / a[i].pls;
                double s0 = a[i].sv * t + 0.5 * a[i].pls * t * t - eps;
                int pos0 = lower_bound(mac+1,mac+m+1, a[i].d + s0) - mac;
                //经过的第一个测速仪
                int pos = lower_bound(mac+1,mac+m+1, a[i].d) - mac;
                if (pos > m) continue;
                double s = mac[pos] - a[i].d;
                //瞬时速度^2
                double v2 = a[i].sv * a[i].sv + 2 * a[i].pls * s;
                if (v2 > 0 && v2 > V * V)//超速
                {
                    ans1 ++; //统计
                    a[i].l = pos, a[i].r = pos0;
                    //瞬时速度降到限速 V 时所经过的路程
                    s = (V*V-a[i].sv*a[i].sv) * 1.0 / (2*a[i].pls) - eps;
                    //超速时经过的最后一个测速仪
                    pos = upper_bound(mac+1,mac+m+1, a[i].d + s) - mac - 1;
                    a[i].r = min(a[i].r, pos);
                }
            }
            else if (a[i].pls == 0) //速度不变
            {
                if (a[i].sv <= V) continue;
                int pos = lower_bound(mac+1,mac+m+1, a[i].d) - mac;
                if (pos > m) continue;
                ans1 ++; //统计
                a[i].l = pos; a[i].r = m; //一直超速到最后
            }
            else if (a[i].pls > 0)
            {
                double s = 0;
                //如果一开始还没超速
                if (a[i].sv <= V) //求上限
                    s = (V * V - a[i].sv * a[i].sv) * 1.0 / (2 * a[i].pls) + eps;
                int pos = lower_bound(mac+1,mac+m+1, a[i].d + s) - mac;
                if (pos > m) continue;
                ans1 ++; //统计
                a[i].l = pos; a[i].r = m;
            }
        }
        // cout << T << " : \n";
        cout << ans1 << " "; //统计完毕
        sort(a + 1, a + n + 1); //按左端点排序
        // if (T != 9) continue;
        // for (int i = 1; i <= n; i ++)
        //     cout << a[i].l << " " << a[i].r << "\n";
        int have = 0; //留下几个测速仪
        int l = 0, r = 0; //目前必有测速仪的区间
        bool flg = 0; //l,r 是否初始化
        for (int i = 1; i <= n; i ++)
        {
            if (a[i].l == 0 && a[i].r == 0) continue;
            if (!flg && a[i].l != 0 && a[i].r != 0)
                l = a[i].l, r = a[i].r, flg = 1;
            int nl = max(l, a[i].l);
            int nr = min(r, a[i].r);
            if (nl <= nr) l = nl, r = nr;
            else have ++, l = a[i].l, r = a[i].r;
        }
        if (l != 0 && r != 0) have ++;
        int ans2 = m - have; //丢弃了几个测速仪
        cout << ans2 << "\n";
    }

    return 0;
}
