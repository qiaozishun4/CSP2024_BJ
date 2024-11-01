#include<bits/stdc++.h>

using namespace std;

int n;
int all[4][20] = {0};
char card[2];
int ans = 0;

int main() {
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for (int i = 0;i < n;i++) {
        for (int j = 0;j < 2;j++) {
            cin >> card[j];
        }
        if (card[0] == 'D') {
            if (card[1] == 'T') {
                all[0][10]++;
            }
            else if (card[1] == 'J') {
                all[0][11]++;
            }
            else if (card[1] == 'Q') {
                all[0][12]++;
            }
            else if (card[1] == 'K') {
                all[0][13]++;
            }
            else if (card[1] == 'A') {
                all[0][1]++;
            }
            else {
                all[0][int(card[1] - '0')]++;
            }
        }
        else if (card[0] == 'C') {
            if (card[1] == 'T') {
                all[1][10]++;
            }
            else if (card[1] == 'J') {
                all[1][11]++;
            }
            else if (card[1] == 'Q') {
                all[1][12]++;
            }
            else if (card[1] == 'K') {
                all[1][13]++;
            }
            else if (card[1] == 'A') {
                all[1][1]++;
            }
            else {
                all[1][int(card[1] - '0')]++;
            }
        }
        else if (card[0] == 'H') {
            if (card[1] == 'T') {
                all[2][10]++;
            }
            else if (card[1] == 'J') {
                all[2][11]++;
            }
            else if (card[1] == 'Q') {
                all[2][12]++;
            }
            else if (card[1] == 'K') {
                all[2][13]++;
            }
            else if (card[1] == 'A') {
                all[2][1]++;
            }
            else {
                all[2][int(card[1] - '0')]++;
            }
        }
        else if (card[0] == 'S') {
            if (card[1] == 'T') {
                all[3][10]++;
            }
            else if (card[1] == 'J') {
                all[3][11]++;
            }
            else if (card[1] == 'Q') {
                all[3][12]++;
            }
            else if (card[1] == 'K') {
                all[3][13]++;
            }
            else if (card[1] == 'A') {
                all[3][1]++;
            }
            else {
                all[3][int(card[1] - '0')]++;
            }
        }
	}
	for (int i = 0;i < 4;i++) {
        for (int j = 1;j <= 13;j++) {
            if (!all[i][j]) {
                ans++;
            }
        }
	}
	cout << ans;
	return 0;
}
