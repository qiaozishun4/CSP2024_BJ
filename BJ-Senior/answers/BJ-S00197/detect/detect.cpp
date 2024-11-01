#include <iostream>
#include <cmath>
using namespace std;
#define ll long long
ll n, res[100010], m, t, v, l, cc;
bool vis[100010];
struct car {
    double s, p, st;
}c[100010];
bool check(ll x) {
    for(int j = 1; j <= m; j++) {
        if(res[j] - c[x].s < 0) {
            continue;
        }
        double tmp = sqrt(c[x].st + c[x].p * 2 * (res[j] - c[x].s));
        if(tmp > v) {
            vis[j] = true;
            return false;
        }
    }
    return true;
}
int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> t;
    while(t--) {
        cin >> n >> m >> l >> v;
        for(int i = 1; i <= n; i++) {
            cin >> c[i].s >> c[i].st >> c[i].p;
        }
        for(int i = 1; i <= m; i++) {
            cin >> res[i];
        }
        for(int i = 1; i <= n; i++) {
            if(!check(i)) {
                cc++;
            }
        }
        cout << cc << " ";
        cc = 0;
        for(int i = 1; i <= m; i++) {
            if(vis[i] == false) {
                cc++;
            }
        }
        cout << cc << endl;
    }


    return 0;
}
