//LMY bao you zheng jie bie gua!!!~~~
#include <bits/stdc++.h>
#define sort stable_sort
using namespace std;
const int MAXN = 1e5 + 5;
int n, a[MAXN], cnt1[MAXN], cnt2[MAXN];
int maxn = 0;
int main(){
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        cnt1[a[i]]++;
        cnt2[a[i]]++;
        maxn = max(maxn, a[i]);
    }
    int j = 0;
    for (int i = 1; i <= maxn; i++){
        if (cnt2[i] != 0){
            while (j < i){
                int d = min(cnt1[j], cnt2[i]);
                cnt1[j] -= d;
                cnt2[i] -= d;
                if (cnt2[i] == 0) break;
                j++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= maxn; i++){
        ans += cnt1[i];
    }
    cout << ans << endl;
    return 0;
}
