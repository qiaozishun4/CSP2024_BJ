#include<bits/stdc++.h>
using namespace std;

const int maxN = int(1e5) + 10;
int nr[maxN];

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    int n, ii, jj, r, maxr=0, minr=int(2e5), jlft;
    cin >> n;
    memset(nr, 0, sizeof(nr));
    for (ii=0 ; ii<n ; ++ii) {
        cin >> r; nr[r] += 1;
        maxr = max(maxr, r);
        minr = min(minr, r);
    }
    if (n<=1) { cout << n << endl; return 0; }

    for (ii=jj=minr,jlft=nr[jj] ; jj<=maxr ; ) {
        if (ii == jj) {
            ++jj; jlft=nr[jj];
        } else if (nr[ii] <= jlft) {
            jlft -= nr[ii]; n -= nr[ii];
            ++ii;
        } else {
            nr[ii] -= jlft; n -= jlft;
            ++jj; jlft = nr[jj];
        }
    }
    cout << n << endl;

    return 0;
}
