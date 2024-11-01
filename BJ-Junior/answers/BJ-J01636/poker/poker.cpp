#include<bits/stdc++.h>
using namespace std;

int a1[15][20];

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    char a, b;
    cin >> n;
    while(n--) {
        cin >> a >> b;
        int i = 0;
        if(a == 'C') {
            i = 1;
        }
        if(a == 'H') {
            i = 2;
        }
        if(a == 'S') {
            i = 3;
        }
        int j = 1;
        if(b >= '2' && b <= '9') {
            j = b - '0';
        }
        if(b == 'T') {
            j = 10;
        }
        if(b == 'J') {
            j = 11;
        }
        if(b == 'Q') {
            j = 12;
        }
        if(b == 'K') {
            j = 13;
        }
        a1[i][j]++;
    }
    int ans = 0;
    for (int i = 0; i <= 3; ++i) {
        for (int j = 1; j <= 13; ++j) {
            if(!a1[i][j]) ++ans;
        }
    }
    cout << ans;
    return 0;
}