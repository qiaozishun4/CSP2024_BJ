#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[105];
bool cnt[4][15];
int change(char x) {
    int y;
    if (x == 'A') y = 1;
    else if (x == 'T') y = 10;
    else if (x == 'J') y = 11;
    else if (x == 'Q') y = 12;
    else if (x == 'K') y = 13;
    else y = x - '0';

    return y;
}
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", &a);
        if (a[0] == 'D') {
            cnt[0][change(a[1])] = 1;
        } else if (a[0] == 'C') {
            cnt[1][change(a[1])] = 1;
        } else if (a[0] == 'H') {
            cnt[2][change(a[1])] = 1;
        } else if (a[0] == 'S') {
            cnt[3][change(a[1])] = 1;
        }
    }
    for (int i = 0; i <= 3; i++) {
        for (int j = 1; j < 15; j++) {
            if (cnt[i][j]) ans++;
        }
    }
    printf("%d\n", 52 - ans);
    return 0;
}
