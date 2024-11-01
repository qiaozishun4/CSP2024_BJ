#include<bits/stdc++.h>
using namespace std;
const int maxcol = 4 + 10;
const int maxnum = 13 + 10;

int n;
char c, a;

bool hv[maxcol][maxnum];
int ans;

int main () {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    scanf("%i", &n);
    for (int i = 1; i <= n; i++) {
        scanf(" %c %c", &c, &a);

        int col, num;
        if (c == 'D') {
            col = 1;
        }else if (c == 'C') {
            col = 2;
        }else if (c == 'H') {
            col = 3;
        }else if (c == 'S') {
            col = 4;
        }
        if (a == 'A') {
            num = 1;
        }else if ('2' <= a && a <= '9') {
            num = a - '0';
        }else if (a == 'T') {
            num = 10;
        }else if (a == 'J') {
            num = 11;
        }else if (a == 'Q') {
            num = 12;
        }else if (a == 'K') {
            num = 13;
        }
        hv[col][num] = true;
        // cerr << i << ' ' << col << ' ' << num << '\n';
    }
    
    for (int col = 1; col <= 4; ++col) {
        for (int num = 1; num <= 13; ++num) {
            if (!hv[col][num]) {
                ++ans;
                // cerr << '\t' << col << ' ' << num << '\n';
            }
        }
    }

    printf("%i\n", ans);
    return 0;
}