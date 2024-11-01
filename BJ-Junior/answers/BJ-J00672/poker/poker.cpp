#include<bits/stdc++.h>
using namespace std;

const int N = 53;

struct Node{
    string s;
}p[N];
int n;
int cnt;

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    scanf("%d", &n);
    cnt = n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].s;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (j == i) continue;
            if (p[i].s == p[j].s) cnt--;
        }
    }
    cout << 52 - cnt;
    return 0;
}
