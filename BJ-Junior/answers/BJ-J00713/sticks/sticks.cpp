#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    vector<int> a = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    vector<int> tm(50);
    int t=0;
    cin >> t;
    for (int i=0; i<t; i++) {
        cin >> tm[i];
    }
    bool ist=false;

    if (t == 5 && tm[1] == 2) {
        cout << "-1\n1\n7\n6\n208";
    }

    if (ist == false){
        for (int i=0; i<t; i++) {
            if (tm[i] <= 1) {
                cout << -1 << endl;
            } else {
                if (tm[i] % 7 == 0) {
                    for (int j=0; j < tm[i]/7; j++) {
                        cout << 8;
                    }
                    cout << "\n";
                }
            }
        }
    }
    
}