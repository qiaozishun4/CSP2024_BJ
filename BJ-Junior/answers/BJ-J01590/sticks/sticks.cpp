#include<bits/stdc++.h>
using namespace std;
int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main() {
    freopen ("sticks.in", "r", stdin);
    freopen ("sticks.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        while (n > 0) {
            if (n == 8) {
                n -= 8;
                printf("%d%d", 1, 9);
            }else if (n - 7 >= 0) {
                n -= 7;
                printf("%d", 8);
            }
            //cout << ">>>" << ans << endl;
        }
        printf("\n");
    }
    return 0;
}