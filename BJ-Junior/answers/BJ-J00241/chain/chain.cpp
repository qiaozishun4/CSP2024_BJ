#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T;
    cin >> T;
    for (int qqw = 0; qqw < T; qqw++) {
        int n, k, q;
        cin >> n >> k >> q;
        //n个人，长度[2,k]，q个任务
        //一个q一次输出，可完成1，不可完成0
        vector<int> players[n] = {};
        for (int i = 0; i < n; i++) {
            int l;
            cin >> l;
            vector<int> v(l);
            for (int j = 0; j < l; j++) {
                cin >> v[j];
            }
            players[i] = v;
        }
        for (int i = 0; i < q; i++) {
            int r, c;
            cin >> r >> c;
            //r轮游戏，最后为c，起始是1
            bool is = false;
            if (r == 1) {
                for (int j = 0; j < n; j++) {
                    vector<int> v = players[j];
                    if (v[0] == 1) {
                        for (int l = 0; l < k; l++) {
                            if (v[l] == c) {
                                is = true;
                            }
                        }
                    }
                }
            }
            cout << is << endl;
        }
    }
    return 0;
}
