#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int a[100];


int main() {

    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i ++) {
        string z;
        cin >> z;
        if (z[0] == 'D') {
            if (z[1] == 'A') a[1] ++;
            else if (z[1] == 'T') a[10] ++;
            else if (z[1] == 'J') a[11] ++;
            else if (z[1] == 'Q') a[12] ++;
            else if (z[1] == 'K') a[13] ++;
            else a[z[1] - '0'] ++;

        }
        if (z[0] == 'C') {
            if (z[1] == 'A') a[14] ++;
            else if (z[1] == 'T') a[23] ++;
            else if (z[1] == 'J') a[24] ++;
            else if (z[1] == 'Q') a[25] ++;
            else if (z[1] == 'K') a[26] ++;
            else a[z[1] - '0' + 13] ++;

        }
        if (z[0] == 'H') {
            if (z[1] == 'A') a[27] ++;
            else if (z[1] == 'T') a[36] ++;
            else if (z[1] == 'J') a[37] ++;
            else if (z[1] == 'Q') a[38] ++;
            else if (z[1] == 'K') a[39] ++;
            else a[z[1] - '0' + 26] ++;

        }
        if (z[0] == 'S') {
            if (z[1] == 'A') a[40] ++;
            else if (z[1] == 'T') a[49] ++;
            else if (z[1] == 'J') a[50] ++;
            else if (z[1] == 'Q') a[51] ++;
            else if (z[1] == 'K') a[52] ++;
            else a[z[1] - '0' + 39] ++;

        }
    }
    for (int i = 1; i <= 52; i ++) {
        if (a[i] <= 0) cnt ++;
    }
    cout << cnt;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
