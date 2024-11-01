#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    bool Ds[13] = {};
    bool Cs[13] = {};
    bool Hs[13] = {};
    bool Ss[13] = {};
    for (int i = 0; i < n; i++) {
        char huase;
        cin >> huase;
        char dianshu;
        cin >> dianshu;
        int dian = 0;
        if (dianshu >= '2' && dianshu <= '9') {
            dian = dianshu - '0';
        }
        if (dianshu == 'T') {
            dian = 10;
        }
        if (dianshu == 'A') {
            dian = 1;
        }
        if (dianshu == 'J') {
            dian = 11;
        }
        if (dianshu == 'Q') {
            dian = 12;
        }
        if (dianshu == 'K') {
            dian = 13;
        }
        dian--;
        if (huase == 'D') {
            Ds[dian] = true;
        }
        if (huase == 'C') {
            Cs[dian] = true;
        }
        if (huase == 'H') {
            Hs[dian] = true;
        }
        if (huase == 'S') {
            Ss[dian] = true;
        }
    }
    int all = 0;
    for (int i = 0; i < 13; i++) {
        all += (!Ds[i]) + (!Cs[i]) + (!Hs[i]) + (!Ss[i]);
    }
    cout << all;
    return 0;
}
