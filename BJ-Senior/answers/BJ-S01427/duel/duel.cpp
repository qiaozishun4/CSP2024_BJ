#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i) {
        for(int j = i; j < n; ++j) {
            if(a[i] > a[j]) {
                int x = a[i];
                a[i] = a[j];
                a[j] = x;
            }
        }
    }
    int numbera = n;
    for(int i = 1; i < n; ++i) {
        for(int j = i; j >= 0; --j) {
            if(a[i] > a[j]) {
                numbera = numbera - 1;
                a[j] = 200000;
                break;
            }
        }
    }
    cout << numbera;
    return 0;
}
