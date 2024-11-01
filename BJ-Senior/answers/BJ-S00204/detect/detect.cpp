#include <bits/stdc++.h>

using namespace std;

struct car {
    int d;  //初始距离
    int a;  //加速度
    int v;  //速度
    bool is, check;
    int bg, ed;
};

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T;
    cin >> T;
    for (int q = 0; q < T; q++) {
        int n, m, L, V;  //长度L，限速V
        cin >> n >> m >> L >> V;
        bool exit = false;
        if (n > 3010 || m > 3010) {
            exit = true;
        }
        car cars[n] = {};
        for (int i = 0; i < n; i++) {
            cin >> cars[i].d >> cars[i].v >> cars[i].a;
            cars[i].ed = 0;
            cars[i].bg = m;
            cars[i].check = false;
        }
        int p[m] = {};
        for (int i = 0; i < m; i++) {
            cin >> p[i];
        }
        if (exit) {
            continue;
        }
        int many[m] = {};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!cars[j].check) {
                    int d = p[i] - cars[j].d;
                    int vf = cars[j].a * d * 2 + cars[j].v * cars[j].v;
                    if (d < 0 || vf <= 0) {
                        vf = 0;
                    }
                    if (vf > 0 && vf <= V * V && cars[j].a <= 0) {
                        cars[j].check = true;
                        continue;
                    }
                    if (vf > V * V) {
                        cars[j].is = true;
                        if (cars[j].a >= 0) {
                            cars[j].bg = i;
                            cars[j].ed = m - 1;
                            for (int k = cars[j].bg; k <= cars[j].ed; k++) {
                                many[k]++;
                            }
                            cars[j].check = true;
                            continue;
                        }
                        if (i < cars[j].bg) {
                            cars[j].bg = i;
                        }
                        if (i > cars[j].ed) {
                            cars[j].ed = i;
                        }
                        many[i]++;
                    }
                }
            }
        }
        int num = 0;
        for (int i = 0; i < n; i++) {
            num += cars[i].is;
        }
        int k = 0;
        int empt = false;
        while (!empt) {
            int maxd = 0, index = 0;
            for (int i = 0; i < m; i++) {
                if (many[i] > maxd) {
                    maxd = many[i];
                    index = i;
                }
            }
            k++;
            /*cout << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << ischao[i][j] << " ";
                }
                cout << endl;
            }*/
            for (int i = 0; i < n; i++) {
                if (cars[i].bg <= index && cars[i].ed >= index) {
                    for (int j = cars[i].bg; j <= cars[i].ed; j++) {
                        many[j]--;
                    }
                    cars[i].bg = m + 1;
                    cars[i].ed = -1;
                }
            }
            int all = 0;
            for (int i = 0; i < m; i++) {
                all += many[i];
            }
            if (all == 0) {
                empt = true;
            }
        }
        if (num == 0) {
            k = 0;
        }
        cout << num << " " << m - k << endl;
    }
    return 0;
}
