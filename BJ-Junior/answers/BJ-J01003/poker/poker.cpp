#include <iostream>
using namespace std;
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, a[13][4] = {}, ans = 0;
    string t, x = "A23456789TJQK",y = "DCHS";
    for (int i = 0; i < n-1; i++) cout << x[i];
    cin >> n;
    for (int i = 0; i < n; i++) {
		cin >> t;
		for (int j = 0; j < 13; j++) for (int k = 0; k < 4; k++) if (y[k] == t[0] && x[j] == t[1]) a[j][k] = 1;  
    }
    for (int i = 0; i < 13; i++) for (int j = 0; j < 4; j++) if (a[i][j] == 0) ans++;
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}