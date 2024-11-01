#include<iostream>
using namespace std;
int n, ans;
bool po[13][4];
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int shape, val;
        if (s[1] == 'A') {
            val = 0;
        }
        else if (s[1] >= '2' && s[1] <= '9') {
            val = s[1] - '0' - 1;
        }
        else if (s[1] == 'T') {
            val = 9;
        }
        else if (s[1] == 'J') {
            val = 10;
        }
        else if (s[1] == 'Q') {
            val = 11;
        }
        else {
            val = 12;
        }
        switch (s[0]) {
            case 'D': {
                shape = 0;
                break;
            }
            case 'C': {
                shape = 1;
                break;
            }
            case 'H': {
                shape = 2;
                break;
            }
            default: {
                shape = 3;
            }
        }
        po[val][shape] = true;
    }
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            if (po[i][j] == false) {
                ans++;
            }
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}