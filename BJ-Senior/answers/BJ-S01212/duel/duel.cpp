#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;

int n;

int r[MAX];
int p[MAX];

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    cin >> n;

    for(int i = 1; i <= n; i++) cin >> r[i];

    sort(r+1, r+n+1);

    if(r[1] == r[n]) {
        cout << n;
        return 0;
    }

    bool qp = 1;
    for(int i = 1; i < n; i++) {
        if(r[i] == r[i+1]) {
            qp = 0;
            i = n;
        }

    }

    int k = r[1];
    int num = 1;
    int sur = 0;

    for(int i = 2; i <= n; i++) {
        if(r[i] == k) num++;
        else {
            p[++sur] = num;
            num = 1;
            k = r[i];
        }
    }
    if(num)
        p[++sur] = num;

    int maxx = -1;

    for(int i = 1; i <= sur; i++) {
        maxx = max(maxx, p[i]);
    }

    cout << maxx << endl;
    return 0;
}
