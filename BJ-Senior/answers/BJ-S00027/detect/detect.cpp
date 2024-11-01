#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdint>
#include <bits/stdc++.h>
#include <set>

using namespace std;

struct car {
    int d; // 从 d 位置驶入
    int v; // 汽车初始速度
    int a; // 加速度
};

struct TYPE {
    int n, m, l, v;
};

const int maxn = 1e5 + 5, maxm = 25;
car cars[maxn][maxm];
TYPE u[maxm];
int p[maxn][maxm];

bool check(int i, int j) {
    if (cars[i][j].d == 0) {
        return false;
    }
    int v = 0;
    for (int t = 0; t < cars[i][j].d; t++) {
        // t时间后的速度
        v = cars[i][j].v + (cars[i][j].a * t);
        // 下一次枚举的速度
        // int vNext = cars[i][j].v + (cars[i][j].a * (t + 1));
        // 位移
        int s = (cars[i][j].v * t) + (0.5 * cars[i][j].a * t * t);
        // 下一次位移
        int sNext = (cars[i][j].v * (t + 1)) + (0.5 * cars[i][j].a * (t + 1) * (t + 1));
        if (t - s > 0 && t - sNext < 0) {
            break;
        }
    }
    if (u[i].v >= v) {
        return false;
    } else {
        return true;
    }
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d%d%d%d", &u[i].n, &u[i].m, &u[i].l, &u[i].v);
        for (int j = 0; j < u[i].n; j++) {
            scanf("%d%d%d", &cars[i][j].d, &cars[i][j].v, &cars[i][j].a);
        }
        for (int j = 0; j < u[i].m; j++) {
            scanf("%d", &p[i][j]);
        }
    }
    int sum = 0;
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < u[i].n; j++) {
            if (check(i, j)) {
                sum++;
            }
        }
    }
    printf("%d %d", sum, sum);
    return 0;
}
