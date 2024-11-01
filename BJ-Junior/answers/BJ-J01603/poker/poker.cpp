#include<iostream>
using namespace std;
int fl[53], n, cnt;
char a[2];
int yuchuli(char x, char y) {
    int res = 0;
    if (x == 'D')
        res = 13;
    if (x == 'S')
        res = 26;
    if (x == 'C')
        res = 39;
    if (y == 'A')
        res++;
    if (y == 'T')
        res+=10;
    if (y == 'J')
        res+=11;
    if (y == 'Q')
        res+=12;
    if (y == 'K')
        res+=13;
    if (y >= '2' && y <= '9')
        res+=y-'0';
    return res;
}
int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        fl[yuchuli(a[0], a[1])] = 1;
    }
    for (int i = 1; i <= 52; i++)
        if (fl[i] == 0)
            cnt++;
    cout << cnt;
    return 0;
}
