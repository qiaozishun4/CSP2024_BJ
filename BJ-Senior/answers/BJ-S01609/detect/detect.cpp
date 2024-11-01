#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MY_TEST

typedef long long ll;

void read(int &rtn) {
    bool rev = false;
    char c = getchar();
    rtn = 0;
    while (c < '0' || c > '9')
        rev |= (c == '-'), c = getchar();
    while (c >= '0' && c <= '9')
        rtn = (rtn << 3) + (rtn << 1) + c - 48, c = getchar();
    if (rev) rtn = -rtn;
}
void read(ll &rtn) {
    bool rev = false;
    char c = getchar();
    rtn = 0LL;
    while (c < '0' || c > '9')
        rev |= (c == '-'), c = getchar();
    while (c >= '0' && c <= '9')
        rtn = (rtn << 3) + (rtn << 1) + c - 48, c = getchar();
    if (rev) rtn = -rtn;
}

const int maxn = 100010;

int n, m, L, V, detectors[maxn];
struct Car {
    int d, v, a;
} cars[maxn];

struct TreeArray {
    int arr[maxn];
    const int lowbit(int x) { return x & -x; }
    void clear() {
        for (int i = 1; i <= m; ++i)
            arr[i] = 0;
    }
    void add(int x, int d) {
        for (; x <= m; x += lowbit(x))
            arr[x] += d;
    }
    int ask(int x) {
        if (!x) return 0;
        int rtn = 0;
        for (; x; x -= lowbit(x))
            rtn += arr[x];
        return rtn;
    }
} tree;

bool v_at_exceed(const Car &car, int pos) {
    return (ll)car.v * car.v + ((ll)car.a * (pos - car.d) << 1) > (ll)V * V;
}

int main() {
    #ifdef MY_TEST
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    #else
    freopen("detect5.in", "r", stdin);
    freopen("detect5.out", "w", stdout);
    #endif

    int T; read(T);
    while (T--) {
        read(n), read(m), read(L), read(V);
        tree.clear();
        for (int i = 1; i <= n; ++i) {
            read(cars[i].d), read(cars[i].v), read(cars[i].a);
        }
        for (int i = 1; i <= m; ++i)
            read(detectors[i]);
        sort(detectors + 1, detectors + m + 1);
        vector<pair<int, int>> restrict;
        for (int i = 1; i <= n; ++i) {
            if (cars[i].a != 0) {
                const int nxt_det = lower_bound(detectors + 1, detectors + m + 1, cars[i].d) - detectors;
                if (nxt_det > m) continue;
                if (cars[i].a > 0 && !v_at_exceed(cars[i], detectors[m])) continue;
                if (cars[i].a < 0 && !v_at_exceed(cars[i], detectors[nxt_det])) continue;
                int lt = nxt_det, rt = m, mid;
                while (lt <= rt) {
                    mid = lt + rt >> 1;
                    const bool judge = v_at_exceed(cars[i], detectors[mid]);
                    // printf("%d %d,%d=%d %d\n", i, lt, rt, mid, v_at_mid);
                    if (judge)
                        cars[i].a > 0 ? rt = mid - 1 : lt = mid + 1;
                    else cars[i].a > 0 ? lt = mid + 1 : rt = mid - 1;
                }
                if (cars[i].a > 0) restrict.push_back({rt + 1, m});
                else restrict.push_back({nxt_det, lt - 1});
            } else {
                if (cars[i].v <= V) continue;
                const int nxt_det = lower_bound(detectors+1, detectors+m+1, cars[i].d) - detectors;
                if (nxt_det <= m)
                    restrict.push_back({nxt_det, m});
            }
        }
        sort(restrict.begin(), restrict.end());
        queue<pair<int, int>> que;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (int i = 0; i < restrict.size(); ++i)
            que.push(restrict[i]);
        int rem = 0;
        for (int i = 1; i <= m; ++i) {
            while (!que.empty() && que.front().first <= i)
                heap.push({que.front().second, que.front().first}), que.pop();
            while (!heap.empty() && heap.top().first < i + 1) {
                if (!(tree.ask(heap.top().first) - tree.ask(heap.top().second - 1)))
                    tree.add(i, 1), ++rem;
                heap.pop();
            }
        }
        printf("%d %d\n", (int)restrict.size(), m - rem);
    }

    return 0;
}