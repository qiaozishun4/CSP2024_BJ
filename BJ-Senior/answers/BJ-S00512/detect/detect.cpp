#include <bits/stdc++.h>
#define N 3000
//#define DEBUG
using namespace std;
int T, n, m, l, vmax;
struct car {
    int d, v, a;
    vector<int> cs;
} b[N];
struct csy {
    int d;
    vector<int> cs;
} p[N];
bool cmp(csy a, csy b) { return a.cs.size() < b.cs.size(); }

void op(int i, int j) { b[i].cs.push_back(j); p[i].cs.push_back(i); }

int main()
{
    freopen("detect1.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    while (T--) {
        int resa = 0, resb = 0;
        for (int i = 0; i < n; i++) {
            b[i].d = b[i].v = b[i].a = 0;
            b[i].cs.clear();
        }
        for (int i = 0; i < m; i++) {
            p[i].d = 0;
            p[i].cs.clear();
        }
        cin >> n >> m >> l >> vmax;
        for (int i = 0; i < n; i++) cin >> b[i].d >> b[i].v >> b[i].a;
        for (int i = 0; i < m; i++) cin >> p[i].d;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (b[i].d > p[j].d) continue;
                if (b[i].d == p[j].d && b[i].v > vmax) {
                    op(i, j);
                    continue;
                }
                int s = p[j].d - b[i].d, v = b[i].v, a = b[i].a;
                double sv = sqrt(v*v+2*a*s);

                #ifdef DEBUG
                printf("[Debug] carnum: %d s: %d v0: %d a: %d sv: %lf cs: %d\n", i+1, s, v, a, sv, (sv>v));
                #endif // DEBUG

                if (sv > vmax) op(i, j);
                if (sv > vmax && a >= 0) {
                    for (int k = j+1; k < m; k++) op(i, k);
                    break;
                }

                if (sv <= vmax && a <= 0) break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (b[i].cs.size() != 0) {
                //cout << i << ' ' << b[i].cs.size() << '\n';
                resa++;
            }
        }
        sort(p, p+n, cmp);
        for (int i = 0; i < m; i++) {
            bool flag = 0;
            for (int j = 0; j < p[i].cs.size(); j++) {
                if (b[p[i].cs[j]].cs.size() <= 1) flag = 1; // necessary csy
            }
            resb += (!flag); // not necessary
        }
        cout << resa << ' ' << resb << '\n';
    }
    return 0;
}
