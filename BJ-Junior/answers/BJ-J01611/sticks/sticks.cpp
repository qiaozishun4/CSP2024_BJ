#include<bits/stdc++.h>
using namespace std;

const int maxN=50;
string recs[maxN];

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    int t, n, m, ii;

    recs[0]=recs[1]="-1";
    recs[2]="1"; recs[3]="7"; recs[4]="4";
    recs[5]="2"; recs[6]="6"; recs[7]="8";
    recs[8]="10"; recs[9]="18"; recs[10]="22";
    recs[11]="20"; recs[12]="28"; recs[13]="68";
    recs[14]="88"; recs[15]="108"; recs[16]="188"; recs[17]="200";
    recs[18]="208"; recs[19]="288"; recs[20]="688";

    cin >> t;
    while (t>0) {
        --t;
        cin >> n;
        if (n<=14) {
            cout << recs[n] << endl;
            continue;
        }
        m = n - 7 * (n/7 -2);
        cout << recs[m];
        for (ii=0 ; ii<n/7-2 ; ++ii) {
            cout << "8";
        }
        cout << endl;
    }


    return 0;
}

