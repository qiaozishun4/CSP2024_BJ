#include<bits/stdc++.h>
using namespace std;


int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    int n, ii, jj, resu=52;
    string sline;
    unordered_map<char, unordered_map<char, bool> > recs;
    cin >> n;

    for (ii=1 ; ii<10 ; ++ii) {
        recs['D']['0'+ii] = recs['C']['0'+ii] = false;
        recs['H']['0'+ii] =recs['S']['0'+ii] = false;
    }
    recs['D']['T'] = recs['C']['T'] = recs['H']['T'] =recs['S']['T'] = false;
    recs['D']['J'] = recs['C']['J'] = recs['H']['J'] =recs['S']['J'] = false;
    recs['D']['Q'] = recs['C']['Q'] = recs['H']['Q'] =recs['S']['Q'] = false;
    recs['D']['K'] = recs['C']['K'] = recs['H']['K'] =recs['S']['K'] = false;
    recs['D']['A'] = recs['C']['A'] = recs['H']['A'] =recs['S']['A'] = false;

    for (ii=0 ; ii<n ; ++ii) {
        cin >>sline;
        if (!recs[sline[0]][sline[1]]) {
            --resu;
            recs[sline[0]][sline[1]] = true;
        }
    }
    cout << resu <<endl;

    return 0;
}

