#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

struct Car {
    int place;
    int speed;
    int add;
};

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n, m, l, v;
        cin >> n >> m >> l >> v;
        vector<Car> a(n);
        vector<int> b(m);
        int tmpp, tmps, tmpa;
        bool equal0 = true;
        bool big = true;
        for (int i = 0; i < n; i++) {
            cin >> tmpp >> tmps >> tmpa;
            a[i].place = tmpp;
            a[i].speed = tmps;
            a[i].add = tmpa;
            if (tmpa > 0) {
                equal0 = false;
            } else if (tmpa < 0) {
                big = false;
                equal0 = false;
            }
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        if (equal0) {
            int ans = 0;
            int maxplace = 0;
            for (int i = 0; i < m; i++) {
                maxplace = max(b[i], maxplace);
            }
            for (int i = 0; i < n; i++) {
                if (a[i].place <= maxplace && a[i].speed > v) {
                    ans++;
                }
            }
            cout << ans << " " << m - 1 << endl;
        } else if (big) {
            int ans = 0;
            int maxplace = 0;
            for (int i = 0; i < m; i++) {
                maxplace = max(b[i], maxplace);
            }
            for (int i = 0; i < n; i++) {
                if (a[i].place <= maxplace && (double)sqrt(double(a[i].speed * a[i].speed + 2 * a[i].add * (maxplace - a[i].speed))) > v) {
                    ans++;
                }
            }
            cout << ans << " " << m - 1 << endl;
        } else {

        }   
    }
    return 0;
}