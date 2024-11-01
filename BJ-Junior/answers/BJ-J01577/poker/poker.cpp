#include <iostream>
using namespace std;

int n;
bool a[130][130];
int ans;

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char x, y;
        cin >> x >> y;
        if (!a[x][y]) {
            a[x][y] = true;
            ans++;
        }
    }
    cout << 52 - ans << endl;
    return 0;
}
