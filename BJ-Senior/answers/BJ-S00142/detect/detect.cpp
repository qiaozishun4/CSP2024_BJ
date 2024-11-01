 #include<bits/stdc++.h>

 using namespace std;

 const int N = 1e5 + 10;

int T, n, m, L, V;
int d[N], v[N], a[N], p[N];

 int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    cin >> T;
    int TT = T;
    bool flag1 = true, flag2 = true, flag3 = true;
    while (TT--) {
        scanf("%d%d%d%d", &n, &m, &L, &V);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", &d[i], &v[i], &a[i]);
            if (!(a[i] == 0))   flag1 = false;
            if (!(a[i] > 0))   flag2 = false;
            if (!(a[i] < 0))   flag3 = false;
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &p[i]);
        }

        int maxp = -1;
        for (int i = 1; i <= m; i++) {
            maxp = max(maxp, p[i]);
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (d[i] <= maxp && v[i] > V) {
                cnt++;
            }
        }


        if (cnt != 0)
            printf("%d %d\n", cnt, n - 1);
        else
            printf("%d %d\n", cnt, n );
    }

    /*if (flag1) {

        int maxp = -1;
        for (int i = 1; i <= m; i++) {
            maxp = max(maxp, p[i]);
        }

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (d[i] <= maxp && v[i] > V) {
                cnt++;
            }
        }

        printf("%d %d\n", cnt, n - 1);
    }*/

    return 0;
 }
