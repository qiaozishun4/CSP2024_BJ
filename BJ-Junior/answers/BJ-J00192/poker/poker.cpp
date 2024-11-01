#include <iostream>
#define maxn 1000
using namespace std;
int main() {
    freopen("poker1.in", "r", stdin);
    freopen("poker1.out", "w", stdout);
    freopen("poker2.in", "r", stdin);
    freopen("poker2.out", "w", stdout);
    freopen("poker3.in", "r", stdin);
    freopen("poker3.out", "w", stdout);
    int n;
    int sum = 52;
    string s;
    char a[maxn];
    char b[maxn];
    bool mark = true;
    char aw[4] = {'D', 'C', 'H', 'S'};
    char bw[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        a[i] = s[0];
        b[i] = s[1];
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            for (int k = 0; k < n; k++) {
                if (aw[i] == a[k] && bw[j] == b[k]) {
                    sum--;
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}