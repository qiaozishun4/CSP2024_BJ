#include <bits/stdc++.h>
using namespace std;
int n, a[100005], ans;
bool flag[100005], num[100005];
int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        num[a[i]]++;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1;i <= n;i++) {
        int p = upper_bound(a + 1, a + n + 1, a[i]) - a;
        //cout << p << '\n';

        if (a[p] <= a[i] or p > n) {
            break;
        }
        else if (flag[p] == 1) {
            int j = p;

            //if (!num[a[j]])
            //    break;

            for (;j <= n;j++) {
                if (!flag[j])
                    break;
            }
            //cout << j;

            if (!flag[j] and j <= n) {
                ans++;
                flag[j] = 1;
                //num[a[j]] -= 1;

            } else {
                break;
            }
        }
        else {
            ans++;
            flag[p] = 1;
        }
    }
    ans = n - ans;
    cout << ans;
    return 0;
}




















