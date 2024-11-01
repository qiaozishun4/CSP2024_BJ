#include <bits/stdc++.h>
using namespace std;
int n,a[100010],ans;
int main() {
    freopen("duel.in","r",stdin); freopen("duel.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1); int now = 0,j = 1,ans = 0;
    for(int i = 1;i <= n;) {
        int cnt1 = 0,cnt2 = 0;
        while(j <= n && a[j] == a[i]) {
            if(now == 0) cnt1++;
            else now--,cnt2++;
            ++j;
        }
        i = j; ans += cnt1; now += cnt1 + cnt2;
    }
    cout << ans;
    return 0;
}
