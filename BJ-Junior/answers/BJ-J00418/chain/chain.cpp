#include <iostream>
using namespace std;

int T;
int n, k, q, r, c;
int l[100005], sl[100005];
int s[20000005], cur;
bool flag;

//the first one of next round
int next(int p) {
    return (p/n+1)*n+1; }

//the last number index of one
int last(int p) {
    return sl[(p-1)%n+1]+sl[n]*((p-1)/n); }

void dfs(int p, int start, int lastp) {
    if (lastp <= r*n && lastp > (r-1)*n) {
        if (start == c)
            flag = 1;
        return;
    }
    if (lastp%n == p%n) {
        dfs(p+1, start, lastp);
        return;
    }
    if (next(p) - next(lastp) >= 2*n)
        return;
    for (int i = last(p-1)+1; i <= last(p); i++)
        if (s[i] == start)
            for (int j = i+1; j <= min(i+k-1, last(p)); j++)
                dfs(next(p), s[j], p);
    dfs(p+1, start, lastp);
}

int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    cin >> T;
    while (T--) {
        cur = 0;
        cin >> n >> k >> q;
        for (int i = 1; i <= n; i++) {
            cin >> l[i];
            sl[i] = sl[i-1] + l[i];
            for (int j = 1; j <= l[i]; j++)
                cin >> s[++cur];
        }
        for (int i = 1; i <= 100; i++)
            for (int j = 1; j <= cur; j++)
                s[i*cur+j] = s[j];
        for (int i = 1; i <= q; i++) {
            flag = 0;
            cin >> r >> c;
            dfs(1, 1, 0);
            cout << flag << endl;
        }
    }
    return 0;
}