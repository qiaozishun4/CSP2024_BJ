#include <iostream>
#include <algorithm>
using namespace std;
int n, r[100005], cnt, cur;
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    cnt = n;
    for (int i = 1; i <= n; i++) cin >> r[i];
    sort(r + 1, r + n + 1);
    cur = 1;
    for (int i = 2; i <= n; i++) if (r[i] > r[cur]) cnt--, cur++;
    cout << cnt;
    return 0;
}