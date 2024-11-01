#include<iostream>
using namespace std;
int p[10][20];
int main() {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        char a,b;
        a = s[0];
        b = s[1];
        if (a == 'D') {
            if (b == 'A') {
                p[1][1]++;
            } else if (b >= '2' && b <= '9') {
                p[1][b-'0']++;
            } else if (b == 'T') {
                p[1][10]++;
            } else if (b == 'J') {
                p[1][11]++;
            } else if (b == 'Q') {
                p[1][12]++;
            } else if (b == 'K') {
                p[1][13]++;
            }
        } else if (a == 'C') {
            if (b == 'A') {
                p[2][1]++;
            } else if (b >= '2' && b <= '9') {
                p[2][b-'0']++;
            } else if (b == 'T') {
                p[2][10]++;
            } else if (b == 'J') {
                p[2][11]++;
            } else if (b == 'Q') {
                p[2][12]++;
            } else if (b == 'K') {
                p[2][13]++;
            }
        } else if (a == 'H') {
            if (b == 'A') {
                p[3][1]++;
            } else if (b >= '2' && b <= '9') {
                p[3][b-'0']++;
            } else if (b == 'T') {
                p[3][10]++;
            } else if (b == 'J') {
                p[3][11]++;
            } else if (b == 'Q') {
                p[3][12]++;
            } else if (b == 'K') {
                p[3][13]++;
            }
        } else if (a == 'S') {
            if (b == 'A') {
                p[4][1]++;
            } else if (b >= '2' && b <= '9') {
                p[4][b-'0']++;
            } else if (b == 'T') {
                p[4][10]++;
            } else if (b == 'J') {
                p[4][11]++;
            } else if (b == 'Q') {
                p[4][12]++;
            } else if (b == 'K') {
                p[4][13]++;
            }
        }
    }
    int c = 0;
    for (int i=1;i<=4;i++) {
        for (int j=1;j<=13;j++) {
            if (p[i][j] == 0) {
                c++;
            }
        }
    }
    cout << c;
    return 0;
}
