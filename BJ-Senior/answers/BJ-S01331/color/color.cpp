#include<bits/stdc++.h>
using namespace std;

const int maxN = int(2e5) + 10;
int va[maxN];
// last red => last blue => score
unordered_map<int, unordered_map<int, int64_t> > rec1, rec0, *cr, *pr, *tmp;

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    int t, n, ii, lr, lb;
    int64_t resu, ls;
    cin >> t;
    while (t>0) {
        --t;
        resu = 0; rec1.clear();
        cin >> n;
        for (ii=0 ; ii<n ; ++ii) {
            cin >> va[ii];
        }
        cr = &rec1; pr = &rec0;
        rec1[0][0] = 0;

        for (ii=0 ; ii<n ; ++ii) {
            tmp=pr; pr=cr; cr=tmp;
            cr->clear();
            for (auto itrr: (*pr)) {
                lr = itrr.first;
                for (auto itrb: itrr.second) {
                    lb = itrb.first; ls = itrb.second;
                    // red
                    (*cr)[va[ii]][lb] = max(((lr==va[ii]) ? (ls+va[ii]) : ls), (*cr)[va[ii]][lb]);
                    // blue
                    (*cr)[lr][va[ii]] = max(((lb==va[ii]) ? (ls+va[ii]) : ls), (*cr)[lr][va[ii]]);
                    resu = max(resu, max((*cr)[va[ii]][lb], (*cr)[lr][va[ii]]));
                }
            }
        }
        cout << resu << endl;
    }

    return 0;
}
