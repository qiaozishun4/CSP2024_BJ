#include <iostream>
#include <cstdio>

using namespace std;

int n;
bool poker[100];
int addsingle(char b) {
   if (b == 'A')
        return 0;
   if (b == 'T')
        return 9;
    if (b == 'J')
        return 10;
    if (b == 'Q')
        return 11;
    if (b == 'K')
        return 12;
    return b - '1';
}
void add(char a, char b) {
    int ans = addsingle(b);
    if (a == 'D') {
        poker[ans] = true;
    } else if (a == 'C') {
        poker[ans + 13] = true;
    } else if (a == 'H') {
        poker[ans + 26] = true;
    } else if (a == 'S') {
        poker[ans + 39] = true;
    }
}
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char a, b;
        cin >> a >> b;
        add(a, b);
    }
    int ans = 0;
    for (int i = 0; i < 52; i++) {
        if (!poker[i]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
