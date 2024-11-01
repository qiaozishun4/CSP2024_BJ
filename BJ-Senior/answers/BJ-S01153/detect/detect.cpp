#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int maxn = 1e5 + 5, maxm = 1e6 + 5;

bool pos[maxm];
int vl[maxm], l[maxn], r[maxn], X[maxn];
vector<pii> vec;

void work()
{
    int n, m, L, V;
    cin >> n >> m >> L >> V; vec.clear();
    for (int i = 1; i <= n; i++)
    {
        int d, v, a;
        cin >> d >> v >> a;
        if (a > 0)
        {
            if (v > V) l[i] = d, r[i] = L;
            else
            {
                int z = (V * V - v * v) / (2 * a) + d + 1;
                if (z > L) l[i] = r[i] = -1;
                else l[i] = z, r[i] = L;
            }
        }
        else if (a < 0)
        {
            if (v <= V) l[i] = r[i] = -1;
            else
            {
                int x = v * v - V * V, y = -2 * a, z = d + x / y;
                if (x % y == 0) z--;
                l[i] = d, r[i] = min(L, z);
            }
        }
        else
        {
            if (v > V) l[i] = d, r[i] = L;
            else l[i] = r[i] = -1;
        }
    }

    int *pre = vl + 1;
    for (int i = 0; i <= L; i++) pos[i] = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> X[i];
        pos[X[i]] = 1;
    }
    for (int i = 0; i <= L; i++) pre[i] = pre[i - 1] + pos[i];

    int cnt = 0, ans = m;
    for (int i = 1; i <= n; i++)
    {
        if (r[i] == -1 || l[i] > r[i]) continue;
        if (pre[r[i]] != pre[l[i] - 1]) cnt++, vec.emplace_back(make_pair(l[i], r[i]));
    }
    cout << cnt << " ";

    set<int> st; st.clear(); int lst = 0;
    for (int i = 1; i <= m; i++) st.insert(X[i]);
    sort(vec.begin(), vec.end(), [&](pii x, pii y) { if (x.second != y.second) return x.second < y.second; return x.first > y.first; });
    for (pii tmp : vec)
    {
        if (tmp.first <= lst) continue;
        ans--; auto it = st.upper_bound(tmp.second); it--;
        st.erase(it); lst = *it;
    }
    cout << ans << "\n";
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);

    int T; cin >> T;
    while (T--) work();
    return 0;
}