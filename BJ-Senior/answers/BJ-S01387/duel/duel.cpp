// cout << "hello_world" << endl;
#include <bits/stdc++.h>
using namespace std;
int cnt1 = 0, a[100001];
struct monster {
    int life = 0, ac = 0;
} b[100001];
void duel(int nt, int n, monster box[]) {
    for (int i = 1; i <= n; ++i)
        for (int j = i - 1; j >= 1; --j)
            if (box[i].ac && box[i].life && box[j].life) {
                int a = box[i].ac, b = box[j].life;
                box[i].ac = max(0, a - b), box[j].life = max(0, b - a);
            }
    int cnt = 0, sum = 0;
    for (int i = 1; i <= n; ++i)
        if (box[i].life)
            box[++cnt] = box[i], sum += box[cnt].life;
    if (nt != sum) duel(sum, cnt, box);
    else cout << sum << endl;
}
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n = 0, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        if (i != 1 && a[i] == a[i - 1]) ++b[cnt].life, ++b[cnt].ac;
        else ++b[++cnt].life, ++b[cnt].ac;
    duel(n, cnt, b);
    return 0;
 }