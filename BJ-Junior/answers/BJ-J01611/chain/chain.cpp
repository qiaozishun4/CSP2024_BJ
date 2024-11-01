#include<bits/stdc++.h>
using namespace std;

// dx[a][b]: set of people who has a => b in one step
unordered_map<int, unordered_map<int, unordered_set<int> > > dx;
// p = recs[s][a]: in steps finish by a => last peopel p (0 for multi)
unordered_map<int, unordered_map<int, int> > recs;
int cl[200005];

int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);

    int t, n, k, q, l, r, c, ii, jj, kk, cmax;
    cin >> t;
    while (t>0) {
        --t; dx.clear(); recs.clear();
        cin >> n >> k >> q;
        for (ii=0 ; ii<n ; ++ii) {
            cin >> l;
            for (jj=0 ; jj<l ; ++jj) {
                cin >> cl[jj];
                for (kk=max(0, jj-k+1) ; kk<jj ; ++kk) {
                    if (dx[cl[kk]][cl[jj]].size()<3) {
                        dx[cl[kk]][cl[jj]].emplace(ii);
                        // cout << " chk1: " << cl[kk] << "=>" << cl[jj] << ": " << dx[cl[kk]][cl[jj]].size() << endl;
                    }
                }
            }
        }

        cmax=0; recs[0][1] = 0;

        while (q>0) {
            --q;
            cin >> r >> c;
            while (r>=cmax) {
                for (auto itrr: recs[cmax]) {
                    ii=itrr.first;
                    for (auto itrd: dx[ii]) {
                        if (recs[cmax+1].count(itrd.first)>0 && recs[cmax+1][itrd.first] == 0) {
                            continue;
                        }
                        if (itrd.second.size() == 1) {
                            if (itrd.second.count(itrr.second)>0) {
                                continue;
                            } else if (recs[cmax+1].count(itrd.first)==0) {
                                recs[cmax+1][itrd.first] = *(itrd.second.begin());
                            } else if (recs[cmax+1][itrd.first] != *(itrd.second.begin())) {
                                recs[cmax+1][itrd.first] = 0;
                            }
                        } else if (itrd.second.size() == 2 ) {
                            if (itrd.second.count(itrr.second)==0) {
                                recs[cmax+1][itrd.first] = 0;
                            } else {
                                for (auto kk: itrd.second) {
                                    if (kk != itrr.second) {
                                        jj = kk; break;
                                    }
                                }
                                if (recs[cmax+1].count(itrd.first)==0) {
                                    recs[cmax+1][itrd.first] = jj;
                                } else if (recs[cmax+1][itrd.first] != jj) {
                                    recs[cmax+1][itrd.first] = 0;
                                }
                            }
                        } else {
                            recs[cmax+1][itrd.first] = 0;
                        }
                    }
                }
                ++cmax;
            }
            cout << (recs[r].count(c)>0 ? 1 : 0) << endl;
        }
    }


    return 0;
}

