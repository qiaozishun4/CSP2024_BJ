#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9;
const int MaxN = 200000 + 5, MaxM = 200000 + 5;

struct Car {
    long long d, v, a;
    Car() : d(0), v(0), a(0) {}
    Car(long long D, long long V, long long A) : d(D), v(V), a(A) {}
    long long CPV(long long P) {
        return v * v + 2 * a * (P - d);
    }
};

int T, N, M, ans, cnt;
long long L, V;
Car cars[MaxN];
long long detectors[MaxM];

int main() {
    #ifndef local
    const string fileName = "detect";
    FILE *temp;
    temp = freopen((fileName + ".in").c_str(), "r", stdin);
    temp = freopen((fileName + ".out").c_str(), "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (cin >> T; T--; ) {
        cin >> N >> M >> L >> V;
        for (int i = 0; i < N; i++) cin >> cars[i].d >> cars[i].v >> cars[i].a;
        for (int i = 0; i < M; cin >> detectors[i++]);
        if ([&](){ for (int i = 0; i < N; i++) if (cars[i].a != 0) return false; return true; }())
            cnt = [&](){ int res = 0; for (int i = 0; i < N; i++) res += cars[i].v > V && cars[i].d <= detectors[M - 1]; return res; }();
        if ([&](){ for (int i = 0; i < N; i++) if (cars[i].a <= 0) return false; return true; }())
            cnt = [&](){ int res = 0; for (int i = 0; i < N; i++) res += cars[i].d <= detectors[M - 1] && cars[i].CPV(detectors[M - 1]) > V * V; return res; }();
        cout << cnt << ' ';
        if ([&](){ for (int i = 0; i < N; i++) if (cars[i].a < 0) return false; return true; }()) cout << M - (cnt != 0) << '\n';
    }

    return 0;
}
