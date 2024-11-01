#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5 + 5, MAXV = 1e6 + 5;
int read(){
    int res = 0, flag = 1;
    char c = getchar();
    for (; c < '0' || c > '9'; c = getchar())
        if (c == '-')
            flag = -1;
    for (; c >= '0' && c <= '9'; c = getchar())
        res = (res << 1) + (res << 3) + (c ^ 48);
    return res * flag;
};
struct Segment{
    int l, r;
    bool operator < (const Segment T) const{
        if (l == T.l)
            return r < T.r;
        return l < T.l;
    }
}seg[MAXN];
int p[MAXN], s[MAXV];
struct Node{
    int id, r;
    bool operator < (const Node T) const{
        return r > T.r;
    }
};
priority_queue <Node> q;
int n, m, L, V;
int find(int l, int r){
    int L = 1, R = m, res = -1;
    while (L <= R){
        int mid = (L + R) >> 1;
        if (p[mid] <= r)
            res = mid, L = mid + 1;
        else
            R = mid - 1;
    } 
    if (res == -1)
        return 0;
    if (p[res] < l)
        return 0;
    return p[res];
}
bool vis[MAXN];
signed main(){
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T = read();
    while (T--){
        n = read(), m = read();
        L = read(), V = read();
        int pos = 0;
        for (int i = 1; i <= n; i++){
            int d = read(), v = read(), a = read();
            if (a == 0){
                if (v > V)
                    seg[++pos] = {d, L};
            }else if (a > 0){
                if (v > V)
                    seg[++pos] = {d, L};
                else{
                    int l = 0, r = L - d, res = 1e9;
                    while (l <= r){
                        int mid = (l + r) >> 1;
                        if (v * v + 2 * a * mid > V * V)
                            r = mid - 1, res = mid;
                        else
                            l = mid + 1;
                    }
                    if (d + res <= L)
                        seg[++pos] = {d + res, L};
                }
            }else if (a < 0){
                if (v > V){
                    int l = 0, r = L - d, res = 0;
                    while (l <= r){
                        int mid = (l + r) >> 1;
                        if (v * v + 2 * a * mid > V * V)
                            l = mid + 1, res = mid;
                        else
                            r = mid - 1;
                    }
                    seg[++pos] = {d, d + res};
                }
            }
        }
        for (int i = 1; i <= m; i++)
            p[i] = read();
        sort(seg + 1, seg + pos + 1);
        while (!q.empty())
            q.pop();
        int ans1 = 0, ans2 = 0;
        int lst = 1;
        for (int i = 1; i <= n; i++)
            vis[i] = 0;
        for (int i = 1; i <= pos; i++){
            while (!q.empty() && q.top().r < seg[i].l){
                int id = q.top().id;
                q.pop();
                if (id < lst)
                    continue;
                int res = find(seg[id].l, seg[id].r);
                if (res){
                    ans2++;
                    for (; seg[lst].l <= res && lst <= pos; lst++)
                        if (!vis[lst])
                            ans1++;
                }else{
                    vis[id] = true;
                }
            }
            q.push({i, seg[i].r});
        }
        while (!q.empty()){
            int id = q.top().id;
            q.pop();
            if (id < lst)
                continue;
            int res = find(seg[id].l, seg[id].r);
            if (res){
                ans2++;
                for (; seg[lst].l <= res && lst <= pos; lst++)
                    if (!vis[lst])
                        ans1++;
            }else{
                vis[id] = true;
            }
        }
        cout << ans1 << ' ' << m - ans2 << endl;
    }
    return 0;
}