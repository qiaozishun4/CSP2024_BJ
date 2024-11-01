#include <bits/stdc++.h>

using namespace std;

int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};//所需木棍

string getfirst(int n) {
    int gs = (n - 1) / 7 + 1;
    int ra[gs] = {};
    int index = 0;
    int jizhun = (gs - 1) * 7;
    for (int i = 0; i < 10; i++) {
        if (n - num[i] <= jizhun) {
            if (((index == 0) && (i == 0)) || n - num[i] < 0) {
                continue;
            }
            n -= num[i];
            jizhun -= 7;
            ra[index] = i;
            index++;
            i = -1;
        }
        if (jizhun == -7) {
            break;
        }
    }
    string r = "";
    for (int i = gs - 1; i >= 0; i--) {
        r = (char) (ra[i] + '0') + r;
    }
    return r;
}

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    cin >> T;
    for (int q = 0; q < T; q++) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << -1 << endl;
            continue;
        }
        cout << getfirst(n) << endl;
    }
    return 0;
}
