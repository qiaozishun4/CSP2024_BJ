#include <iostream>
#include <cstdio>
using namespace std;
long long n, ia, ib, ans = 0;
char a, b;
bool h[15][25] = {false};
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    scanf("%lld", &n);
    for(long long i = 0; i < n; i++) {
        cin >> a >> b;
        if(a == 'D') {
            ia = 1;
        }
        else if(a == 'C') {
            ia = 2;
        }
        else if(a == 'H') {
            ia = 3;
        }
        else if(a == 'S'){
            ia = 4;
        }
        if(b == 'A') {
            ib = 1;
        }
        else if(b == 'T') {
            ib = 10;
        }
        else if(b == 'J') {
            ib = 11;
        }
        else if(b == 'Q') {
            ib = 12;
        }
        else if(b == 'K') {
            ib = 13;
        }
        else {
            ib = b - '0';
        }
        h[ia][ib] = true;
    }
    for(long long i = 1; i <= 4; i++) {
        for(long long j = 1; j <= 13; j++) {
            if(h[i][j] == false) {
                ans++;
            }
        }
    }
    printf("%lld", ans);
    return 0;
}
