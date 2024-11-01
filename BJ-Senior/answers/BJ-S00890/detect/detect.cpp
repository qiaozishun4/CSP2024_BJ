#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100000 + 10;
int T, n, m;
long long L, V, k, ans1, ans2;
long long d[maxn], v[maxn], a[maxn], p[maxn];
pair<int, int> s[maxn];
bool cmp(pair<int, int> x, pair<int, int> y) {
    return x.second < y.second;
}
int bs1(int l, int r, int i) {
    int ans = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        long long s = p[mid] - d[i];
        if(v[i] * v[i] + 2 * a[i] * s > V * V) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return ans;
}
int bs2(int l, int r, int i) {
    int ans = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        long long s = p[mid] - d[i];
        long long v2 = v[i] * v[i] + 2 * a[i] * s;
        if(v2 > V * V) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    int cnt = 0;
    while(T--) {
        cnt++;
        cin >> n >> m >> L >> V;
        for(int i = 1; i <= n; i++) cin >> d[i] >> v[i] >> a[i];
        for(int i = 1; i <= m; i++) cin >> p[i];
        ans1 = ans2 = k = 0;
        for(int i = 1; i <= n; i++) {
            int nxt = lower_bound(p + 1, p + 1 + m, d[i]) - p;
            //cerr << i << ": nxt = " << nxt << endl;
            if(nxt == m + 1) continue;
            if(a[i] == 0) {
                if(v[i] <= V) continue;
                ans1++;
                s[ans1].second = m;
                s[ans1].first = nxt;
                //cerr << i << ": " << s[ans1].first << " " << s[ans1].second << " range" << endl;
            }
            else if(a[i] > 0) {
                int pos = bs1(nxt, m, i);
                if(pos != -1) {
                    ans1++;
                    s[ans1] = {pos, m};
                    //cerr << i << ": " << s[ans1].first << " " << s[ans1].second << " range" << endl;
                }
            }
            else if(a[i] < 0) {
                int pos = bs2(nxt, m, i);
                //cerr << i << ": pos = " << pos << endl;
                if(pos != -1) {
                    ans1++;
                    s[ans1] = {nxt, pos};
                    //cerr << i << ": " << s[ans1].first << " " << s[ans1].second << " range" << endl;
                }
            }
        }
        sort(s + 1, s + ans1 + 1, cmp);
        int last = -1;
        for(int i = 1; i <= ans1; i++) {
            if(s[i].first > last) {
                ans2++;
                last = s[i].second;
            }
        }
        cout << ans1 << " " << m - ans2 << endl;
    }
    return 0;
}