#include<bits/stdc++.h>
using namespace std;

string s;
int n;
int c[100][100];
int cnt;

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        if (c[int(s[0])][int(s[1])] != 1) {
            cnt++;
        }
        c[int(s[0])][int(s[1])] = 1;
    }
    cout << 52 - cnt <<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
