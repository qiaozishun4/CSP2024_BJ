// 勤奋 求实 创造 奉献
// Luogu Coder12823
// 塞尔达是天

#include <bits/stdc++.h>
using namespace std;

bool pokers[5][15];

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    scanf("%d", &n);
    while (n--) {
        string tmp;
        cin >> tmp;
        char color = tmp[0], num = tmp[1];
        
        int x;
        if (num == 'A') {
            x = 1;
        } else if (num >= '2' && num <= '9') {
            x = (num - '0');
        } else if (num == 'T') {
            x = 10;
        } else if (num == 'J') {
            x = 11;
        } else if (num == 'Q') {
            x = 12;
        } else {
            x = 13;
        }

        if (color == 'D') {
            // 方片
            pokers[1][x] = true;
        } else if (color == 'C'){
            // 草花
            pokers[2][x] = true;
        } else if (color == 'H') {
            // 红桃
            pokers[3][x] = true;
        } else {
            // 黑桃
            pokers[4][x] = true;
        }
    }

    int res = 52;   
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 13; j++) {
            if (pokers[i][j] == 1) {
                res--;
            }
        }
    }
    printf("%d\n", res);

    return 0;
}

// C C F 快让我得 1=