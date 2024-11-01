#include<bits/stdc++.h>
using namespace std;

int n, ans;
int d[20], c[20], h[20], s[20];
int mapper(char x) {
    if(x=='A') return 1;
    if(x=='2') return 2;
    if(x=='3') return 3;
    if(x=='4') return 4;
    if(x=='5') return 5;
    if(x=='6') return 6;
    if(x=='7') return 7;
    if(x=='8') return 8;
    if(x=='9') return 9;
    if(x=='T') return 10;
    if(x=='J') return 11;
    if(x=='Q') return 12;
    if(x=='K') return 13;
    else return 0;
}
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        char opt, x;
        cin >> opt >> x;
        if(opt=='D') d[mapper(x)]++;
        else if(opt=='C') c[mapper(x)]++;
        else if(opt=='H') h[mapper(x)]++;
        else s[mapper(x)]++;
    }
    for(int i = 0; i <= 20; i++) {
        if(d[i]) ans++;
        if(c[i]) ans++;
        if(h[i]) ans++;
        if(s[i]) ans++;
    }
    cout << 52-ans << '\n';
    return 0;
}
