#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll num[MAXN];
int color[MAXN];
int numind[MAXN];
ll T, n;
int main() {
//    freopen("color2.in", "r", stdin);
    scanf("%lld", &T);
    for (int t = 1; t <= T; t++) {
        memset(color, 0, sizeof(color));
        memset(num, 0, sizeof(num));
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &num[i]);
        }
      //  for (int i = 1; i <= n; i++) {
      //      cout << num[i] << ' ';
       // }
        int ans1 = 0, ans2 = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            memset(numind, 0, sizeof(numind));
            int pre1 = 0, pre2 = 0;
            ans1 = 0;
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (num[j] == num[i] || color[j] == 1) {
                    if (num[j] == num[i]) {
                        cnt++;
                        //cout << "I,J:" << i << ' ' << j << ' ' << "NUM:" << num[i] << endl;
                        numind[cnt] = j;
                    }
                    if (num[pre1] == num[j]) {
                        ans1 += num[j];
                    }
                    pre1 = j;
                    continue;
                }
                if (color[j] == 2) {
                    if (num[pre2] == num[j]) {
                        ans1 += num[j];
                    }
                    pre2 = j;
                    continue;
                }
            }
            pre1 = 0, pre2 = 0;
            ans2 = 0;

            for (int j = 1; j <= n; j++) {
                if (num[j] == num[i] || color[j] == 2) {
                    if (num[pre2] == num[j]) {
                        ans2 += num[j];
                    }
                    pre2 = j;
                    continue;
                }
                if (color[j] == 1) {
                    if (num[pre1] == num[j]) {
                        ans2 += num[j];
                    }
                    pre1 = j;
                    continue;
                }
            }
            if (ans1 > ans2) {
                ans = ans1;
                for (int j = 1; j <= cnt; j++) {
                    color[numind[j]] = 1;
                }
            }
            else {
                ans = ans2;
                for (int j = 1; j <= cnt; j++) {
                    color[numind[j]] = 2;
                }
            }
    //        cout << "I:" << i << ' ' << "CNT:" << cnt << endl;
     //       cout << "ans:" << ans << endl;;
        }
     //   for (int i = 1; i <= n; i++) {
     //       cout << color[i] << ' ';
     //   }
     //   cout << endl;
        cout << ans << endl;
    }
    return 0;
}
