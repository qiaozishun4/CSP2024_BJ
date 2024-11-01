#include <bits/stdc++.h>
#define c1 SharpSmile_AK_IOI
#define c2 SegTree_AK_IOI
using namespace std;
bool b[114][514];
inline int hs (char c) {//hua se
    if (c == 'D') {
        return 1;
    }
    if (c == 'C') {
        return 2;
    }
    if (c == 'H') {
        return 3;
    }
    if (c == 'S') {
        return 4;
    }
    return 0;
}
inline int ds (char c) {//dianshu
    if (c == 'A') {
        return 1;
    }
    if (c == 'T') {
        return 10;
    }
    if (c == 'J') {
        return 11;
    }
    if (c == 'Q') {
        return 12;
    }
    if (c == 'K') {
        return 13;
    }
    return (c - '0');
}
int n;
int main () {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++) {
        char c1,c2;
        cin >> c1 >> c2;
        b[hs(c1)][ds(c2)] = 1;
    }
    int ans = 52;
    for (int i = 1;i <= 4;i++) {
        for (int j = 1;j <= 13;j++) {
            if (b[i][j]) {
                ans--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}