//csp-j 1
//2024.10.26
//silu:for
//time:O(n)
//mem:O(1)
//tiaoshi;
//  1)
#include <bits/stdc++.h>
using namespace std;
//const int maxn = 57;
bool a[9][18] = {0};
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int x, y;
        string s;
        cin >> s; //in
        if (s[0] == 'D') {
            x = 1;
        } else if (s[0] == 'C') {
            x = 2;
        } else if (s[0] == 'H') {
            x = 3;
        } else if (s[0] == 'S') {
            x = 4;
        }
        if (s[1] == 'A') {
            y = 1;
        } else if (s[1] == 'T') {
            y = 10;
        } else if (s[1] == 'J') {
            y = 11;
        } else if (s[1] == 'Q') {
            y = 12;
        } else if (s[1] == 'K') {
            y = 13;
        } else {
            y = s[1] - '0';
        }
        a[x][y] = 1;
    }
    for (int i = 0; i <= 8; i++) {
        for (int j = 0; j <= 17; j++) {
            if (a[i][j] == 1){
                sum++;
            }
        }
    }
    cout << 52 - sum; //out
    return 0;
}