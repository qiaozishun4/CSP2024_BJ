#include <bits/stdc++.h>

using namespace std;

int n;
bool poker[5][14];
int ans = 52;

int change(char c) {
    if('2' <= c && c <= '9') return int(c - '0');
    switch(c) {
        case 'A':
            return 1;
        case 'T':
            return 10;
        case 'J':
            return 11;
        case 'Q':
            return 12;
        case 'K':
            return 13;
        case 'D':
            return 1;
        case 'C':
            return 2;
        case 'H':
            return 3;
        case 'S':
            return 4;
    }
}

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i ++) {
        char a, b;
        cin >> a >> b;
        if(poker[change(a)][change(b)] == 0) {
            poker[change(a)][change(b)] = 1;
            ans --;
        }
    }
    cout << ans << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
