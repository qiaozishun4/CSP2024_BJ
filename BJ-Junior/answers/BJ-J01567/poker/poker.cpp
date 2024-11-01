#include <bits/stdc++.h>
using namespace std;

int n;

int p[60];

int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        char x, y;
        cin >> x >> y;
        p[i] = (int)(x) * 256 + (int)(y);
    }
    sort(p + 1, p + n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += (p[i] != p[i + 1]);
    cout << 52 - cnt;
    return 0;
}
