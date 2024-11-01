#include <bits/stdc++.h>
#define ll long long
#define CHECK cout << "walked" << endl;
using namespace std;

const int N = 1e5 + 10, LL = 1e6 + 10;
int T;
int n, m, L, V;
int d[N], v[N], a[N], p[N];
int c_front[LL]; // 从前往后扫每个点的被管辖最近测速点
int c_back[LL]; // 从后往前扫每个点的被管辖最近测速点

struct cover {
    int l, r;
} seg[N];
int tot = 0;
bool cmp(cover t1, cover t2) {return t1.l < t2.l;}
bool vis[LL];
int ans1, ans2; 
// 问题可能是：（1）测速点相同
void prework(){
    memset(vis, 0, sizeof(vis));
    scanf("%d%d%d%d", &n, &m, &L, &V);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &d[i], &v[i], &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &p[i]);
        vis[p[i]] = 1;
    }
    // 注意是0～L的吧？？？？？？？？？？
    p[m + 1] = L + 1;
    for (int i = 1; i <= m; i++) {
        for (int j = p[i]; j < p[i + 1]; j++) {
            c_front[j] = i;
        }
    }
    for (int i = m - 1; i >= 0; i--) {
        for (int j = p[i] + 1; j <= p[i + 1]; j++) {
            c_back[j] = i + 1;
        }
    }
    // for (int i = 1; i <= L; i++) cout << c_front[i] << " " ; cout << endl;
    // for (int i = 1; i <= L; i++) cout << c_back[i] << " " ; cout << endl;



    ans1 = ans2 = 0;
}
void calcSegment() {
    tot= 0;
    for (int i = 1; i <= n; i++) {
        // cout << "i=" << i << endl;
        if (a[i] > 0) { // 加速度大于0的情况，这种情况下需要找到刚好超速的位置
            int len = L - d[i];
            int vtl_2 = v[i] * v[i] + 2 * a[i] * len;
            if (V * V < vtl_2) {
                int l = 0, r = len, mid;
                while (l + 1 < r) {
                    mid = (l + r) >> 1;
                    if (v[i] * v[i] + 2 * a[i] * mid <= V * V) {// 符号
                        l = mid;
                    } else {
                        r = mid;
                    }
                }
                if (v[i] * v[i] + 2 * a[i] * l <= V * V) l++; // 这里有大bug
                // 刚好超速的位置是l
                seg[++tot].l = c_back[d[i] + l];
                seg[tot].r = m;

                if (seg[tot].l < seg[tot].r) ans1++;
                else if(seg[tot].l == seg[tot].r && (vis[d[i] + l] || vis[m])) ans1 ++;
                // cout << seg[tot].l << " " << seg[tot].r << endl;
            } else {
                // pass
            }
        } else if (a[i] == 0) { // 这是加速度等于0的情况，这种情况下只需要判断v0即可
            if (v[i] <= V) {
                // pass
            } else {
                seg[++tot].l = c_back[d[i]];
                seg[tot].r = m;

                if (seg[tot].l < seg[tot].r) ans1++;
                else if (seg[tot].l == seg[tot].r && (vis[d[i]] || vis[m])) ans1 ++;
                // cout << seg[tot].l << " " << seg[tot].r << endl;
            }
        } else { // 这是加速度小于0的情况，这种情况下需要先判断是否可能超速，然后找到低于限速的位置
        // 大不了这段不要了！！！
            /*
            5 5 ‐2
            6 4 ‐4
            */
            int tt = c_back[d[i]];
            int dd = p[tt] - d[i];
            if (v[i] * v[i] + 2 * a[i] * dd <= V * V) {
                // pass
            } else {
                int l = dd, r = -v[i] * v[i] / (2 * a[i]), mid; // 这个r要检查
                while (l + 1 < r) {
                    mid = (l + r) >> 1;
                    if (v[i] * v[i] + 2 * a[i] * mid > V * V) { // 符号
                        l = mid;
                    } else {
                        r = mid;
                    }
                }
                if (v[i] * v[i] + 2 * a[i] * l <= V * V) l--;
                seg[++tot].l = c_back[d[i]];
                seg[tot].r = c_front[d[i] + l];
                if (seg[tot].l < seg[tot].r) ans1++;
                else if  (seg[tot].l == seg[tot].r && (vis[d[i]] || vis[d[i] + l])) ans1 ++;

                // cout << seg[tot].l << " " << seg[tot].r << endl;
            }
        }
    }
}

void GreedySolve() {
    int mxr = 0;
    sort(seg + 1, seg + 1 + tot, cmp);

        // for (int i = 1; i <= tot; i++) {
        //     cout << seg[i].l << " " << seg[i].r << endl;
        // }
    ans2 = m;
    for (int i = 1; i <= tot; i++) { // 这样离散化到底行不行
        if (seg[i].l > mxr) {
            ans2 -= (seg[i].l - mxr - 1);
            ans2--;
            mxr = seg[i].r;
        }
    }
    if (m > seg[tot].r)
        ans2 -= m - seg[tot].r - 1;
}

int main()
{
    freopen("detect3.in", "r", stdin);
    freopen("detect3.out", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        // 多测清空
        prework();

        calcSegment();

        GreedySolve();
        
        printf("%d %d\n", ans1, ans2);
        // 总体时间复杂度是O(nlogn) 等会细细的算一下
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

// 手搓数据：测速点连续