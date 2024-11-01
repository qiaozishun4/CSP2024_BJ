#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int n2 = n;
    long long a[100000];
    freopen("duel.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] >= a[i + 1]) {
            a[i + 1] = 0;
            n2 -= 1;
        } else {
            a[i] = 0;
            n2 - 1
        }
    }
    freopen("duel.out", "w", stdout);
    cout << n2 << endl;
    return 0;
}