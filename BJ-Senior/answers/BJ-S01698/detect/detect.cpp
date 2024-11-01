#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Car {
    double st, ed;
} car[100010];
int ck[100010];
Car cnt[100010];
bool isuse[100010];
int ans2 = pow(2, 31) - 1;

void dfs(int k, int n, int m, int &ans2) {
    if(k == m + 1) {
        int tongji = 0, ct = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(!isuse[j]) continue;
                if(ck[j] >= car[i].st && ck[j] <= car[i].ed) {
                    ct++;
                    break;
                }
            }
        }
        for(int i = 1; i <= m; i++) {
            if(isuse[i]) tongji++;
        }
        if(ct == m) {
            ans2 = min(tongji, ans2);
            //cout << ans2 << endl;
        }
        return;
    }
    isuse[k] = 1;
    dfs(k + 1, n, m, ans2);
    isuse[k] = 0;
    dfs(k + 1, n, m, ans2);
}

signed main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        int ans = 0, ans2 = pow(2, 31) - 1;
        int n, m, l, v;
        cin >> n >> m >> l >> v;
        for(int i = 1; i <= n; i++) {
            int dcar, vcar, acar;
            cin >> dcar >> vcar >> acar;
            if(acar == 0) {
                if(vcar > v) {
                    car[i].st = dcar;
                    car[i].ed = l;
                }
                else car[i].st = car[i].ed = -1; //-1 no chaosu luduan
            }
            if(acar > 0) {
                if(vcar <= v) {
                    double weiyi = (v * v - vcar * vcar) * 1.0 / (2 * acar);
                    car[i].st = dcar + weiyi + 1;
                    car[i].ed = l;
                    if(car[i].st > car[i].ed) car[i].st = car[i].ed = -1;
                }
                else {
                    car[i].st = dcar;
                    car[i].ed = l;
                }
            }
            if(acar < 0) {
                if(vcar > v) {
                    double weiyi = (v * v - vcar * vcar) * 1.0 / (2 * acar);
                    car[i].st = dcar;
                    car[i].ed = min(dcar + weiyi - 1, l * 1.0);
                }
                else {
                    if(car[i].st > car[i].ed) car[i].st = car[i].ed = -1;
                }
            }
            //cout << car[i].st << " " << car[i].ed << endl;
        }
        for(int i = 1; i <= m; i++) {
            cin >> ck[i];
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(ck[j] >= car[i].st && ck[j] <= car[i].ed) {
                    ans++;
                    //cout << i << " ";
                    break;
                }
            }
        }
        cout << ans << " ";
        dfs(1, n, m, ans2);
        cout << ans2 << endl;
    }
}
