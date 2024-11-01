#include<bits/stdc++.h>
using namespace std;

int n;
const int N = 1e5+10;
int r[N];
int vis[N];
int maxr;

bool cmp(int x, int y) {return x > y;}

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> r[i];
    sort(r+1, r+n+1, cmp);
    for (int i = 1; i <= n; i++) {
        vis[r[i]]++;
        maxr = max(maxr, r[i]);
    }
    sort(vis+1, vis+maxr+1, cmp);
    cout << vis[1];
    return 0;
}
