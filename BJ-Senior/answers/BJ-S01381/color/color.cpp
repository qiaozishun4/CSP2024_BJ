#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
using namespace std;

int f(vector<int> a, int p, vector<bool> color) {
    int rednow = 0;
    int bluenow = 0;
    int i = p - 1;
    while (i >= 0 && color[i] == false) {
        i--;
    }
    if (!(i == 0 && !color[i]) && a[i] == a[p]) {
        rednow = a[i];
    }
    i = p - 1;
    while (i >= 0 && color[i] == true) {
        i--;
    }
    if (!(i == 0 && !color[i]) && a[i] == a[p]) {
        bluenow = a[i];
    }
    if (p == a.size() - 1) {
        return max(rednow, bluenow);
    }
    color[p] = true;
    int ans1 = rednow + f(a, p + 1, color);
    color[p] = false;
    int ans2 = bluenow + f(a, p + 1, color);
    return max(ans1, ans2);
}


int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<bool> color(n, false);
        cout << f(a, 0, color) << endl;
    }
}