#include<bits/stdc++.h>
using namespace std;
bool b[10][20];
int n, cnt = 52;
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int T1, T2;
        if (s[0] == 'D') T1 = 1;
        if (s[0] == 'C') T1 = 2;
        if (s[0] == 'H') T1 = 3;
        if (s[0] == 'S') T1 = 4;
        if (s[1] <= '9' && s[1] >= '2') T2 = s[1] - '0';
        if (s[1] == 'A') T2 = 1;
        if (s[1] == 'T') T2 = 10;
        if (s[1] == 'J') T2 = 11;
        if (s[1] == 'Q') T2 = 12;
        if (s[1] == 'K') T2 = 13;
        b[T1][T2] = true;
    }
    for (int i = 1; i <= 4; i++) for (int j = 1; j <= 13; j++) if (b[i][j]) cnt--;
    printf("%d", cnt);
    return 0;
}
