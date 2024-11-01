#include <iostream>
#include <cmath>
using namespace std;
int n;
const int mxn = 100005;
int a[mxn], vis[mxn], fig[mxn];
int minn = 1e9, secminn = 1e9;
int num = 0, secnum = 0;
void check() {
    minn = 1e9;
    for (int i = 0; i < n; i++) {
        if (a[i] < minn && vis[i] != 1) {
            num = i;
            minn = a[i];
        }
    }
    return ;
}
void check2() {
    secminn = 1e9;
    for (int i = 0; i < n; i++) {
        if (a[i] < secminn && vis[i] != 1 && fig[i] != 1 && i != num && secminn > a[i]) {
            secminn = a[i];
            secnum = i;
        }
    }
    return ;
}
bool check3() {
    for (int i = 0; i < n; i++) {
        if (vis[i] != 1) {
            if (fig[i] == 0) {
                return false;
            }
        }
    }
    return true;
}
using namespace std;
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    check();
    check2();
    for (int i = 0; i < n; i++) {
        if (minn == secminn) {
            fig[num] = 1;
            fig[secnum] = 1;
            check();
            check2();
            if (check3()) {
                break;
            } else {
                continue;
            }
        } else {
            vis[num] = 1;
            fig[secnum] = 1;
            check();
            check2();
            if (check3()) {
                break;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
