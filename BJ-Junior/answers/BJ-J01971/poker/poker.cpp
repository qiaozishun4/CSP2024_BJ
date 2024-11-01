#include <bits/stdc++.h>

using namespace std;
bool D[14];
bool C[14];
bool H[14];
bool S[14];
int ans = 0;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    char a;
    char b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        int x = 0;
        if (a == 'D') {
            if (b == 'T') {
                x = 10;
            }else if (b == 'J') {
                x = 11;
            }else if (b == 'Q') {
                x = 12;
            }else if (b == 'K') {
                x = 13;
            }else if (b == 'A') {
                x = 1;
            }else{
                x = b - '0';
            }
            D[x] = true;
        }
        if (a == 'C') {
            if (b == 'T') {
                x = 10;
            }else if (b == 'J') {
                x = 11;
            }else if (b == 'Q') {
                x = 12;
            }else if (b == 'K') {
                x = 13;
            }else if (b == 'A') {
                x = 1;
            }else{
                x = b - '0';
            }
            C[x] = true;
        }
        if (a == 'H') {
            if (b == 'T') {
                x = 10;
            }else if (b == 'J') {
                x = 11;
            }else if (b == 'Q') {
                x = 12;
            }else if (b == 'K') {
                x = 13;
            }else if (b == 'A') {
                x = 1;
            }else{
                x = b - '0';
            }
            H[x] = true;
        }
        if (a == 'S') {
            if (b == 'T') {
                x = 10;
            }else if (b == 'J') {
                x = 11;
            }else if (b == 'Q') {
                x = 12;
            }else if (b == 'K') {
                x = 13;
            }else if (b == 'A') {
                x = 1;
            }else{
                x = b - '0';
            }
            S[x] = true;
        }
    }
    for (int i = 1; i <= 13; i++) {
        if (!(C[i])) {
            ans++;
        }
    }
    for (int i = 1; i <= 13; i++) {
        if (!(D[i])) {
            ans++;
        }
    }
    for (int i = 1; i <= 13; i++) {
        if (!(H[i])) {
            ans++;
        }
    }
    for (int i = 1; i <= 13; i++) {
        if (!(S[i])) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
