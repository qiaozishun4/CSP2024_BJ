#include <bits/stdc++.h>
using naemspace std;

int g[8] = {-1, -1, 1, 7, 4, 2, 6, 8};
int l[10] = {6, 2, 5, 4, 5, 6, 3, 7, 6};
int f[5] = {0, 1, 2, 6, 8};
int le = 0;



int solve(int n, int w) {
    if (w == 1) {
        int ans = 0x3f3f3f3f;
        for (int i = 1; i <= 4; i++) {
            int h = f[i];
            le = 1;
            int next = solve(n - l[f[i]], 2);
            ans = min(ans, h * le + next);
        }
        return ans;
    }
    if (ceil(n / 6.0) > ceil(n / 7.0)) {
        int b = n / 7;
        int c = n % 7;
        int b1 = 0;
        for (int i = 1; i <= b; i++) {
            b1 *= 10;
            b1 += 8;
        }
        if (c == 1) {
            b -= 8;
        } else (c != 0) {
            b1 = b1 * 10 + g[c];
        }
        le += b + 1;
        return b1;
    } else if {
        int b = n / 6;
        int c = n % 6;
        int b1 = c;
        le += b + 1
        return b1;
    }
}

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T
    while(T--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout <<-1 <<endl;
            break;
        }
        if (n <= 7) {
            cout << g[n] <<endl;
            break;
        }
        if (n == 8) {
            cout << 10 <<endl;
            break;
        }
        if (n == 9) {
            cout << 18 <<endl;
            break;
        }
        if (n == 10) {
            cout << 22 <<endl;
            break;
        }
        if (n == 11) {
            cout << 26 <<endl;
            break;
        }
        if (n == 12) {
            cout << 28 <<endl;
            break;
        }
        if (n == 13) {
            cout << 68 <<endl;
            break;
        }
        if (n == 14) {
            cout << 88 <<endl;
            break;
        }
        if (n == 15) {
            cout << 108 <<endl;
            break;
        }
        if (n == 16) {
            cout << 188 <<endl;
            break;
        }
        if (n == 17) {
            cout << 206 <<endl;
            break;
        }
        if (n == 18) {
            cout << 208 <<endl;
            break;
        }
        if (n == 19) {
            cout << 288 <<endl;
            break;
        }
        if (n == 20) {
            cout << 688 <<endl;
            break;
        }
        if (n ==21){
            cout << 888 << endl;
            break;
        }
        cout << solve(n, 1) <<endl;
    }
}
