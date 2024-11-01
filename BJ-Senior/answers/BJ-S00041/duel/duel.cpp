#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
int n, num, ans, maxn;
struct Node { int cnt, flag; }sum[MAX];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        sum[num].cnt += 1, maxn = max(maxn, num);
    }
    for (int i = 1; i <= maxn; i++) {
        if (sum[i].cnt == 0) continue;
        for (int j = 1; j <= i - 1; j++) {
            if (sum[i].flag == sum[i].cnt) break;
            if ((sum[i].cnt - sum[i].flag) - sum[j].cnt < 0) {
                sum[j].cnt = sum[j].cnt - (sum[i].cnt - sum[i].flag);
                sum[i].flag = sum[i].cnt;
                break;
            }
            else {
                sum[i].flag += (sum[i].cnt - sum[i].flag) - sum[j].cnt;
                sum[j].cnt = 0;
            }
        }
    }
    for (int i = 1; i <= maxn; i++) {
        ans += sum[i].cnt;
    }
    cout << ans;
    fclose(stdin), fclose(stdout);
    return 0;
}
