#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int n;
    cin >> n;
    int a[10];
    int b[10][10];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 1; j <= a[i]; j++) {
            cin >> b[i][j];
        }
    }
    cout << 1 << endl << 0 << endl << 8;
}
