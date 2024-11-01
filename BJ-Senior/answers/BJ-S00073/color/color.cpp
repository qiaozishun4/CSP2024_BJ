#include<iostream>
using namespace std;
const int N = 20;

int t;
int n, res, ans;
int a[N];

int main() {

    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    cin >> t;
    while(t--) {
        res = ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for(int sta = 0; sta < (1 << n); sta++) {
            res = max(res, ans);
            ans = 0;
            int pre0 = -1, pre1 = -1;
            for(int i = 1; i <= n; i++) {
                if(sta & (1 << (i - 1))) {
                    if(pre1 != -1 && a[pre1] == a[i]) {
                        ans += a[i];
                    }
                    pre1 = i;
                } else {
                    if(pre0 != -1 && a[pre0] == a[i]) {
                        ans += a[i];
                    }
                    pre0 = i;
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}