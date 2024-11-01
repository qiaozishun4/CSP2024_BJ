//BJ-J00771 chain.cpp
//123456 WA 7 AC
//Locked
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int n, k, q;

int p1[100005], p1c = 0;
int pc[100005], pcc = 0;

vector <int> v[100005];

int R1(int c) {
    for (int i = 1; i <= n; i++) {
        int len = v[i].size();
        p1c = pcc = 0;
        for (int j = 0; j < len; j++) {
            if (v[i][j] == 1) p1[++p1c] = j;
            if (v[i][j] == c) pc[++pcc] = j;
        }
        for (int i = 1; i <= p1c; i++) {
            for (int j = 1; j <= pcc; j++) {
                if (abs(p1[i] - pc[j]) < k && abs(p1[i] - pc[j]) >= 1) return 1;
            }
        }
    }
    return 0;
}

int Solve(int c) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int len = v[i].size();
        for (int j = 0; j < len; j++) {
            if (v[i][j] == c) {
                ans = 1;
                break;
            }
        }
        if (ans) break;
    }
    return ans;
}

int main() {

    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);

    int TEST;
    cin >> TEST;
    while (TEST--) {
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i++) {
            v[i].clear();
            int l;
            cin >> l;
            for (int j = 1; j <= l; j++) {
                int x;
                cin >> x;
                v[i].push_back(x);
            }
        }
        while (q--) {
            int r, c;
            cin >> r >> c;
            if (r == 1) cout << R1(c) << endl;
            else cout << Solve(c) << endl;
        }
    }
    return 0;
}
