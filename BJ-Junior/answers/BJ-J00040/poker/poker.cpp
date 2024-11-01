#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
struct Node {
    bool flagD, flagC, flagH, flagS;
}arr[MAX];
string str;
int n, ans = 0;
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> str;
        int cnt = 0;
        if (str[1] >= '2' && str[1] <= '9') cnt = str[1] - '0';
        else  {
            if (str[1] == 'A') cnt = 1;
            else if (str[1] == 'T') cnt = 10;
            else if (str[1] == 'J') cnt = 11;
            else if (str[1] == 'Q') cnt = 12;
            else cnt = 13;
        }
        if (str[0] == 'D') arr[cnt].flagD = true;
        else if (str[0] == 'C') arr[cnt].flagC = true;
        else if (str[0] == 'H') arr[cnt].flagH = true;
        else arr[cnt].flagS = true;
    }
    for (int i = 1; i <= 13; i++) {
        if (arr[i].flagD == false) ans += 1;
        if (arr[i].flagC == false) ans += 1;
        if (arr[i].flagH == false) ans += 1;
        if (arr[i].flagS == false) ans += 1;
    }
    cout << ans;
    fclose(stdin), fclose(stdout);
    return 0;
}