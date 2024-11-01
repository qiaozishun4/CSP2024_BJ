//csp-j 3
//2024.10.26
//silu:init()
//time:O(t)
//mem:O(1)
//tiaoshi:
//  1)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const short maxt = 55;
int a[maxn];
short base[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int ans[maxt];
void init()
{
    for (int i = 1; i <= maxn; i++) {
        int sum = 0;
        int x = i;
        while (x != 0) {
            int now = x % 10;
            sum += base[now];
            x /= 10;
        }
        a[i] = sum;
    }
}
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    init();
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n; //in
        bool flag = 0;
        for (int j = 1; j <= maxn; j++) {
            if (a[j] == n) {
                flag = 1;
                ans[i] = j;
                break;
            }
        }
        if (!flag) {
            ans[i] = -1;
        }
    }
    for (int i = 1; i <= t - 1; i++) {
        cout << ans[i] << endl;
    }
    cout << ans[t]; //out
    return 0;
}