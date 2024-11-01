#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Card {
    int x;
    int y;
};

bool cmp(Card a, Card b) {
    return a.y > b.y;
}

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin >> n;
    vector<Card> v(n);
    char a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a == 'D') {
            v[i].x = 0;
        } else if (a == 'C') {
            v[i].x = 1;
        } else if (a == 'H') {
            v[i].x = 2;
        } else if (a == 'S') {
            v[i].x = 3;
        }
        if (b == 'A') {
            v[i].y = 1;
        } else if(b == 'T') {
            v[i].y = 10;
        } else if (b == 'J') {
            v[i].y = 11;
        } else if (b == 'Q') {
            v[i].y = 12;
        } else if (b == 'K') {
            v[i].y = 13;
        } else {
            v[i].y = b - '0';
        }
    }
    sort(v.begin(), v.end(), cmp);
    int i = 0;
    int cnt = 0;
    while (i < n) {
        Card tmp;
        tmp.x = v[i].x;
        tmp.y = v[i].y;
        while (i < n && v[i].x == tmp.x && v[i].y == tmp.y) {
            i++;
        }
        cnt++;
    }
    cout << 52 - cnt << endl;
    return 0;
}