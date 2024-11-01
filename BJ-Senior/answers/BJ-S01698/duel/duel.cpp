#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N];
int cnt;
int i, j = 1;

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 2; i <= n; i++) {
        if(a[i] > a[j]) {
            j++;
        }
    }
    cout << n - (j - 1);

}
