#include <bits/stdc++.h>
using namespace std;

int n, b = 52, h, v;
bool o[5][14];
string c;

int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> c;

        if (c[0] == 'D') h = 1;
        if (c[0] == 'C') h = 2;
        if (c[0] == 'H') h = 3;
        if (c[0] == 'S') h = 4;

        if (c[1] == 'A') v = 1;
        if (c[1] == '2') v = 2;
        if (c[1] == '3') v = 3;
        if (c[1] == '4') v = 4;
        if (c[1] == '5') v = 5;
        if (c[1] == '6') v = 6;
        if (c[1] == '7') v = 7;
        if (c[1] == '8') v = 8;
        if (c[1] == '9') v = 9;
        if (c[1] == 'T') v = 10;
        if (c[1] == 'J') v = 11;
        if (c[1] == 'Q') v = 12;
        if (c[1] == 'K') v = 13;

        if (o[h][v] == false) {
            o[h][v] = true;
            b--;
        }
        //cout << h << " "  << v << endl;
    }
    cout << b;
	return 0;
}
