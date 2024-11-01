#include <bits/stdc++.h>
using namespace std;

bool haxi[4][20];
int cnt;

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        char c1, c2;
        int t1, t2;
        cin >> c1 >> c2;
        if(c1 == 'D') t1 = 0;
        if(c1 == 'C') t1 = 1;
        if(c1 == 'H') t1 = 2;
        if(c1 == 'S') t1 = 3;
        if(c2 == 'A') t2 = 1;
        if(c2 == 'T') t2 = 10;
        if(c2 == 'J') t2 = 11;
        if(c2 == 'Q') t2 = 12;
        if(c2 == 'K') t2 = 13;
        if(c2 >= '2' && c2 <= '9') t2 = c2 - '0';
        haxi[t1][t2] = 1;
    }
    for(int i = 0; i < 4; i++) {
        for(int j = 1; j <= 13; j++) {
            if(!haxi[i][j]) cnt++;
        }
    }
    cout << cnt;
}
