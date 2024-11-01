

#include <iostream>
#include <algorithm>

#define int long long

using namespace std;

const int MAXI = 1e5 + 9;
int t;
int n, m, L, V;
int d[MAXI], v[MAXI], a[MAXI];
int p[MAXI];

bool Detect (int i, int j) {
    if (d[i] > p[j]) return 0;

    if (a[i] == 0) return v[i] > V;
    if (a[i] < 0 && v[i] <= V) return 0;
    if (a[i] > 0 && v[i] > V) return 1;

    int one = 2 * a[i] * d[i] + V * V - v[i] * v[i];
    int two = 2 * a[i] * p[j];
    if (a < 0) return one <= two;
    if (a > 0) return one < two;
}

void BaoLi () {
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++) {
        bool flag = 0;
        for (int j = 1; j <= m; j++)
            if (Detect(i, j)) flag = 1;
        ans1 += flag;
    }
    for (int i = 0; i < (1 << m); i++) {
        bool flag = 1;
        for (int j = 1; j <= n; j++) {
            int flag1 = 0, flag2 = 0;
            for (int k = 1; k <= m; k++) {
                if (Detect(j, k)) {
                    flag1 = 1;
                    if (i & (1 << (k - 1))) flag2 = 1;
                }
            }
            if (flag1 && !flag2) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            int cnt = 0;
            for (int j = 1; j <= m; j++)
                if (!(i & (1 << (j - 1)))) cnt++;
            ans2 = max(ans2, cnt);
        }
    }
    cout << ans1 << ' ' << ans2 << '\n';
}

void SPA () {
    int ans1 = 0;
    for (int i = 1; i <= n; i++)
        if (v[i] > V && d[i] <= p[m]) ans1++;
    if (!ans1) cout << ans1 << ' ' << m << '\n';
    else cout << ans1 << ' ' << m - 1 << '\n';
}

void SPB () {
    int ans1 = 0;
    for (int i = 1; i <= n; i++)
        if (Detect(i, m)) ans1++;
    if (!ans1) cout << ans1 << ' ' << m << '\n';
    else cout << ans1 << ' ' << m - 1 << '\n';
}

void SPC () {
    int ans1 = 0;
    for (int i = 1; i <= n; i++) {
        int id = -1;
        int l = 1, r = m;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (p[mid] >= d[i]) id = mid, r = mid - 1;
            else l = mid + 1;
        }
        if (id == -1) ans1++;
        else if (Detect(i, id)) ans1++;
    }
    cout << ans1 << ' ' << 0 << '\n';
}

signed main () {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    cin >> t;
    while (t--) {
        cin >> n >> m >> L >> V;
        for (int i = 1; i <= n; i++) cin >> d[i] >> v[i] >> a[i];
        for (int i = 1; i <= m; i++) cin >> p[i];
        sort(p + 1, p + m + 1);

        if (n <= 20 && m <= 20) {
            BaoLi();
            continue;
        }

        if (a[1] == 0) {
            SPA();
            continue;
        }
        if (a[1] > 0) {
            SPB();
            continue;
        }
        if (a[1] < 0) {
            SPC();
            continue;
        };
    }

    return 0;
}


//struct Node {int l, r;}f[MAXI];
//bool Compare (Node one, Node two) {
//    return one.r < two.r;
//}
//void Solve () {
//    int ans1 = 0, ans2 = 0;
//    for (int i = 1; i <= n; i++) {
//        int id = -1;
//        int l = 1, r = m;
//        while (l <= r) {
//            int mid = (l + r) / 2;
//            if (p[mid] >= d[i]) id = mid, r = mid - 1;
//            else l = mid + 1;
//        }
//        if (a[i] < 0) {
//            l = id, r = m;
//            int num = -1;
//            while (l <= r) {
//                int mid = (l + r) / 2;
//                if (Detect(i, mid)) num = mid, l = mid + 1;
//                else r = mid - 1;
//            }
//            //id ~ num
//
//            f[i].l = id, f[i].r = num;
//        }
//        if (a[i] > 0) {
//            l = id, r = m;
//            int num = -1;
//            while (l <= r) {
//                int mid = (l + r) / 2;
//                if (Detect(i, mid)) num = mid, r = mid - 1;
//                else l = mid + 1;
//            }
//            //num ~ m
//
//            f[i].l = num, f[i].r = m;
//        }
//    }
//
//    sort(f + 1, f + n + 1, Compare);
//
//    int id = 0;
//    for (int i = 1; i <= n; i++) {
//        if (f[i].l > 0 && f[i].r > 0 && f[i].l <= f[i].r) {
//            ans1++;
//            if (f[i].l > id) id = f[i].r, ans2++;
//        }
//    }
//
//    cout << ans1 << ' ' << ans2 << '\n';
//}
